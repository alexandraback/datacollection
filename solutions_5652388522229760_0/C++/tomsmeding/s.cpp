#include <iostream>

using namespace std;

int main(){
	int T,tt;
	cin>>T;
	for(tt=1;tt<=T;tt++){
		int N,Ns;
		cin>>N;
		if(N==0){
			cout<<"Case #"<<tt<<": INSOMNIA"<<endl;
			continue;
		}
		Ns=N;
		int seen=0; //bitmap
		while(true){
			int nn=N;
			while(nn){
				seen|=1<<(nn%10);
				nn/=10;
			}
			if(seen==0x3ff)break;
			N+=Ns;
		}
		cout<<"Case #"<<tt<<": "<<N<<endl;
	}
}
