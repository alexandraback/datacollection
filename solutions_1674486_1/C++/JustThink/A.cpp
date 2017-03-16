#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>

using namespace std;

int qcompare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

bool compare(int a,int b){
	return a<b;
}
vector<int> inh[1002];
map<int,int> cache;
//syntax for qsort => qsort (array, n, sizeof(int), qcompare);
//c++ sort => sort(v.begin(),v.end(),mycompare)
int solve(int i,int j){
	if(i==j)return 0;
	int hash=i+1005*j;
	if(cache.count(hash)!=0)return cache[hash];
	int k=0;
	int ways=0;
	for(k=0;k<inh[i].size();k++){
		if(inh[i][k]==j)ways+=1;
		else ways+=solve(inh[i][k],j);
	}
	cache[hash]=ways;
	return ways;
}
int main(){
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		cache.clear();
		int n;
		cin>>n;
		int i,j,k,m;
		for(i=0;i<n;i++){
			inh[i].clear();
			cin>>m;
			for(j=0;j<m;j++){
				cin>>k;
				inh[i].push_back(k-1);
			}
		}
		int ways=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				ways=solve(i,j);
				if(ways>=2)break;
			}
			if(ways>=2)break;
		}
		if(ways>=2)cout<<"Case #"<<cas<<": "<<"Yes"<<endl;
		else cout<<"Case #"<<cas<<": "<<"No"<<endl;
	}

	return 0;
}
