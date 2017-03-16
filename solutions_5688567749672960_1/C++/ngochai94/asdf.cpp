#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-12
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long t,n,p10[16],req[16],ans;
vector<int> v;
bool flag;

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    p10[0]=1;
    For(i,1,16) p10[i]=10*p10[i-1];
    req[1]=1;
    req[2]=10;
    For(i,3,16)
    {
        req[i]=req[i-1]+1;
        For(j,0,(i-1)/2) req[i]+=18*p10[j];
        if(i%2==0) req[i]+=9*p10[i/2-1];
    }
    //cout<<req[4]<<endl;
    For(cas,1,1+t)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>n;
        v.clear();
        ans=0;
        if(n<20)
        {
            cout<<n<<endl;
            continue;
        }
        if(n%10==0)
        {
            n-=1;
            ans+=1;
        }
        while(n)
        {
            v.pb(n%10);
            n/=10;
        }
        //cout<<v.size();
        For(i,0,v.size()/2) swap(v[i],v[v.size()-1-i]);
        ans+=req[v.size()];
        flag=false;
        if(v[0]!=1)
        {
            flag=true;
            ans+=v[0]-1;
        }
        For(i,1,v.size()/2) if(v[i])
        {
            flag=true;
            ans+=p10[i]*v[i];
        }
        if(flag) ans++;
        if(v.size()&1) ans+=p10[v.size()/2]*v[v.size()/2];
        //cout<<ans<<endl;
        For(i,0,v.size()/2) ans+=p10[i]*v[v.size()-1-i];
        cout<<ans<<endl;
    }
}
