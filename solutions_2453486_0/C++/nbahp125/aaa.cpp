#include "stdafx.h"

#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<fstream>
using namespace std;
int main()
{
	int t,n,m,i,j;
	cin>>t;
	getchar();
	int a[16];
	int b[10]={0,4,8,12,0,1,2,3,0,3};
	int c[10]={1,1,1,1,4,4,4,4,5,3};
	ofstream file;
	file.open("d:\\aa.txt");
	for(int times=1;times<=t;times++)
	{
		bool existempty = 0;
		file<<"Case #"<<times<<": ";
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				char ch=getchar();
				if(ch=='X')
					a[i*4+j]=1;
				else if(ch=='O')
					a[i*4+j]=-1;
				else if(ch=='T')
					a[i*4+j]=0;
				else{
					existempty=1;
					a[i*4+j]=1000;
				}
			}
			getchar();
		}
		getchar();

			bool found=0;
			for(i=0;i<10;i++)
			{
				int s=a[b[i]];
				for(j=1;j<=3;j++)
					s+=a[b[i]+c[i]*j];
				if(s==4||s==3){
					file<<"X won"<<endl;
					found=1;
					break;
				}
				else if(s==-4||s==-3)
				{
					file<<"O won"<<endl;
					found=1;
					break;
				}
			}
			if(!found){
				if(existempty)
					file<<"Game has not completed"<<endl;
				else
					file<<"Draw"<<endl;
			}	

	}
	return 0;
}