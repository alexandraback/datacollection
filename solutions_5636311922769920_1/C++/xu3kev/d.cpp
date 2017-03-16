#include<iostream>
using namespace std;
long long int expK[101];
int main(){
	int T;
	cin>>T;
	int ans=0;
	long long int K,C,S;
	for(int cs=1;cs<=T;++cs){
		cin>>K>>C>>S;
		expK[0]=1;
		for(int i=1;i<=100;++i){
			expK[i]=expK[i-1]*K;
		}

		cout<<"Case #"<<cs<<":";
		if(S<(K-1)/C+1){
			cout<<" IMPOSSIBLE";
		}
		else{
			long long int count=0;
			long long int pos=0;
			for(int i=0;i*C<K;++i){
				//cout<<"("<<i*C<<" "<<count<<endl;
				for(int j=1;j<C;++j){
					if(count!=K-1){
						++count;
					}
					pos=pos*K+count;
				}
				cout<<" "<<pos+1;
				long long int expKC=1;
				long long int tmp=C;
				while(tmp>0){
					expKC*=K;
					--tmp;
				}
				if(pos>expKC){
					cerr<<"WARNING"<<endl;
					exit(-1);
				}
				if(count!=K-1){
					++count;
				}
				pos = count;
			}
		}
		cout<<endl;
	}
	return 0;
}
