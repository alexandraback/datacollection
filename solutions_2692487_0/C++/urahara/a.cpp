#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<climits>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<complex>
#include<set>
#include<bitset>
#include<utility>
#include<valarray>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;

#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define all(a) (a).begin(),(a).end()
#define len(a) ((int)(a).size())
#define mem(a,n) memset(a,n,sizeof(a))
#define eps 1e-9
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,n) for(int i=(a);i<(n);i++)
#define repr(i,a,n) for(int i=(n);i>=(a);i--)

#define inf 99999999999999LL
int main(void){
	ios_base::sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	ll t,n,cur;
	cin>>t;
	rep(k,t){
		cin>>cur>>n;
		vll v(n);
		rep(i,n)cin>>v[i];
		sort(all(v));
		ll re=inf,added=0;
		if(cur==1){cout<<"Case #"<<k+1<<": "<<n<<endl;continue;}
		rep(i,n){			
			ll cc=0;
			while(cur<=v[i]){
				cc++;
				cur+=cur-1;
			}
			added+=cc;
			cur+=v[i];
			re = min(re,n-i+added-cc);
			re = min(re,n-i-1+added);
		}
		re = min(re,added);
		cout<<"Case #"<<k+1<<": "<<re<<endl;
	}
	return 0;
}
