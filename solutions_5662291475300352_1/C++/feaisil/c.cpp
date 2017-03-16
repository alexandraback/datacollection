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
typedef pair<int,int> Pi;
typedef vector<pair<int,int> > Vii;
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
bool PairC(const Pi& firstElem,
                 const Pi& secondElem) {
  return (360.0 - firstElem.first)/360.0 * firstElem.second > (360.0 - secondElem.first)/360.0 * secondElem.second;

}
void solve()
{
    int n,r=10000000;
    cin >> n;

    Vii p;

    FORN(i,n)
    {
        int d,h,m;
        cin >> d >> h >>m;
        FORN(k,h)
        {
            p.push_back(make_pair(d,m+k));
        }
    }

    sort(p.begin(), p.end(), PairC);

    double eta = 0;
    int d = 0;
    FORN(i,p.size())
    {
        d=0;
        /* trouver cb depassent le plus long apr`es le dernier double */
        eta=(360.0 - p[i].first)/360.0 * p[i].second;
        for(int j=i+1; j<p.size(); ++j)
        {
            if(eta > ((1.0+(360.0 - p[j].first)/360.0) * p[j].second))
            {
                /* depassement plusieurs fois ?*/
                d+=int((eta-(360.0 - p[j].first)/360.0 * p[j].second)/p[j].second);
            }
        }
        errlog(i);
        errlog("\n");
        errlog(eta);
        errlog("\n");
        errlog(d);
        errlog("\n");
        r=min(r,d+i);
    }
/*
    int slow = 0;
    if( s[0] < s[1])
    {
        slow = 1;
    }

    if((360.0 - p[slow])/360.0 * s[slow] <
            (1.0+(360.0 - p[(slow+1)%2])/360.0 )* s[(slow+1)%2])
        r=0;
    else
        r=1;*/
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
