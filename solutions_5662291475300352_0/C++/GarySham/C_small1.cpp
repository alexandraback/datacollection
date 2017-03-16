#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long
#define eps (1e-8)
#define fgt(x,y) (((x)-(y)) > (eps))
#define feq(x,y) (fabs((x)-(y)) < eps)

struct node{
    int d,s;

    node(){}
    node(int d,int s):d(d),s(s){}

    bool operator<(const node &x)const{
        if (d == x.d) return s > x.s;
        else return d < x.d;
    }
} h[100];

int main(){
    int T; scanf("%d",&T);
    FOE(t,1,T){
        int N; scanf("%d",&N);

        int num = 0;
        FOR(i,0,N){
            int d,c,m;
            scanf("%d%d%d",&d,&c,&m);
            FOR(j,0,c) h[num++] = node(d,m+j);
        }
        sort(h,h+num);
        //FOR(i,0,num) printf("%d %d!\n",h[i].d,h[i].s);

        if (num < 2) printf("Case #%d: 0\n",t);
        else if (h[0].s == h[1].s) printf("Case #%d: 0\n",t);
        else {
            if (h[0].s < h[1].s){
                double tt = ((360.0 - h[1].d)/360.0) * h[1].s;
                double ct = (360.0 + (h[1].d - h[0].d))/360.0 * h[0].s;
                if (fgt(tt,ct) || feq(tt,ct))
                    printf("Case #%d: 1\n",t);
                else
                    printf("Case #%d: 0\n",t);
            }
            else{
                double tt = ((360.0 - h[0].d)/360.0) * h[0].s;
                double ct = (360.0 - (h[1].d - h[0].d))/360.0 * h[1].s;
                if (fgt(ct,tt) || feq(tt,ct))
                    printf("Case #%d: 1\n",t);
                else
                    printf("Case #%d: 0\n",t);
            }
        }
    }
    return 0;
}
