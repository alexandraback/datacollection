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
        string s;
        cin >> s;
        s = s + "+";
        vector<char> v(s.begin(), s.end());
        int lastminpos=-1;
        int ans=0;
        for ( int i=v.size()-1; i>=0; i-- )
        {
            if (v[i]=='-')
            {
                lastminpos = i;
                break;
            }
        }
        if (lastminpos>=0)
        {
            while (true)
            {
                for ( int i=0; i<=lastminpos; i++ )
                {
                    if (v[i]!=v[i+1])
                    {
                        // flip
                        reverse(v.begin(), v.begin()+i);
                        for ( int j=0; j<=i; j++ )
                        {
                            if (v[j]=='-')
                                v[j]='+';
                            else
                                v[j]='-';
                        }

                        ans++;
                        break;
                    }
                }
                if (v[lastminpos]=='+')
                    break;
            }
        }

        cout << "Case #" << ncase << ": ";
        cout << ans << endl;

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
