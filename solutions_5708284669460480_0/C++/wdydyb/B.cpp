#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
string k,l;
int K,L,S;
int cnt,maxim,all;
int count(string now){
	//cout<<now<<endl;
	int ret=0;
	for(int i=0;i<=S-L;i++){
		if(now.substr(i,L)==l){
			ret++;
		}
	}
	//cout<<ret<<endl;
	return ret;
}
void search(int p,string now){
	if(p==0){
		all++;
		int pre=count(now);
		cnt+=pre;
		maxim=max(maxim,pre);
		return;
	}
	for(int i=0;i<K;i++){
		search(p-1,now+k[i]);
	}
}
int main(){
	int t,p=1;
	cin>>t;
	
	while(t--){
		cin>>K>>L>>S;
		cin>>k>>l;
		cnt=0,maxim=0,all=0;
		search(S,"");
		//cout<<cnt<<" "<<maxim<<" "<<all<<endl;
		//cout<<"Case #"<<p<<": "<<(double)maxim-(double)cnt/(double)all<<endl; 
		printf("Case #%d: %lf\n",p,(double)maxim-(double)cnt/(double)all);
		p++;
	}
	
	return 0;
}