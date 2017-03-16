#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

long long dp[101][101];
long long a[101], A[101], b[101], B[101];

int main()
{
    int Cases, nowCase = 0;
    cin >> Cases;
    while (Cases--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i] >> A[i];
        for (int i = 1; i <= m; ++i)
            cin >> b[i] >> B[i];
        a[0] = b[0] = 0;
        A[0] = B[0] = 101;
        CLEAR(dp);
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (i) dp[i][j] = max(dp[i-1][j], dp[i][j]);
                if (j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if (i && j) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                long long sl[101];
                CLEAR(sl);
                for (int k = i+1; k <= n; ++k)
                {
                    long long sr[101];
                    CLEAR(sr);

                    sl[A[k]] += a[k];
                    for (int r = j+1; r <= m; ++r)
                    {
                        sr[B[r]] += b[r];
                        dp[k][r] = max(dp[k][r], dp[i][j] + min(sl[A[k]], sr[A[k]]));
                    }
                }
            }
        REP(i, n+1) { REP(j, m+1) {  ans = max(ans, dp[i][j]);}  }
        printf("Case #%d: ", ++nowCase);
        cout << ans << endl;
    }
    return 0;
}
