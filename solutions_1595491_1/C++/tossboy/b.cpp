#include<iostream>
using namespace std;

int T,N,S,P;

int main(){
	cin>>T;
	for(int ca=1; ca<=T; ca++){
		cout<<"Case #"<<ca<<": ";
		cin>>N>>S>>P;
		int cnt =0;
		for(int i=0; i<N; i++){
			int tol;
			cin>>tol;
			if( (tol+2)/3 >= P)
				cnt ++;
			else if(S>0 && (tol+4)/3>=P && (tol+4)/3>=2){
				S--;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
