#include<iostream>
#include <cstdio>
#include <map>
#include <cstdlib>
using namespace std;

int n;
long long s[20];
long long S[500];
long long d[1<<20];
map<long long, int> m;

void solve(){
	cin>>n;
	for (int i=0; i<n; ++i)
		cin>>S[i];
	for (int sh=0; sh<100; sh+=20){
		m.clear();
		for (int i=0; i<25; ++i)
			s[i]=S[i+sh];
		for (int i=1; i<(1<<25); ++i){
			d[i]=0;
			for (int j=0; j<25; ++j)
				if (i&(1<<j))
					d[i]+=s[j];
			if (m.count(d[i])!=0){
				for (int j=0; j<25; ++j)
					if ((1<<j) & m[d[i]])
						cout<<s[j]<<' ';
				cout<<endl;
				for (int j=0; j<25; ++j)
					if ((1<<j) & i)
						cout<<s[j]<<' ';
				cout<<endl;
				return;
			}
			m[d[i]]=i;
		}
	}
	cout<<"Impossible"<<endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	for (int i=1; i<=t; ++i){
		cout<<"Case #"<<i<<":\n";
		solve();
		cerr<<i<<endl;
	}
}