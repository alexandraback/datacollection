#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
int T,R,C,M,vis[55][2555];
char G[55][55];
int main()
{
//    freopen("C.in","r",stdin);
//    freopen("C.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;++t){
        cin>>R>>C>>M;
//        cerr<<"case"<<t<<":"<<R<<' '<<C<<' '<<M<<endl;
        printf("Case #%d:\n",t);
        memset(G,'*',sizeof(G));
        memset(vis,0,sizeof(vis));
        int l=R*C-M;
        if(R==1){
            for(int i=1;i<l;++i)
                G[0][i]='.';
            G[0][0]='c';
            G[0][C]=0;
            puts(G[0]);
            continue;
        }
        if(C==1){
            puts("c");
            for(int i=1;i<l;++i)
                puts(".");
            for(int i=0;i<M;++i)
                puts("*");
            continue;
        }
        if(l==1){
            G[0][0]='c';
            for(int i=0;i<R;++i){
                G[i][C]=0;
                puts(G[i]);
            }
            continue;
        }
        int ma=min(C,l/2);
        l-=ma*2;
        if(l==1)--ma,++++l;
        if(ma<2){
            puts("Impossible");
            continue;
        }
        for(int i=0;i<ma;++i)
            G[0][i]=G[1][i]='.';
        for(int i=2;i<R;++i){
            int mma=min(ma,l);
            l-=mma;
            if(l==1)--mma,++l;
            if(mma<2)break;
            for(int j=0;j<mma;++j)
                G[i][j]='.';
            ma=mma;
        }
        if(l){
            puts("Impossible");
            continue;
        }
        G[0][0]='c';
        for(int i=0;i<R;++i){
            G[i][C]=0;
            puts(G[i]);
        }
    }
    return 0;
}
