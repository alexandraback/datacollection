#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long fn(long long n){
	if(n<=20)return n;
	long long dig=0,i,j,k,n1;
	for(i=n;i>0;i/=10)dig++;
	for(i=0,j=1;i<((dig+1)/2);i++)j*=10LL;
	n1=n;
	k=(n%j)-1;
	n=1+((n/j)*j);
	v.clear();
	for(i=n;i>0;i/=10)v.push_back(i%10);
	for(i=0;i<(v.size()/2);i++)if(v[i]!=v[v.size()-(i+1)])break;
	if(k<0||i==(v.size()/2)){
		k=1 + (n1%j);
		return k+fn(n1-k);
	}
	for(n1=0,i=0;i<v.size();i++)n1=n1*10+v[i];
	return k+1+fn(n1);
}
int main(){
	long long t,te,i,j,k,n,m;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n;
		m=fn(n);
		cout<<"Case #"<<(te+1)<<": "<<m<<"\n";
	}
}