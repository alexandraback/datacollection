#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<numeric>
#include<fstream>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64

int dp[100];
int main(){
    int t,cs = 1, coin[105], c, d, v, i, j, ans;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>c>>d>>v;
        CLR(dp);
        dp[0] = 1;
        for(i = 0;i<d;i++){
            cin>>coin[i];
            for(j = v;j>=coin[i];j--){
                dp[j] = dp[j] || dp[j - coin[i]];
            }
        }
        while(1){
            for(i = 0;i<=v;i++){
                if(dp[i] == 0) break;
            }
            if(i > v) break;
            for(j = v;j>=i;j--){
                dp[j] = dp[j] || dp[j - i];
            }
            ans++;
        }
        printf("Case #%d: %d\n",cs++,ans);
    }
	return 0;
}
