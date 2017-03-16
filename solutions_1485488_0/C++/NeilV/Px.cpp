/*
ID: neil
PROG: untitled
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <string.h>
#include <list>
#include <algorithm>
#include <set>

#define for0(i,n) for (int i=0; i<n; i++)
#define forin(i,n) for (int i=0; i<=n; i++)
#define forr(i,n) for (int i=n-1; i>=0; i--)
#define fori(i,a,b) for (int i=a; i<=b; i++)
#define iter(v,x) for(vector<x>::iterator it=v.begin(); it!=v.end(); it++)
#define pb(x) push_back(x)
#define vec(x) vector<x>
#define ms(a,z) memset(a,z,sizeof(a))
#define sort(a) sort(a.begin(),a.end())
#define nl() cout<<"\n"
#define print(x) cout<<x<<" "
#define printv(v) for(int _=0; _<v.size(); _++) cout<<v[_]<<" "; cout<<"\n";
#define printa(a,s) for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";
#define print2D(a,m,n) for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";}
#define sum(a,l,s) int s=0; for (int _=0; _<l; _++) s+=a[_];

using namespace std;

int INF = 999999999;
double EPSILON = 0.00000001;
int ceil[10][10];
int floor[10][10];
int height,h,w;
double time[10][10];
bool visited[10][10];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int sint(string s){
    int num=0;
    istringstream myStream(s);
    (myStream>>num);
    return num;
}

string str (int num){
    ostringstream oss;
    oss<< num;
    return oss.str();
}

vector <string> split(string s)
{
    vector <string> tokens;
    stringstream os(s);
    string temp;
    while (os >> temp)
    {
        tokens.push_back(temp);
    }
    return tokens;
}

int maxv(vector<int> v){
    int m = -9999999;
    for0(i,v.size()) m = max(m,v[i]);
    return m;
}

int minv(vector<int> v){
    int m = 9999999;
    for0(i,v.size()) m = min(m,v[i]);
    return m;
}

struct Node
{
    int y,x;
    double t;
};
bool operator<(const Node& self, const Node& other)
{
    return self.t > other.t;
}

void bfs()
{
    queue<pair<int,int> > q;
    pair<int,int> start; start.first = 0; start.second = 0;
    q.push(start);
    //ms(time,-1);
    for0(y,h){
        for0(x,w) time[y][x] = -1;
    }
    time[0][0] = 0;

    while (not q.empty()){
        pair<int,int> top =q.front();
        q.pop();
        int x1 = top.first;
        int y1 = top.second;
        //cout<<x1<<" "<<y1<<"\n";
        int f1,c1,f2,c2;
        f1 = max(floor[y1][x1],height);
        c1 = ceil[y1][x1];

        for0(i,4){
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];
            if (x2 < 0 or x2 >= w or y2 < 0 or y2 >= h) continue;
            if (time[y2][x2] != -1) continue;
            //cout<<x2<<" "<<y2<<"\n";
            f2 = max(floor[y2][x2],height);
            c2 = ceil[y2][x2];
            int c = min(c1,c2);
            int f = max(f1,f2);

            if (c-f >= 50){
                if (height-floor[y1][x1] >= 20) time[y2][x2] = time[y1][x1]+1;
                else time[y2][x2] = time[y1][x1]+10;
                pair<int,int> next; next.first = x2; next.second = y2;
                q.push(next);
            }
        }
    }
}

double dijkstra(int startx, int starty)
{
    ms(visited,false);
    priority_queue<Node> heap;
    Node start; start.x = startx; start.y = starty; start.t = 0;
    heap.push(start);

    while (not heap.empty()){
        Node top = heap.top(); heap.pop();
        int x1 = top.x;
        int y1 = top.y;
        //cout<<x1<<" "<<y1<<" "<<top.t<<"\n";
        if (y1 == h-1 and x1 == w-1) return top.t;
        if (visited[y1][x1]) continue;
        visited[y1][x1] = true;

        double f1,c1,f2,c2;
        f1 = floor[y1][x1];
        if (height-top.t*10 < f1) f1 = height-top.t*10;
        c1 = ceil[y1][x1];

        for0(i,4){
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];
            if (x2 < 0 or x2 >= w or y2 < 0 or y2 >= h) continue;

            f2 = floor[y2][x2];
            double hw = height-top.t*10;
            //if (height-top.t*10 > f2) f2 = height-top.t*10;
            c2 = ceil[y2][x2];

            double c,f,t;
            c = c1;
            if (c2 < c) c = c2;
            f = f1;
            if (f2 > f) f = f2;
            if (c-f < 50) continue;

            if (c - hw>= 50) t=top.t;
            else t=top.t+ (hw-(c-50))/10.0;

            //if (c-f >= 50){
            //cout<<c<<" "<<hw<<"\n";
            //cout<<x1<<" "<<y1<<"    "<<x2<<" "<<y2<<"\n";
            if (height-t*10-floor[y1][x1] >= 20) t += 1;
            else t += 10;
            Node next; next.x = x2; next.y = y2; next.t = t;
            heap.push(next);

        }
    }
    return INF;
}

int main()
{
    ifstream in("P2.txt");
    //ofstream out("P2.out");
    FILE * out = fopen("P2.out","w");
    int cases;
    in >> cases;

    for0(casen,cases){
        in >> height >> h >> w;
        for0(y,h){
            for0(x,w){
                in >> ceil[y][x];
            }
        }
        for0(y,h){
            for0(x,w){
                in >> floor[y][x];
            }
        }
        bfs();
        //print2D(time,h,w); nl();

        double best = INF;
        for0(y,h){
            for0(x,h){
                if (time[y][x] != -1){
                    double t = dijkstra(x,y);
                    if (t < best) best=t;
                }
            }
        }
        //print(best);
        //nl(); nl();
        //out >> "Case #"
        fprintf(out,"Case #%d: %.9f\n",casen+1,best);
    }
    return 0;
}
