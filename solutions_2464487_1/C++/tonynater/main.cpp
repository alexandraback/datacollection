//tonynater - Google Code Jam 2013

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define sz(x) ((int) x.size())

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = 3.141592653589793;
const double tau = 6.283185307179586;
const double epsilon = 1e-6;

int T;

ll R, P;

bool check(ll nRings)
{
    return ((nRings*2*R + nRings+4*(nRings)*(nRings-1)/2) <= P);
}

int main (int argc, const char * argv[])
{
    freopen("/Users/tonynater/Downloads/A-large.in", "r", stdin);
    freopen("/Users/tonynater/Tony/Computer/Xcode_repos/Miscellaneous/codejam2013/output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> T;
    
    for(int t = 1; t <= T; t++)
    {
        cin >> R >> P;
        
        ll low = 0, high = min(LONG_MAX/2/R, (ll)sqrt(LONG_MAX)), mid;
        while(low < high-1)
        {
            mid = (low+high)/2;
            
            if(check(mid)) low = mid;
            else high = mid;
        }
        
        cout << "Case #" << t << ": ";
        
        if(!check(high)) cout << low << '\n';
        else cout << high << '\n';        
    }
    
    return 0;
}