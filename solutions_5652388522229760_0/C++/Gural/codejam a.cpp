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
int arr[maxn];
int main(){
	freopen("a.in" , "r" , stdin);
	freopen("a.out" , "w" , stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		bool ok = false;
		ll u,n,r;
		cin>>u;
		
		for (int h = 0; h < 10; h++)
			arr[h] = 0;
		
		n = u;
		if (u != 0) {
		r = u;
		while(1){
			u = r;
			while(u>0){
				arr[u%10]=1;
				u/=10;
			}
			ok=1;
			for(int i=0;i<=9;i++)
				if(arr[i]==0)
					ok=0;
			if(ok)
				break;
			r+=n;
		} }
		
		
		cout<<"Case #"<<i<<": ";
		if (n == 0) {
			cout << "INSOMNIA\n";
		}
		else
			cout<<r<<endl;
	}

return 0;
}

