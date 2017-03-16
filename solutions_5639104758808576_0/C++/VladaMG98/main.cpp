#include <bits/stdc++.h>
using namespace std;
const bool SUBMIT=true;
const int MAXN=1010;
int arr[MAXN],cums[MAXN];
int main()
{
    if(SUBMIT)
    {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    }
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        string s;
        cin >> s;
        for(int i=0;i<=n;i++) {arr[i]=s[i]-'0',cums[i]=cums[i-1]+arr[i];}
        int ans=0;
        for(int i=0;i<=n;i++) ans=max(ans,i-cums[i-1]);
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}
