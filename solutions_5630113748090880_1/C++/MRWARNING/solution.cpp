#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<bitset>
#define LL long long

const int MAXN=0;
const int MAXM=0;
const long long LLINF=9000000000000000000;
const int INF=2147483647;//careful because of floyed and so on
const int MOD=1000000007;
double eps=0.00000001;

using namespace std;

int T;
int n;
int cnt[3000];
vector<int>ans;

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
            ans.clear();
            memset(cnt,0,sizeof(cnt));
            scanf("%d",&n);
            for (int i=1;i<=2*n-1;i++){
                    for (int j=1;j<=n;j++){
                            int x;
                            scanf("%d",&x);
                            cnt[x]++;
                    }
            }
            for (int i=1;i<=2500;i++){
                    if (cnt[i]%2==1) ans.push_back(i);
            }
            sort(ans.begin(),ans.end());
            printf("Case #%d: ",cas);
            printf("%d",ans[0]);
            for (int i=1;i<n;i++) printf(" %d",ans[i]);
            printf("\n");
    }
    return 0;
}
