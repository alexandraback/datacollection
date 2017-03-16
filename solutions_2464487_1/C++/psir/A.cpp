#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

#define VS vector<string>
#define VI vector<int>
#define VVI vector< VI >
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORC(it,kont) for(__typeof((kont).begin()) it = (kont).begin(); it!=(kont).end(); ++it)
#define PI 4*atan(1)

char buff[20000];

long long sum( long long r, long long k )
    {
    double K = k, R = r;
    double bla = K*(2*R+2 +(K-1)*4)/2;
    if( bla > 2e18) return -1;
    return k*(4*r+2 + (k-1)*4)/2;
    }

int main()
    {
    int T;
    gets(buff);
    sscanf(buff,"%d",&T);
    //cout << T << endl;
    FOR( tp, 0, T )
        {
        int sol = 0;        
        long long r,t;
        cin >> r >> t;
        //cout << r << t << endl;
        long long max = 707106781;
        long long min = 0;
 
        while(max != min )
            {
            long long mid = (max+min+1)/2;
            //cout << mid << endl;
            long long f = sum(r,mid);
            //cout << r << " " << mid << " " << f << endl;
            if( f <= t && f >= 0 )
                min = mid;
            else
                max = mid-1;
            }

        printf("Case #%d: %d\n",tp+1,max);
        }
    return 0;
    }
