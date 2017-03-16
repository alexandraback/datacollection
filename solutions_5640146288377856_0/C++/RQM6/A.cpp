#include<iostream>
using namespace std;

int main(){
	int T,t,R,C,W;
	cin>>T;
	for(t=1;t<=T;t++){
		cin>>R>>C>>W;
		cout<<"Case #"<<t<<": ";
		if(C%W==0)	cout<<(C/W)+(W-1);
		else		cout<<(C/W)+(W);
		cout<<endl;
	}
	return 0;
}
