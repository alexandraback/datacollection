
#include<bitset>
#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

inline int in()
{
    int res=0;char c;int f=1;
    while((c=getchar())<'0' || c>'9')if(c=='-')f=-1;
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res*f;
}
const int N=100010,MOD=1e9+7;


int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T=in(),ca=1;

    //printf("Case #%d: %d\n",ca++,ans);
    while(T--)
    {
        string s;
        cin>>s;
        int n=s.size();
        string ans="",t="";
        ans += s[0],t+=s[0];

        for(int i=1;i<n;i++)
        {
            ans += s[i];
            t.insert(0,1,s[i]);
            if(ans < t) ans=t;
            else t=ans;
        }
        cout<<"Case #"<<(ca++)<<": "<<ans<<endl;
    }
    return 0;
}
