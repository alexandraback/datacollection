#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

long long dp[100][8], sum[100][8];
int main() {
    int Case = 1;
    long long t,i,j;
    long long  A,B,K;
    cin>>t;
    while(t--)
    {
        cin>>A>>B>>K;
        A -= 1;
        B -= 1;
        long long num = 0;
        for(i = 0; i < 80; i++)
        {
            for(j = 0; j < 8; j++)
            {
                sum[i][j] = 0;
                dp[i][j] = 0;
            }
        }
        dp[56][0] = 1;
        for (i = 55; i >= 0; i--) {
            for ( long long state = 0; state < 8; state++) {
                long long z = 1LL << i;
                long long  cnt = dp[i + 1][state];
                long long  val = sum[i + 1][state];
                if (cnt == 0) continue;
                for (int st = 0; st < 4; st++) {
                    int u = st & 1, v = st >> 1;
                    int cur = 0;
                    if (state & 4) cur |= 4;
                    else if (!u && (A & z)) cur |= 4;
                    else if (u && !(A & z)) continue;
                    
                    if (state & 2) cur |= 2;
                    else if (!v && (B & z)) cur |= 2;
                    else if (v && !(B & z)) continue;
                    
                    if (state & 1) cur |= 1;
                    else if ((u & v) && !(K & z)) continue;
                    else if (!(u & v) && (K & z)) cur |= 1;
                    dp[i][cur] += cnt;
                }
            }
        }
        for(i = 1; i < 8; i += 2) {
            num += dp[0][i];
        }
        cout<<"Case #"<<Case++<<": "<<num<<endl;
        
    }
    
    return 0;
}
