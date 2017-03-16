#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e5+1;
string s;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,k;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        int i,ans=0;
        cin>>s;
        for(i=s.length()-1;i>=0;i--)
            if(((ans%2==0)&&s[i]=='-')||((ans%2)&&s[i]=='+'))ans++;
        printf("Case #%d: %d\n",k,ans);
    }
    return 0;
}
