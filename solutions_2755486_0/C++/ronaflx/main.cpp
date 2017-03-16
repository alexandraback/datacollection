#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

const int N = 676060+3;

int cas;
int n;
const int bas = 1000;

struct T{
    int bg,ed;
    int  s;
    T(){}
    T(int tbg, int ted, int ts):bg(tbg+bas), ed(ted+bas), s(ts){}
};

vector<T> adj[N];


int h[N];

void input()
{
    for(int i = 0; i < N; ++i) adj[i].clear();
    scanf("%d",&n);
    int d, cnt,w,e,s, det_d, det_s, det_p;
    for(int i = 0; i < n; ++i){
        cin >> d >> cnt >> w >> e;
        cin >> s >> det_d >> det_p >> det_s;
        for(int j = 0; j < cnt; ++j){
            adj[d].push_back(T(w,e,s));
            d += det_d;
            w += det_p;
            e += det_p;
            s += det_s;
        }
    }
}


int Ans(){
    memset(h, 0, sizeof(h));
    int res = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < (int)adj[i].size(); ++j){
            int w = adj[i][j].bg;
            int e = adj[i][j].ed;
            int s = adj[i][j].s;
            bool ok = true;
            for(int k = w; k < e; ++k){
                if(h[k] < s) {
                    ok = false;
                    break;
                }
            }
            if(!ok) ++res;
        }
        for(int j = 0; j < (int)adj[i].size(); ++j){
            int w = adj[i][j].bg;
            int e = adj[i][j].ed;
            int s = adj[i][j].s;
            for(int k = w; k < e; ++k){
                if(h[k] < s) {
                    h[k] = s;
                }
            }
        }
    }
    return res;
}
int main(){
    int cas, tcas=0;
    freopen("in","r",stdin);
    freopen("out","w", stdout);
    for(cin >> cas; cas; --cas){
        input();
        printf("Case #%d: %d\n",++tcas,Ans());
    }
}
