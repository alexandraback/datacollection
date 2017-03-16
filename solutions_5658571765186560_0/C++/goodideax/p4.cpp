#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	int X,R,C;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int flag = 0;
		cin>>X>>R>>C;
		if(X==1) flag =1;
		if(X==2&&(R*C)%2==0&&R*C>=2) flag=1;
		if(X==3&&(R*C)%3==0&&R!=1&&C!=1)
			flag=1;
		if(X==4&&(R*C)%4==0&&R*C>=12&&R>2&&C>2)
			flag = 1;
		
		if(flag)
			cout<<"Case #"<<i+1<<": GABRIEL"<<endl;
		else
			cout<<"Case #"<<i+1<<": RICHARD"<<endl;
	}
	return 0;
}
