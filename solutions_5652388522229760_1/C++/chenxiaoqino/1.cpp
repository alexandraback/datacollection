#include <iostream>
#include <string>
using namespace std;

void calc(int N){
	bool all[10]={0};
	int Limit=10;

	if(N==0)
		goto FAIL;

	while(Limit<=N*10){
		Limit*=10;
	}
	Limit=Limit/N+1;


	for(int i=1;i<=Limit;i++){
		int NN=i*N;
		while(NN>0){
			all[NN%10]=true;
			NN/=10;
		}
		for(int j=0;j<10;j++)
			if(all[j]==false)goto SKIP;
		cout<<(i*N);
		return;
		SKIP:continue;
	}
	FAIL:
	cout<<"INSOMNIA";
	return;
}

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int IN;cin>>IN;
		cout<<"Case #"<<(i+1)<<": ";
		calc(IN);
		cout<<endl;
	}

	return 0;
}