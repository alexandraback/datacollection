#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main()
{
	int TC;
    cin >> TC;
	for ( int tc=1 ; tc<=TC ; ++tc )
	{
		printf("Case #%d: ", tc);
        int n;
        cin >> n;
        double sc[64];
        double sum = 0.0;
        for ( int i=0 ; i<n ; ++i ) 
        {
            cin >> sc[i];
            sum += sc[i];
        }
        int sumint = (int)sum;
        double lo = 0.0;
        double hi = sum;
        for ( int r=0 ; r<100 ; ++r )
        {
            double mid = (lo + hi) * 0.5;
            double ss = 0.0;
            for ( int i=0 ; i<n ; ++i )
            {
                double t = (1.0 * mid - sc[i]) / sum;
                if ( t < 0.0 ) t += -10.0;
                ss += t;
            }
            if ( ss < 1.0 )
            {
                lo = mid;
            }
            else 
            {
                hi = mid;
            }
        }
        double kk = (lo + hi) * 0.5;
        //printf("k = %.3lf\n", kk);
        for ( int i=0 ; i<n ; ++i )
        {
            printf("%.8lf ", (1.0 * kk - sc[i])*100 / sum);
        }
        puts("");
	}
	return 0;
}
