#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
#define INF 1e18
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second

using namespace std;

ll gcd(ll n1,ll n2){
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
int arr[upperlimit+1];
vector <int> temp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("C-small-attempt0.in","r",stdin);
	freopen("outsmallC.txt","w",stdout);

	int t,i,j,k,n;
	int answer;
	bool valid;
	cin>>t;
    for(int k1=1;k1<=t;k1++){
        answer=0;
        cin>>n;
        for(i=1;i<=n;i++)cin>>arr[i];
        for(j=1;j<(1<<n);j++){
            int temp1=j;
            temp.clear();
            for(i=1;i<=n;i++){
                if(temp1&1)temp.pb(i);
                temp1/=2;
            }
            k=temp.size();
            sort(temp.begin(),temp.end());
            if(k>answer){
                do{
                    valid=true;
                    for(i=0;i<k;i++){
                        if(!(arr[temp[i]]==temp[(i+1)%k]||arr[temp[i]]==temp[(i+k-1)%k])){
                            valid=false;
                            break;
                        }
                    }
                    if(valid){
                        answer=k;
                    }
                }while(next_permutation(temp.begin(),temp.end()));
            }
        }
        cout<<"Case #"<<k1<<": "<<answer<<endl;
    }


	return 0;
}
