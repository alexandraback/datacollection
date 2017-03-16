#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;
map<pair<int,int>,string> d;
map<pair<int,int>,int> c;
class rock{
    public:
        int x,y;
        int step;
};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
string dz[]={"N","E","S","W"};
inline int abs( int x) {
    if (x >0) return x; else return -x;
}
int main() {
    queue<rock> q;
    d[make_pair(0,0)] = "";
    c[make_pair(0,0)] = 1;
    rock w;
    w.x=0;
    w.y=0;
    w.step=1;
    q.push(w);
    while(!q.empty()) {
        rock top = q.front();
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = top.x+dx[k]*top.step;
            int ny = top.y+dy[k]*top.step;
            if (nx == 0 && ny == 0) {
            } else {
                if (abs(nx) <= 500 && abs(ny) <= 500) {
                    if (c[make_pair(nx,ny)] == 0) {
                        d[make_pair(nx,ny)] = d[make_pair(top.x,top.y)]+dz[k];
                        c[make_pair(nx,ny)] = 1;
                        rock ff;
                        ff.x = nx;
                        ff.y = ny;
                        ff.step = top.step+1;
                        q.push(ff);
                    }
                }
            }
        }
    }
    int t;
    scanf("%d",&t);
    for (int tc=1; tc<=t; tc++) {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("Case #%d: %s\n",tc,d[make_pair(x,y)].c_str());
    }

    return 0;
}
