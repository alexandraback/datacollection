#include<iostream>
using namespace std;

int main(){
	int T,t,R,C,W;
	cin>>T;
	for(t=1;t<=T;t++){
		cin>>R>>C>>W;
		cout<<"Case #"<<t<<": ";
		if(R==1){
			if(C%W==0)	cout<<(C/W)+(W-1);
			else		cout<<(C/W)+(W);
		}
		else{
			int x;
			x=(R-1)*(C/W);
			if(C%W==0)	cout<<x+(C/W)+(W-1);
			else		cout<<x+(C/W)+(W);
		}cout<<endl;
	}
	return 0;
}
