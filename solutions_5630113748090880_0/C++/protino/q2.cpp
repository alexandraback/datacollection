#include<bits/stdc++.h>
using namespace std;
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define mp make_pair // useful for working with pairs
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define present(c,x) ((c).find(x) != (c).end())
#define ll long long
#define fastscan ios_base::sync_with_stdio(0);cin.tie(NULL); 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

int main(){
	fastscan	
	int t;
	cin>>t;
	for(int p=1;p<=t;p++){
		cout<<"Case #"<<p<<": ";
		int n;
		cin>>n;
		map<int,int> m;
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				int x;cin>>x;
				m[x]++;
			}
		}
		tr(m,it){
			if((it->se)%2==1) cout<<it->fi<<" ";
		}
		cout<<"\n";
	}
	return 0;
}