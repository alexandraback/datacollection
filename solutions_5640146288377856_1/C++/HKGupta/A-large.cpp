#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int R,C,W;
		cin>>R>>C>>W;
		int ct=0;
		ct=(C/W)*(R-1);
		while(C-W>=W)
		{
			ct++;
			C-=W;
		}	
		if(C>W)
			ct+=1+W;
		else
			ct+=W;


		cout<<"Case #"<<i+1<<": "<<ct<<"\n";	
	}


	return 0;
}