#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<string>
#include<bitset>
#include<set>
#include<algorithm>

#define FOR(a,b) for(int a=0;a<b;a++)
#define FORR(a,b) for(int a=b-1;a>=0;a--)
#define FOR2(a,b,c) for(int a=b;a<c;a++)
#define FORR2(a,b,c) for(int a=c-1;a>=b;a--)
#define EACH(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

#define VI vector<int>
#define VVI vector< vector<int> >
#define PII pair<int,int>
#define VS vector<string>

#define MAXN  1000
#define BSIZE 1010

using namespace::std;

typedef long long lint;

int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char dir[4] = {'E','N','W','S'};
int ox,oy;

struct node{
    int x,y,s;
    char d;
    int h;
    node(){}
    node(int x,int y,int s,int d){
        this->x = x; 
        this->y = y;
        this->s = s;
        this->d = d;
        this->h = abs(ox-x)+abs(oy-y);
    }
    bool operator<(const node& other) const{
        int g1 = this->s+this->h;
        int g2 = other.s+other.h;
        if(g1==g2) return this->s>other.s;
        return g1>g2;
    }
    void path(map< PII, node > &visit){
        if(this->x==0&&this->y==0) return;
        int fx = this->x+s*move[this->d][0]*-1,
            fy = this->y+s*move[this->d][1]*-1;
        visit[make_pair(fx,fy)].path(visit);
        printf("%c",dir[this->d]);
    }
};

map< PII, node > visit;

inline void a_star(){
    visit.clear();
    priority_queue<node> q;

    node x = node(0,0,0,0); 
    q.push(x);
    visit[make_pair(0,0)] = x;

    while(true){
        x = q.top();
        q.pop();
        if(x.x==ox && x.y==oy){
            x.path(visit);
            return;
        }
        FOR(i,4){
            int ns = x.s+1,
                nx = x.x+ns*move[i][0],
                ny = x.y+ns*move[i][1];
            if(visit.count(make_pair(nx,ny))>0) continue;
            node y = node(nx,ny,ns,i);
            q.push(y);
            visit[make_pair(nx,ny)] = y;
        }
    }
}

int main(){
    int tot_cases;
    scanf("%d",&tot_cases);
    for(int case_num=1;case_num<=tot_cases;case_num++){

        scanf("%d %d",&ox,&oy);
        printf("Case #%d: ",case_num);
        a_star();
        printf("\n");
    }
    return 0;
}
