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
int main()
{
//    freopen("B.in","r",stdin);
//    freopen("B.out","w",stdout);
    int T;
    double C,F,X;
    cin>>T;
    for(int t=1;t<=T;++t){
        cin>>C>>F>>X;
        double sum=0,sp=2;
        while(1){
            double cur=C/sp;
            if(X/sp<=X/(sp+F)+cur){
                sum+=X/sp;
                break;
            }
            sum+=cur;
            sp+=F;
        }
        printf("Case #%d: %.7lf\n",t,sum);
    }
    return 0;
}
