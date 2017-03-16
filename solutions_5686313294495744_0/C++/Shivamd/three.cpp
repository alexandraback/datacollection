#include<bits/stdc++.h>
#define itn int
#define mp make_pair
#define endl "\n"
#define M_PI 3.14159265358979323846
using namespace std;
typedef long long ll;
int mod = 1e9 + 7 ;
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b); }
ll t,ii,j,i,n,m;
string str[1003][3];
map<string,ll> ma[3];
pair<ll,pair<ll,ll> > arr[100010];
bool comp(pair<ll,pair<ll,ll> >x,pair<ll,pair<ll,ll> > y)
{
    if(x.second.first>1 && x.second.second>1)
        return 0;
    return 1;
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("C:/Users/SHIVAM/Desktop/C-small-attempt0 (1)", "r", stdin);
	freopen("C:/Users/SHIVAM/Desktop/out.txt", "w", stdout);

    cin>>t;
    for(ii=1;ii<=t;ii++)
    {
        cin>>n;
        ma[0].clear();
        ma[1].clear();
        for(i=0;i<n;i++)
        {
            cin>>str[i][0]>>str[i][1];
            ma[0][str[i][0]]++;
            ma[1][str[i][1]]++;

        }
        for(i=0;i<n;i++)
        {
            arr[i].first=i;
            arr[i].second.first=ma[0][str[i][0]];
            arr[i].second.second=ma[1][str[i][1]];
            //cout<<arr[i].second.first<<" "<<arr[i].second.second<<endl;
        }
        ll ans=0;
        for(i=n-1;i>=0;i--)
        {
            sort(arr,arr+i+1,comp);
            //cout<<arr[i].first<<endl;
            ll ind=arr[i+1].first;
            ll v1=arr[i+1].second.first;
            ll v2=arr[i+1].second.second;
            if(v1>1 && v2>1)
            {
                ans++;
            }
            for(j=0;j<i;j++)
            {
                if(str[arr[j].first][0]==str[ind][0])
                    arr[j].second.first--;
                if(str[arr[j].first][1]==str[ind][1])
                    arr[j].second.second--;


            }
        }
        cout<<"Case #"<<ii<<": "<<ans<<endl;
    }
}
