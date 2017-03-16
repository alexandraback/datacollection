#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define GABRIEL "GABRIEL"
#define RICHARD "RICHARD"
using namespace std;

struct point{
    int x,y;
    point();
    point(int x,int y);
    void translate(int x,int y);
};

struct polyomino {
    vector<point> points;
    void reflect_h();
    void reflect_v();
    void rotate();
    void normalize();
    void clear();
    vector<polyomino> generate();
    void print();
    int size();
    int get_min_x();
    int get_min_y();
    int get_max_x();
    int get_max_y();
};

vector<polyomino> ptemplate[7];

void generate_template();

vector<int> separate_region(const int r,const int c,polyomino p,int offset_i,int offset_j);
bool is_valid(const int r,const int c,polyomino p,int offset_i,int offset_j);
bool can_solve(int x,int r,int c,polyomino p);

void floodfill(int now_i,int now_j,int r,int c,const vector<vector<char> > &map,vector<vector<bool> > &visited,int &counter);

void solve();

void debug_polyomino();

int main(){
    generate_template();
    solve();
}

void debug_polyomino(){
    for(int i = 1; i < 5; i++){
        printf("Polyonimo #%d\n",i);
        for(int j = 0; j < (int) ptemplate[i].size(); j++){
            ptemplate[i][j].print();
        }
    }
}
void solve() {
    
    int TC;
    scanf("%d",&TC);
    int x,r,c;
    for(int tc = 0; tc < TC; ++tc){
        scanf("%d %d %d",&x,&r,&c);
        bool ans = false;
        //generate semua polyomino yang mungkin
        for(int pt = 0; pt < (int) ptemplate[x].size(); pt++){
            bool unsolved_configuration = true;
            vector<polyomino> ps = ptemplate[x][pt].generate();
            for(int current_po = 0; current_po < (int) ps.size(); current_po++){
                if (can_solve(x,r,c,ps[current_po])){
                    unsolved_configuration = false;
                    break;
                }
            } 
            //ada yang gak bisa, horey
            if (unsolved_configuration){
                ans = true;
            }
        }
        printf("Case #%d: %s\n",tc + 1,(ans)?(RICHARD):(GABRIEL));
    }
}

bool can_solve(int x,int r,int c,polyomino p){
    bool retval = false;
    for(int oi = 0; oi <= r; oi++)
    for(int oj = 0; oj <= c; oj++){
        if (is_valid(r,c,p,oi,oj)){
            bool oke = true;
            vector<int> regions = separate_region(r,c,p,oi,oj);
            
            for(int i = 0; i < (int) regions.size(); i++){
                if (regions[i] % x != 0){
                    oke = false;
                }
            }
            if (oke){
                retval = true;
            }
        }
    }
    return retval;
}

void polyomino::rotate(){
    for(int i = 0; i < size(); i++){
        point tmp = points[i];
        points[i].x = tmp.y;
        points[i].y = -tmp.x;
    }
    normalize();
}

void polyomino::reflect_h(){
    for(int i = 0; i < size(); i++){
        points[i].y *= -1;
    }
    normalize();
}

void polyomino::reflect_v(){
    for(int i = 0; i < size(); i++){
        points[i].x *= -1;
    }
    normalize();
}

void polyomino::normalize(){
    int min_x = 10000,min_y = 1000;
    int tx,ty;
    for(int i = 0; i < size(); i++){
        min_x = min(min_x,points[i].x);
        min_y = min(min_y,points[i].y);
    }
    if (min_x < 0) tx = -min_x; else tx = 0;
    if (min_y < 0) ty = -min_y; else ty = 0;

    for(int i = 0; i < size(); i++)
        points[i].translate(tx,ty);

    min_x = 1000,min_y = 1000;
    for(int i = 0; i < size(); i++){
        min_x = min(min_x,points[i].x);
        min_y = min(min_y,points[i].y);
    }
    if (min_x > 0) tx = -min_x; else tx = 0;
    if (min_y > 0) ty = -min_y; else ty = 0;

    for(int i = 0; i < size(); i++)
        points[i].translate(tx,ty);
}

point::point(){ }

point::point(int _x,int _y){
    x = _x; y = _y;
}
int polyomino::size(){
    return (int) points.size();
}

void point::translate(int _x,int _y){
    x += _x;
    y += _y;
}

void polyomino::clear(){
    points.clear();
}

vector<polyomino> polyomino::generate(){
    vector<polyomino> ret;
    polyomino p = *this;
    
    p = *this;
    int i = 0;
    do {
        ret.push_back(p);
        p.rotate(); i++;
    } while (i < 4);
    p = *this;
    p.reflect_v();
    ret.push_back(p);
    p = *this;
    p.reflect_h();
    ret.push_back(p);
    return ret;
}


bool is_valid(const int r,const int c,polyomino p,int offset_i,int offset_j){
    return(
    (0 <= (p.get_min_x() + offset_i)) && 
    (0 <= (p.get_min_y() + offset_j)) &&
    (p.get_max_x() + offset_i < r) &&
    (p.get_max_y() + offset_j < c)
    );
}

vector<int> separate_region(const int r,const int c,polyomino p,int offset_i,int offset_j){
    vector<vector<char> > map;
    vector<vector<bool> > visited;
    vector<int> retval;

    for(int i = 0; i < r; i++){
        vector<char> arr;
        for(int j = 0; j < c; j++){
            arr.push_back('.');
        }
        map.push_back(arr);
    }

    for(int i = 0; i < r; i++){
        vector<bool> arr;
        for(int j = 0; j < c; j++){
            arr.push_back(0);
        }
        visited.push_back(arr);
    }
    for(int ctr = 0; ctr < p.size(); ctr++){
        map[p.points[ctr].x + offset_i][p.points[ctr].y + offset_j] = '*';
    }

    //print map
    
    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j ++){
    //         printf("%c",map[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if (!visited[i][j] && map[i][j] == '.'){
                int counter = 1;
                visited[i][j] = 1;
                floodfill(i,j,r,c,map,visited,counter);
                retval.push_back(counter);
            }
        }
    }
    // printf("regions: ");
    // for(int i = 0; i < (int) retval.size(); i++){
    //     printf("%d ",retval[i]);
    // }
    // printf("\n\n");
    return retval;
}

void floodfill(int now_i,int now_j,int r,int c,const vector<vector<char> > &map,vector<vector<bool> > &visited,int &counter){
    static int di[] = {-1, 1, 0, 0};
    static int dj[] = { 0, 0,-1, 1};

    for(int i = 0; i < 4; i++){
        int next_i = now_i + di[i];
        int next_j = now_j + dj[i];
        if (0 <= next_i && next_i < r && 0 <= next_j && next_j < c){
            if (!visited[next_i][next_j] && map[next_i][next_j]=='.'){
                visited[next_i][next_j] = 1;
                counter += 1;
                floodfill(next_i,next_j,r,c,map,visited,counter);
            }
        }
        
    }
}

int polyomino::get_min_x(){
    int ret = points[0].x;
    for(int i = 0; i < size(); i++){
        ret = min(ret,points[i].x);
    }
    return ret;
}

int polyomino::get_max_x(){
    int ret = points[0].x;
    for(int i = 0; i < size(); i++){
        ret = max(ret,points[i].x);
    }
    return ret;
}

int polyomino::get_min_y(){
    int ret = points[0].y;
    for(int i = 0; i < size(); i++){
        ret = min(ret,points[i].y);
    }
    return ret;
}

int polyomino::get_max_y(){
    int ret = points[0].y;
    for(int i = 0; i < size(); i++){
        ret = max(ret,points[i].y);
    }
    return ret;
}

void generate_template(){
    polyomino p;
    //1
    p.clear();
    p.points.push_back(point(0,0));
    p.normalize();
    ptemplate[1].push_back(p);
    //2
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.normalize();
    ptemplate[2].push_back(p);
    //3
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.normalize();
    ptemplate[3].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(1,0));
    p.normalize();
    ptemplate[3].push_back(p);
    //4
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.points.push_back(point(0,3));
    p.normalize();
    ptemplate[4].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(1,0));
    p.points.push_back(point(1,1));
    p.normalize();
    ptemplate[4].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.points.push_back(point(1,0));
    p.normalize();
    ptemplate[4].push_back(p);
    p.clear();
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.points.push_back(point(1,1));
    p.points.push_back(point(1,0));
    p.normalize();
    ptemplate[4].push_back(p);
    p.clear();
    p.points.push_back(point(0,1));
    p.points.push_back(point(1,1));
    p.points.push_back(point(2,1));
    p.points.push_back(point(1,0));
    p.normalize();
    ptemplate[4].push_back(p);
    //5
    p.clear();
    p.points.push_back(point(0,1));
    p.points.push_back(point(1,0));
    p.points.push_back(point(1,1));
    p.points.push_back(point(1,2));
    p.points.push_back(point(2,2));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.points.push_back(point(0,3));
    p.points.push_back(point(0,4));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.points.push_back(point(0,3));
    p.points.push_back(point(1,0));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(1,1));
    p.points.push_back(point(1,2));
    p.points.push_back(point(1,3));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.points.push_back(point(1,1));
    p.points.push_back(point(1,2));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,2));
    p.points.push_back(point(1,2));
    p.points.push_back(point(2,2));
    p.points.push_back(point(1,1));
    p.points.push_back(point(1,0));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(2,1));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,2));
    p.points.push_back(point(0,1));
    p.points.push_back(point(1,1));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(1,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(2,1));
    p.points.push_back(point(1,2));
    p.points.push_back(point(1,1));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(0,1));
    p.points.push_back(point(0,2));
    p.points.push_back(point(1,2));
    p.points.push_back(point(0,3));
    p.normalize();
    ptemplate[5].push_back(p);

    p.clear();
    p.points.push_back(point(0,2));
    p.points.push_back(point(1,2));
    p.points.push_back(point(1,1));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.normalize();
    ptemplate[5].push_back(p);

    //6
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(0,1));
    p.normalize();
    ptemplate[6].push_back(p);

    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(1,1));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();

    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(2,1));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
    p.clear();
    p.points.push_back(point(0,0));
    p.points.push_back(point(1,0));
    p.points.push_back(point(2,0));
    p.points.push_back(point(3,0));
    p.points.push_back(point(4,0));
    p.points.push_back(point(5,0));
    p.normalize();
    ptemplate[6].push_back(p);
}

void polyomino::print(){
    int max_x = 0;
    int max_y = 0;
    for(int i = 0; i < size(); i++){
        max_x = max(max_x,points[i].x);
        max_y = max(max_y,points[i].y);
    }
    char mat[10][10];
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++){
            mat[i][j] = '.';
        }
    for(int i = 0; i < size(); i++){
        mat[points[i].x][points[i].y] = '*';
    }
    for(int i = 0; i <= max_x; i++){
        for(int j = 0; j <= max_y; j++){
            printf("%c",mat[i][j]);
        }
        printf(" \n");
    }
    printf("\n");
}

