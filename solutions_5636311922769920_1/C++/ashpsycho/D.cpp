#include <bits/stdc++.h>
using namespace std;
long long po(long long b,long long e){
	long long ans=1;
	while(e>0){
		if(e&1)ans=ans*b;
		b=b*b;
		e/=2LL;
	}
	return ans;
}
int main(){
	long long t,te,i,j,k,n,m,ans,c,s,K;
	cin>>t;
	vector<long long>v;
	for(te=0;te<t;te++){
		cin>>K>>c>>s;
		v.clear();
		for(i=0,k=0;i<s && k<K;i++){
			for(n=0,j=c-1;j>=0;j--){
				n+=((k%K)*po(K,j));
				if(k<K)k++;
			}
			v.push_back(n);
			if(k==K)break;
		}
		if(i==s)cout<<"Case #"<<(te+1)<<": IMPOSSIBLE\n";
		else{
			cout<<"Case #"<<(te+1)<<": ";
			for(i=0;i<v.size();i++)cout<<(1+v[i])<<" ";
			cout<<"\n";
		}
	}
	return 0;
}