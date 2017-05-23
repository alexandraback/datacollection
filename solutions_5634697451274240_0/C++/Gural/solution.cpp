#include<bits/stdc++.h>
#define maxn 500009
#define INF 1000000007
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mid(a,b) (a+b)/2
#define sz size()
#define ll long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define tr(i, c) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
using namespace std;
int main(){
	freopen("kek.in", "r", stdin);
	freopen("kek.out", "w", stdout);
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		string s;
		cin>>s;
		int ans=0;
		for(int i=1;i<s.sz;i++){
			if(s[i]!=s[i-1])
				ans++;
		}
		cout<<"Case #"<<j+1<<": ";
		if(s[s.sz-1]=='-')
			cout<<ans+1<<endl;
		else
			cout<<ans<<endl;
	}
return 0;
}

