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

double ts[2000],xs[2000];
int main(){
    int T;
    scanf("%d",&T);
    for(int ix=0;ix<T;ix++){
        printf("Case #%d:\n",ix+1);
        double D;
        int N,A;
        scanf("%lf%d%d",&D,&N,&A);
        for(int i=0;i<N;i++){
            scanf("%lf%lf",&ts[i],&xs[i]);
        }
        for(int i=0;i<A;i++){
            double ai;
            scanf("%lf",&ai);
            if(N==1){
                printf("%.10f\n",sqrt(2*D/ai));
            }else if(N==2){
                double v0=(xs[1]-xs[0])/(ts[1]-ts[0]);
                double art=(v0+sqrt(v0*v0+2*ai*xs[0]))/ai;
                double arx=0.5*ai*art*art;
                if(arx>=D) printf("%.10f\n",sqrt(2*D/ai));
                else printf("%.10f\n",art+(D-arx)/v0);
            }else printf("0\n");
        }
    }
}
