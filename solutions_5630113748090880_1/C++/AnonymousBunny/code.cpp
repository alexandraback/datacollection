#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define maxn 60
map <int, int> cnt;
set <int> s;
int uu;
int main() {
	// your code goes here
	int t;
	cin>>t;
	for (uu=1; uu<=t; uu++){
		s.clear();
		cnt.clear();
		int n;
		cin>>n;
		int x;
		for (int j=1; j<=2*n-1; j++){
			for (int k=0; k<n; k++){
				cin>>x;
				cnt[x]++;
				s.insert(x);
			}
		}
		cout<<"Case #"<<uu<<": ";
		for (set<int>::iterator it= s.begin(); it!=s.end(); it++){
			if (cnt[*it]%2==1) cout<<*it<<" ";
		}
		cout<<endl;
	}
	return 0;
}
