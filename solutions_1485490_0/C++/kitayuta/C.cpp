// {{{
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ALL(A)		(A).begin(),(A).end()
#define DUMP(A)    cout<<#A<<"="<<(A)<< endl
#define SIZE(A)    (int)((A).size())
#define MP  make_pair
#define PB  push_back
using namespace std;
typedef long long ll;

int vx[]={1,0,-1,0},vy[]={0,1,0,-1};
// }}}

ll numas[100],valas[100],numbs[100],valbs[100];
ll sums[101][101];
int main(){
    int T;
    scanf("%d",&T);
    for(int ix=0;ix<T;ix++){
        printf("Case #%d: ",ix+1);
        int N,M;
        scanf("%d%d",&N,&M);
        int nat=0,mat=0;
        ll n,v;
        scanf("%lld%lld",&numas[0],&valas[0]);
        for(int i=1;i<N;i++){
            scanf("%lld%lld",&n,&v);
            if(valas[nat]==v) numas[nat]+=n;
            else{
                nat++;
                numas[nat]=n;
                valas[nat]=v;
            }
        }
        N=nat+1;
        scanf("%lld%lld",&numbs[0],&valbs[0]);
        for(int i=1;i<M;i++){
            scanf("%lld%lld",&n,&v);
            if(valbs[mat]==v) numbs[mat]+=n;
            else{
                mat++;
                numbs[mat]=n;
                valbs[mat]=v;
            }
        }
        M=mat+1;
//        printf("%d, %d\n",N,M);
//        for(int i=0;i<N;i++){
//            printf("(%lld,%lld) ",valas[i],numas[i]);
//        }
//        printf("\n");
//        for(int i=0;i<M;i++){
//            printf("(%lld,%lld) ",valbs[i],numbs[i]);
//        }
//        printf("\n");
        for(int i=1;i<=100;i++){
            sums[i][0]=0;
            for(int j=1;j<=M;j++){
                sums[i][j]=sums[i][j-1];
                if(valbs[j-1]==i) sums[i][j]+=numbs[j-1];
            }
        }
        if(N==1){
            printf("%lld\n",min(numas[0],sums[valas[0]][M]));
        }else if(N==2){
            ll ma=0;
            for(int i=0;i<=M;i++){
                ma=max(ma,min(numas[0],sums[valas[0]][i])+min(numas[1],sums[valas[1]][M]-sums[valas[1]][i]));
            }
            printf("%lld\n",ma);
        }else if(N==3){
            ll ma=0;
            for(int i=0;i<=M;i++){
                for(int j=i;j<=M;j++){
                    ma=max(ma,min(numas[0],sums[valas[0]][i])+min(numas[1],sums[valas[1]][j]-sums[valas[1]][i])+min(numas[2],sums[valas[2]][M]-sums[valas[2]][j]));
                }
            }
            if(valas[0]==valas[2]){
                ma=max(ma,min(numas[0]+numas[2],sums[valas[0]][M]));
            }
            printf("%lld\n",ma);
        }
    }
}
