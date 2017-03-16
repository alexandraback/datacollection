/**
 *@author A B M Faisal
 */

# include <iostream>
# include <sstream>

# include <vector>
# include <string>
# include <map>
# include <stack>
# include <queue>
# include <deque>
# include <set>
# include <algorithm>
# include <memory>

# include <utility>
# include <assert.h>

# include <cstring>
# include <cstdio>
# include <cctype>
# include <cstdlib>
# include <cmath>

using namespace std;
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
#define S(x) ((x)*(x))
#define I(n)   scanf("%d",&(n))
const double pi = acos(-1.0);
typedef long long LL;

int main()
{
    freopen("A-large.in","r",stdin);

    freopen("out1.txt","w",stdout);
    int T,N,J[220];
    I(T);
    for(int cas=1;cas<=T;cas++)
    {
        I(N);
        int X=0;
        for(int i=0;i<N;i++){
            I(J[i]);
            X+=J[i];
        }
        double needed = X*1.0/N;
        printf("Case #%d:",cas);
        for(int i=0;i<N;i++)
        {
            double lo = 0.,hi=1.;
           // cout<<"lo "<<lo<<endl;
           // cout<<"hi "<<hi<<endl;

          //  cout<<fabs(lo-hi)<<" % "<<1e-12<<endl;
            while( fabs(lo-hi) > 1e-12 ){
                double mid = (lo+hi)/2.;

                double left = 1. - mid;

                double points = J[i] + X * mid;

                for(int j=0;j<N;j++){
                    if ( j == i ) continue;
                    double need = points - J[j];
                    need /= X;
					if ( need < 0.0 ) continue;
                    left -= need;
                }

                if ( left >= 0 ){
                    lo = mid;
                }
                else hi = mid;
            }
            printf(" %.6lf",lo*100);
        }
        printf("\n");
    }
    return 0;
}
