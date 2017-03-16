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
		string a;
		vector<char> v1,v2;
		cin>>a;
		char c=a[0];
		for(int i=1;i<a.size();i++){
			if(a[i]>=c){
				c=a[i];
				v1.pb((char)c);
			}
			else{
				v2.pb((char)a[i]);
			}
		}
		for(int i=v1.size()-1;i>=0;i--) cout<<v1[i];
		cout<<a[0];
		for(int i=0;i<v2.size();i++) cout<<v2[i];
		cout<<"\n";
	}
	return 0;
}