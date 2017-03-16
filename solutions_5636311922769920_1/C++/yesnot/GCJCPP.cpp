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
        int K,C,S;
        cin >> K >> C >> S;
        cout << "Case #" << ncase << ": ";
        if (K==1) {
                cout << "1" << endl;
        }
        else if (C==1) {
            if (S<K)
                cout << "IMPOSSIBLE" << endl;
            else {
                cout << 1;
                for (int i=2; i<=K; i++)
                    cout << " " << i;
                cout << endl;
            }
        }
        else {
            if (S>=K-1) {
                cout << 2;
                for (int i=3; i<=K; i++)
                    cout << " " << i;
                cout << endl;
            }
            else {
                cout << "IMPOSSIBLE" << endl;
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
