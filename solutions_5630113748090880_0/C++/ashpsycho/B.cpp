#include <bits/stdc++.h>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,co[2501];
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n;
		for(i=0;i<2501;i++)co[i]=0;
		for(i=0;i<(2*n-1);i++){
			for(j=0;j<n;j++){
				cin>>k;
				co[k]++;
			}
		}
		vector<int>v;
		for(i=0;i<2501;i++)if(co[i]&1)v.push_back(i);
		cout<<"Case #"<<(te+1)<<": ";
		for(i=0;i<n;i++)cout<<v[i]<<" ";
		cout<<"\n";
	}
	return 0;
}