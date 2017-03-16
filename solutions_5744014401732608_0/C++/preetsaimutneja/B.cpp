#include <bits/stdc++.h>
using namespace std;
const int N=51;
const long long bd=1e18;
bool pos[N];
bool g[N][N];
int t;
int b;
long long m;
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	cin>>t;
	for(int test=1;test<=t;++test) {
		cout<<"Case #"<<test<<": ";
		cin>>b>>m;
		int idx=0;
		long long cm=m-1;
		memset(pos,false,sizeof(pos));
		vector<bool> bin;
		while(cm) {
			bin.push_back(cm%2);
			cm/=2;
		}
		idx=bin.size();
		reverse(bin.begin(),bin.end());
		if(idx>=b-1) {
			cout<<"IMPOSSIBLE\n";
			continue;
		} else {
			cout<<"POSSIBLE\n";
		}
		for(int i=1;i<b;++i) {
			for(int j=i+1;j<b;++j) {
				g[i][j]=true;
			}
		}
		int z=b-bin.size()-1;
		for(int i=0;i<z;++i) {
			g[0][i]=0;
		}
		for(int i=0;i<idx;++i) {
			g[0][z+i]=bin[i];
		}
		g[0][b-1]=true;

		for(int i=0;i<b;++i) {
			for(int j=0;j<b;++j) {
				cout<<g[i][j];
			}
			cout<<"\n";
		}
	}
}