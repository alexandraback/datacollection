#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;

bool check(int C,int D,int V,vector<int> coins) {
	if(V==0) return true;
	if(D==0) return false;
	if(coins.back()*(C+1)>V) {
		int max=coins.back()-1;
		coins.pop_back();
		return check(C,D-1,max,coins);
	}
	int max=V-coins.back()*C;
	coins.pop_back();
	return check(C,D-1,max,coins);
	return false;
}

bool repeated(vector<int> coins,vector<int> n) {
	for(int i=0;i<coins.size();i++) 
		for(int j=0;j<n.size();j++)
			if(n[j]==coins[i]) return true;
	return false;
}

vector<int> next(vector<int> v,int max) {
	int j=v.size()-1;
	v[j]++;
	int k=0;
	while(v[j]>max-k) {
		j--;
		k++;
		if(j<0) {
			v[0]=-1;
			return v;
		}
		v[j]++;
		for(int i=j+1;i<v.size();i++)
			v[i]=v[i-1]+1;
	}
	return v;
}

int main() {

	int nCases;
	cin>>nCases;
	
	for(int nCase=1; nCase<=nCases; nCase++) {
		cout<<"Case #"<<nCase<<": ";
		int C,D,V;
		cin>>C>>D>>V;
		vector<int> coins(D);
		for(int i=0;i<D;i++) {
			cin>>coins[i];
		}
		if(check(C,D,V,coins)) {
			cout<<0<<endl;
			continue;
		}
		int sol=-1;
		for(int n=1;n<V;n++) {
			vector<int> add(n);
			for(int i=0;i<n;i++) add[i]=i+1;
			while(true) {
				if(add[0]<0) break;
				if(!repeated(coins,add)) {
					vector<int> q=coins;
					q.insert( q.end(), add.begin(), add.end() );
					sort(q.begin(),q.end());
					if(check(C,D+n,V,q)) {
						sol=n;
						break;
					}
				}
				add=next(add,V);
			}
			if(sol>=0) break;
		}
		cout<<sol<<endl;
	}

	return 0;
}
