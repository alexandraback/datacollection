#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int qq=1;qq<=t;qq++)
	{
		int x,r,c;
		cin>>x>>r>>c;
		if(x>=7||(r*c)%x!=0)
			cout<<"Case #"<<qq<<": "<<"RICHARD\n";
		else if(x==1||x==2)
		{
			cout<<"Case #"<<qq<<": "<<"GABRIEL\n";
		}
		else if(x==3)
		{
			if(min(r,c)==1)
				cout<<"Case #"<<qq<<": "<<"RICHARD\n";
			else
				cout<<"Case #"<<qq<<": "<<"GABRIEL\n";
		}
		else if(x==4)
		{
			if(min(r,c)<3)
				cout<<"Case #"<<qq<<": "<<"RICHARD\n";
			else
				cout<<"Case #"<<qq<<": "<<"GABRIEL\n";
		}
		else
		{
			if(min(r,c)<4)
				cout<<"Case #"<<qq<<": "<<"RICHARD\n";
			else
				cout<<"Case #"<<qq<<": "<<"GABRIEL\n";
		}
	
	}
	return 0;
}
