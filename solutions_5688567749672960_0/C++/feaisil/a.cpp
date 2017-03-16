#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

#define VCERR(vect)for(size_t iiivcerr=0; iiivcerr<vect.size(); iiivcerr++) {errlog(vect[iiivcerr]); errlog(" ");} errlog("\n");
#define VIN(t,vect, len) t vect(N); for(size_t iiivcerr=0; iiivcerr<len; iiivcerr++) cin >> vect[iiivcerr];
#define FORN(i, n) for(int i=0; i<n; i++)
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<double> Vd;
typedef map<int,Vi> MVi;
typedef vector<string> vstr;

template<typename T, bool a=false>
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
    int N,r,v;
    cin >> N;
    r=0;
    v=0;

    if(N < 10)
    {
        r=N;
    }
    else
    {
        r+=10;v=10;

        if( N >= 100)
        {
            r+=20 * (numDigits(N) -2);
            v=pow(10,numDigits(N)-1);
        }
        // first digit/last
        int f=0, l=N%10;
        if(v>0)
            f=N/v;
        cerr << r<<" "<< v <<" "<< f <<" "<< l << endl;
        if(l== 0)
        {
            r+=N-v;
        }
        else
        {
            r+=f+1;
            v=f*v+1;
            r+=N-v;
        }
    }
    cout << r<< endl;
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
