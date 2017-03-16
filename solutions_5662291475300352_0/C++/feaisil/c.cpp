#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define VCERR(vect)for(size_t iiivcerr=0; iiivcerr<vect.size(); iiivcerr++) {errlog(vect[iiivcerr]); errlog(" ");} errlog("\n");
#define VIN(t,vect, len) t vect(N); for(size_t iiivcerr=0; iiivcerr<len; iiivcerr++) cin >> vect[iiivcerr];
#define FORN(i, n) for(int i=0; i<n; i++)
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<double> Vd;
typedef map<int,Vi> MVi;
typedef vector<string> Vstr;
typedef stack<int> Si;

template<typename T, bool a=true>
void errlog(const T& v)
{
    if(a)
    {
        cerr << v;
    }
}


void solve()
{
    int n,r;
    cin >> n;

    Vi p;
    Vi s;

    FORN(i,n)
    {
        int d,h,m;
        cin >> d >> h >>m;
        FORN(k,h)
        {
            p.push_back(d);
            s.push_back(m+k);
        }
    }

    // jeasy 2 points
    int slow = 0;
    if( s[0] < s[1])
    {
        slow = 1;
    }

    if((360.0 - p[slow])/360.0 * s[slow] <
            (1.0+(360.0 - p[(slow+1)%2])/360.0 )* s[(slow+1)%2])
        r=0;
    else
        r=1;
    cout << r << endl;
}

int main()
{
    int T;
    cin >> T;
    cerr << T << endl;
    string re;

    for(int tt=1; tt <= T; tt++)
    {
        if(tt*1000/T%10 ==0)
            cerr << tt << ", " << tt*100/T<< "%" << endl;
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}
