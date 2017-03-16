#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long pow(int a,int x){
	long long p=1;
	for(int i=0;i<x;i++){
		p*=a;
	}
	return p;
}

int main(){
	int T;
	cin>>T;
	int K,C,S;
	int index;
	long long dist,offset;
	for(int i=1;i<=T;i++){
		vector<long long> v;
		cin>>K>>C>>S;
		if(S < ((K-1)/C+1)){
			cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
			continue;
		}
		index=1;
		
		while(index <= K){
			long long base = (index-1)*pow(K,C-1);
			offset=1;
			for(int h=2;h<=C;h++){
				if(index<K){
					index++;
				}
				offset=(offset-1)*K+index;
			}
			v.push_back(base+offset);
			index++;
		}
		cout<<"Case #"<<i<<":";
		vector<long long>::iterator it;
		for(it=v.begin();it!=v.end();it++){
			cout<<" "<<(*it);
		}
		cout<<endl;
	} 
	return 0;
}

