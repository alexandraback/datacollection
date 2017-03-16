#include <iostream>

using namespace std;

int main(){
	int T;
	int h[2501];
	int htem;
	cin>>T;
	for(int t=1;t<=T;t++){
		int N;
		cin>>N;
		for(int i=0;i<2501;i++){
			h[i]=0;
		}
		for(int i=0;i<N*(2*N-1);i++){
			cin>>htem;
			if(h[htem]==0) h[htem]=1;
			else h[htem]=0;
		}
		cout<<"Case #"<<t<<":";
		for(int i=1;i<2501;i++){
			if(h[i]==1){
				cout<<' '<<i;
			}
		}
		cout<<endl;
	}
	return 0;
}
