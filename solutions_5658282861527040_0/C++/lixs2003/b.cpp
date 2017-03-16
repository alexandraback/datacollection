#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
using namespace std;

int n1,i1,a,b,k,i,j,num;

int main()
{
		cin>>n1;
	
	for(i1=1;i1<=n1;i1++)
	{
		cin>>a>>b>>k;
		num=0;
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
			{
				if((i&j)<k)
					num++;
			}
		cout<<"Case #"<<i1<<": ";
		cout<<num<<endl;
	}
	
	return 0;
} 
