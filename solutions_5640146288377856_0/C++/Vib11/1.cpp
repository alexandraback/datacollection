/*This program is made on Vibhore's Machine.*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	 freopen("1.in", "r", stdin);
 	 freopen("1", "w", stdout);

	int a,b,c,d,n,t,r,w,i,j,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
		
		int count=0;
		cin>>r>>c>>w;
		int vib;
		if(c%w==0)
		vib=(r*(c/w))+w-1;
		else
		vib=(r*(c/w))+w;
		cout<<"Case #"<<(i+1)<<": "<<vib<<endl;
	}
	return 0;
}

