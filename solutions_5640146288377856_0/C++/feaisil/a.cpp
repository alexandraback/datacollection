#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>
#include <time.h>
using namespace std;

#define VCERR(vect)for(size_t iiivcerr=0; iiivcerr<vect.size(); iiivcerr++) {errlog(vect[iiivcerr]); errlog(" ");} errlog("\n");
#define VIN(t,vect, len) t vect(N); for(size_t iiivcerr=0; iiivcerr<len; iiivcerr++) cin >> vect[iiivcerr];
#define FORN(i, n) for(int i=0; i<n; i++)
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<double> Vd;
typedef map<int,Vi> MVi;
typedef vector<string> vstr;

#ifdef DBG
#define dbg true
#else
#define dbg false
#endif
template<typename T, bool a=dbg>
void errlog(const T& v)
{
    if(a)
    {
        cerr << v;
    }
}

int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int f(Vi& v)
{
    int c=0;
    for(int i=0; i < v.size(); i++ )
    {
        if(v[i]<i)
            c++;
    }
    return c;
}

void solve()
{
    int N;
    int C;
    int R;
    int W;
    int h;
    cin >> R >> C >> W;

    h=C/W*R;
    if(C%W > 0)
        h++;
    h+=W -1;
    //cin >> N;
//    errlog();
    cout << h << endl;
}

int main()
{
    int T;

    time_t t,t2;
    time(&t);
    cin >> T;
    cerr << T << endl;
    string re;

    for(int tt=1; tt <= T; tt++)
    {
        if(tt*1000/T%10 ==0)
        {
            time(&t2);
            cerr << "#" << tt << ", " << tt*100/T<< "%" << " { " << difftime(t,t2) << " } " << endl;
        }
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}
