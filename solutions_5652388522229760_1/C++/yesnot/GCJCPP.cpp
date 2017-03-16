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

//==================================
void solve()
{
    int numCases = 1;
    cin >> numCases;

    for ( int ncase=1; ncase <= numCases; ncase++ )
    {
        //===== start case
        bool seen[10];
        for (int i=0; i<10; i++)
            seen[i] = false;

        ll N;
        cin >> N;
        ll ans = -1;
        ll M=N;

        if (N>0)
        {
            while (true)
            {
                //check
                ll x = M;
                while (x>0)
                {
                    seen[x%10] = true;
                    x = x/10;
                }

                bool allseen = true;
                for ( int i=0; i<10; i++ )
                {
                    if (!seen[i])
                    {
                        allseen = false;
                        break;
                    }
                }
                if (allseen)
                {
                    ans = M;
                    break;
                }
                else
                    M += N;
            }
        }

        cout << "Case #" << ncase << ": ";
        if (ans>0)
            cout << ans << endl;
        else
            cout << "INSOMNIA" << endl;

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
