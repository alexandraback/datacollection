#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 0.0000001
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define maxn 32000

int t,n,res,cur,val;
string s;

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    For(cas,1,1+t)
    {
        cin>>n>>s;
        cur=res=0;
        For(i,0,n+1) if(s[i]!='0')
        {
            val=s[i]-'0';
            if(i>cur)
            {
                res+=i-cur;
                cur=i+val;
            }
            else cur+=val;
        }
        cout<<"Case #"<<cas<<": "<<res<<endl;
    }
}

