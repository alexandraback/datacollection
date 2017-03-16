#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,arr[1000001];
	cin>>t;
	for(i=0;i<1000001;i++)arr[i]=1000000;
	arr[1]=1;
	vector<int> a;
	for(i=2;i<1000001;i++){
		a.clear();
		arr[i]=1+arr[i-1];
		if(i%10==0)continue;
		for(j=i;j>0;j/=10)a.push_back(j%10);
		for(j=0,k=0;j<a.size();j++)k=k*10+a[j];
		arr[i]=min(arr[i],1+arr[k]);
	}
	for(te=0;te<t;te++){
		cin>>n;
		cout<<"Case #"<<(te+1)<<": "<<arr[n]<<"\n";
	}
}