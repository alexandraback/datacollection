#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long ll;
#define C_UE 10
#define V2V_UE 10
#define maxn 10000000
#define mod 1000000007

char s[1005];
int main()
{
    freopen("A-large.txt", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t;cas++)
    {
        scanf("%s",s);
        string ans = "";
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            string A=ans+s[i],B=s[i]+ans;
            ans=max(A,B);
        }
        printf("Case #%d: ",cas);
        cout<<ans<<endl;
    }
    return 0;
}
