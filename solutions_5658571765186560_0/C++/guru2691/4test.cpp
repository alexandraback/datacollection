#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int idx=1;idx<=T;idx++)
	{
		int X,R,C;
		cin>>X>>R>>C;
		if(R<C)
		swap(R,C);
		
		if(X==1)
		{
			cout<<"Case #"<<idx<<": "<<"GABRIEL"<<'\n';
		}
		else if(X==2)
		{
			if((R*C)%2 == 0)
			{
				cout<<"Case #"<<idx<<": "<<"GABRIEL"<<'\n';
			}
			else
			{
				cout<<"Case #"<<idx<<": "<<"RICHARD"<<'\n';
			}
		}
		else if(X==3)
		{
			if(R==4 and C==3)
			{
				cout<<"Case #"<<idx<<": "<<"GABRIEL"<<'\n';
			}
			else if(R==3 and (C==2 or C==3))
			{
				cout<<"Case #"<<idx<<": "<<"GABRIEL"<<'\n';
			}
			else
			{
				cout<<"Case #"<<idx<<": "<<"RICHARD"<<'\n';
			}
		}
		else
		{
			if(R==4 and (C==4 or C==3))
			{
				cout<<"Case #"<<idx<<": "<<"GABRIEL"<<'\n';
			}
			else
			{
				cout<<"Case #"<<idx<<": "<<"RICHARD"<<'\n';
			}
		}
	}
	return 0;
}





