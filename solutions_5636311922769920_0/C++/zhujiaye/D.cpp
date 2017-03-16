#include<iostream>
using namespace std;

typedef long long LL;

int Q,K,C,S;

int main(){
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cout<<"Case #"<<testcase<<": ";
		cin>>K>>C>>S;
		LL kc=1;
		for (int i=1;i<C;i++)
			kc*=K;
		LL now=1;
		for (int i=1;i<=S;i++){
			if (i>1)
				cout<<" ";
			cout<<now;
			now+=kc;	
		}
		cout<<endl;
	}
	return 0;
}
