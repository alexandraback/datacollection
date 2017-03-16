#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
using namespace std;
typedef long long ll;

vector<ll> nums;

vector<ll> gen[8];
bool isp(ll x){
	string ss="";
	while(x){
		ss+=(x % 10) + '0';
		x/=10;
	}
	FOR(i,ss.length())
		if(ss[i] != ss[ss.length() - i - 1]) return false;
	return true;
}
int main(){
	ll y,x;
	FORR(i,1,10){ gen[1].pb(i); }
	FORR(i,2,8){
		FOR(j,gen[i - 1].size())
			FOR(k,10)
				gen[i].pb(gen[i - 1][j] * 10 + k);	
	}
	
	FORR(i,1,18){
		if(i % 2){
			// reverse
			FOR(j,gen[(i + 1) / 2].size()){
				x=gen[(i + 1) / 2][j] / 10;
				y=gen[(i + 1) / 2][j];
				
				while(x){
					y=y * 10 + (x % 10);
					x /= 10;
				}
				if(isp(y * y)) nums.pb(y * y);
		//		cout<<y<<"\n";
			}
		}
		else{
			// reverse
			FOR(j,gen[i / 2].size()){
				x=gen[i / 2][j];
				y=gen[i / 2][j];
				
				while(x){
					y=y * 10 + (x % 10);
					x /= 10;
				}
				if(isp(y * y)) nums.pb(y * y);
		//		cout<<y<<"\n";
			}
			//if(i==14) cout<<y<<"\n";
		}
	}	

	/*ll x=11;
	while(x < 100){
		ll y=x * x;
		if(isp(y)) nums.pb(y);
		x+=11;
	}*/
	
	int t,n=nums.size();
	//cout<<n<<"\n";
	sort(nums.begin(),nums.end());
	//FOR(i,n) cout<<nums[i]<<"\n";
	cin>>t;
	FOR(tt,t){
		int l1=0,r1=n - 1,mid,l2=0,r2=n - 1;

		ll a,b;
		cin>>a>>b;
		while(r1 - l1 > 1){
			mid=(r1 + l1) / 2;
			if(nums[mid] > a) r1=mid;
			else l1=mid;
		}
		while(r2 - l2 > 1){
			mid=(r2 + l2) / 2;
			if(nums[mid] > b) r2=mid;
			else l2=mid;
		}	

		if(nums[n - 1] < a){ cout<<"Case #"<<tt + 1<<": 0\n"; continue; }
		if(nums[l1] < a) l1++;
		if(nums[r2] <= b) l2=r2;
		cout<<"Case #"<<tt + 1<<": "<<(l2 - l1 + 1)<<"\n";
	}
	return 0;
}
