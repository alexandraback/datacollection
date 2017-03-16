#include <iostream>
#include <sstream>
#include <math.h>
#include <cmath>
#include <map>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    //ios::sync_with_stdio(0);
    freopen( "input.txt" , "r" , stdin );freopen( "output.txt" , "w" , stdout );
    long long t;
    cin >> t;
    for(long long F = 0 ; F < t ; ++F)
    {
        cout << "Case #" << F+1 << ": ";
        long long a , n , x;
        cin >> a >> n;
        vector< long long > v;
        for( long long i = 0 ; i < n ; ++i )
        {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        long long ans = 10000000000000000;
        long long st = 0;
        for( int i = 0 ; i < v.size() ; ++i )
        {
            if( v[i] < a )
                a += v[i];
            else
            {
                ans = min(ans,st+v.size()-i);
                if(a == 1)
                    st = ans + 1;
                else
                while( a <= v[i] )
                {
                    a += a-1;
                    ++st;
                }
                a += v[i];
            }
        }
        cout << min(st,ans) << endl;
    }
    return 0;
}
