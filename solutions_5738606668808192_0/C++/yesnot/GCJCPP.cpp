#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <limits>

using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<long long> vll;

template <typename T>
string tostring ( T value )
{
    ostringstream ss;
    ss << value;
    return ss.str();
}

template <typename T>
T strtonum ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
//----------------------------------
#define MOD 1000000007
#define MAXPRM 1000000
bool isprime[MAXPRM];
set<ll> prmset;
void calcprimes()
{
    for ( int i=0; i<MAXPRM; i++ )
        isprime[i] = true;

    isprime[0] = false;
    isprime[1] = false;
    for ( int j=4; j<MAXPRM; j+=2 )
        isprime[j]=false;

    int cnt=0;
    for ( int i=3; i*i<=MAXPRM; i+=2 )
    {
        if (isprime[i])
        {
            cnt++;
            for ( int j=i*i; j<MAXPRM; j+=i)
            {
                isprime[j]=false;
                cnt++;
            }
        }
    }
    for ( int i=0; i<MAXPRM; i++ )
    {
        if (isprime[i])
            prmset.insert(i);
    }
    //cout << "prmset:" << prmset.size() << endl;
}

bool isnprime(ll n, ll& divisor)
{
    if (n==2)
        return true;
    if (n<2)
        return false;
    if (n%2==0)
    {
        divisor = 2;
        return false;
    }
    if (prmset.find(n)!=prmset.end())
        return true;
    for ( auto it=prmset.begin(); it!=prmset.end(); it++ )
    {
        ll p = *it;
        if ( p*p > n)
            break;
        if ( n % p == 0)
        {
            divisor = p;
            return false;
        }
    }
    return true;
}

ll todec(vector<int> vbin, int frombase)
{
    ll res = 0;
    ll k=1;
    for ( int i=vbin.size()-1; i>=0; i-- )
    {
        if (vbin[i]==1)
            res += k;
        k *= frombase;
    }
    return res;
}

//==================================
void solve()
{
    int numCases = 1;
    cin >> numCases;

    calcprimes();

    for ( int ncase=1; ncase <= numCases; ncase++ )
    {
        //===== start case
        int N, J;
        cin >> N >> J;
        int njamcoins = 0;
        cout << "Case #" << ncase << ":" << endl;
        ll maxnum = 1;
        for ( int i=0; i<N; i++ )
            maxnum *= 2;
        //cout << maxnum << endl;

        for ( ll num=maxnum/2; num<maxnum; num++)
        {
            if ( njamcoins==J )
                break;

            // check first and last digit
            if ( (num%2==0) || ((num>>(N-1))==0) ) continue;
            //if ( (num%2==0) || ((num>>5)==0) ) continue;

            //if (num!=9) continue;
            //if (!(num==35 || num==63 || num==57)) continue;

            vector<int> vci;
            for ( int i=15; i>=0; i-- )
            {
                if ( ((num>>i) & 1)==1 )
                    vci.push_back(1);
                else
                    vci.push_back(0);
            }

            bool jamcoin = true;
            vector<ll> divlist;
            for ( int base=2; base<=10; base++ )
            {
                ll y = todec(vci, base);
                ll divisor;
                if (isnprime(y, divisor))
                {
                    jamcoin = false;
                    break;
                }
                divlist.push_back(divisor);
                //cout << y << endl;
            }
            if (jamcoin)
            {
                njamcoins++;
                //cout << njamcoins << ":";
                for ( int i=0; i<vci.size(); i++ ) {
                    cout << vci[i];
                }
                for ( auto it=divlist.begin(); it!=divlist.end(); it++ ) {
                    cout << " " << *it;
                }
                cout << endl;
            }
        }

        //cout << ans << endl;

        //===== end case
    }
}

int main()
{
#ifdef CCQTEST
#include "HRCPP1.h"
#endif
    solve();
#ifdef CCQTEST
#include "HRCPP2.h"
#endif
    return 0;
}
