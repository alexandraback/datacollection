#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

string solve(){
	int n,m;
	int a[113][113],b[113],c[113];
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>n>>m;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>a[i][j];
			b[i]=max(b[i],a[i][j]);
			c[j]=max(c[j],a[i][j]);
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (b[i]>a[i][j] && c[j]>a[i][j]) return "NO";
		}
	}
	return "YES";
}

int main(){
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solve()<<'\n';
	}
	return 0;
}