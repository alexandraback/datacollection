
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

//#define LOCAL

#ifndef LOCAL
#define OPEN(prefix)\
        {\
                char in[256], out[256];\
                snprintf(in, 256, "%s.in", prefix);\
                snprintf(out, 256, "%s.out", prefix);\
                freopen(in, "r", stdin);\
                freopen(out, "w", stdout);\
        }
#define CLOSE() \
        {\
                fclose(stdin);\
                fclose(stdout);\
        }
#else 
#define OPEN(prefix)
#define CLOSE()
#endif

typedef long long LL;
const int N = 10010;
const int M = 10000010;
LL dp[2][M];
LL v[N];

int main()
{
    OPEN("B-small-attempt1");
    int T;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        int E, R, n;
        cin>>E>>R>>n;
        for (int i = 1; i <= n; i++)
            cin>>v[i];
        
        int i = 1, j = n;
        while (i < j){
            swap(v[i], v[j]);
            i++, j--;
        }
        
        for (int j = 0; j <= E; j++)
            dp[0][j] = 0;
//            dp[0][j][0] = dp[0][j][1] = 0;
        
        int d = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= E; j++){
               int pj = min(j + R, E);
               dp[d][j] = dp[d ^ 1][pj];
               if (j && dp[d][j] < dp[d][j - 1] + v[i])
                   dp[d][j] = dp[d][j - 1] + v[i];
/*                dp[d][j][0] = dp[d ^ 1][j][0];
                if (j && dp[d][j][0] < dp[d][j - 1][1] + v[i])
                    dp[d][j][0] = dp[d][j - 1][1] + v[i];
                
                int pj = min(j + R, E);
                dp[d][j][1] = dp[d ^ 1][pj][0];
                if (j && dp[d][j][1] < dp[d][j - 1][1] + v[i])
                    dp[d][j][1] = dp[d][j - 1][1] + v[i];
 */
            }
            d ^= 1;
            
        }
        cout<<"Case #"<<cas<<":"<<" ";
        cout<<dp[d^1][E]<<endl;
    }
    
    CLOSE();
    return 0;
}
