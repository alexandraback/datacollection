#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define MINF 0xc0c0c0c0
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

int T;
string S;
char latest[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
        cin >> S;
        string fr, ba;
        latest[0] = S[0];
        for (int i = 1; i < S.length(); ++i)
            latest[i] = max(latest[i-1], S[i]);
        for (int i = S.length()-1; i >= 0; --i)
        {
            if (S[i] == latest[i])
                fr += S[i];
            else
                ba += S[i];
        }
        for (int i = ba.length()-1; i >= 0; --i)
            fr += ba[i];
        cout << "Case #" << z << ": " << fr << endl;
    }
}
