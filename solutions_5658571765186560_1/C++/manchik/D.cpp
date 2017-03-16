#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int X,R,C;
		cin>>X>>R>>C;
		cout<<"Case #"<<t<<": ";
		if(X==1)
		cout<<"GABRIEL"<<endl;
		else if(X==2)
		{
			if((R*C)%2==0)
			cout<<"GABRIEL"<<endl;
			else
			cout<<"RICHARD"<<endl;
		}else if(X==3)
		{
			if(R*C==6||R*C==9||R*C==12)
			cout<<"GABRIEL"<<endl;
			else
			cout<<"RICHARD"<<endl;
		}else{
			if(R*C==16||R*C==12)
			cout<<"GABRIEL"<<endl;
			else
			cout<<"RICHARD"<<endl;
		}
		
	}
	return 0;
}		
