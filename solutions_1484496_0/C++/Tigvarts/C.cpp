#include<iostream>
#include <cstdio>
#include <map>
using namespace std;

int n;
int s[20];
int d[1<<20];
map<int, int> m;

void solve(){
	cin>>n;
	m.clear();
	for (int i=0; i<n; ++i)
		cin>>s[i];
	for (int i=1; i<(1<<n); ++i){
		d[i]=0;
		for (int j=0; j<n; ++j)
			if (i&(1<<j))
				d[i]+=s[j];
		if (m.count(d[i])!=0){
			for (int j=0; j<n; ++j)
				if ((1<<j) & m[d[i]])
					cout<<s[j]<<' ';
			cout<<endl;
			for (int j=0; j<n; ++j)
				if ((1<<j) & i)
					cout<<s[j]<<' ';
			cout<<endl;
			return;
		}
		m[d[i]]=i;
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
	}
}