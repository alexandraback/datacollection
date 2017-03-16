#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t,num=1;
	cin>>t;
	while(t--)
	{
		int a,b,k,counter=0;
		cin>>a>>b>>k;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				if((i&j)<k)counter++;
			}
		}
		cout<<"Case #"<<num++<<": "<<counter<<endl;
	}
}
