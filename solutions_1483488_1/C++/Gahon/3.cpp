#include<iostream>
#include<fstream>
#include<algorithm>
#include <stdlib.h>
#include<string>
using namespace std;
long long ten[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
bool tash[9999999];
int main()
{

	ifstream in("C-large.in");
	ofstream out("C-large.out");
	long long  k,m,p,j,tt,t,i,a,b,l,maxa,n,lena,ans=0,tmp,y,com[100];
	in>>t;
	for (tt=1;tt<=t;tt++)
	{
		in>>a>>b;ans=0;
		for (i=a;i<=b;i++) tash[i]=false;
		for (lena=0;lena<=7;lena++)
			if (a<ten[lena]){break;}
		for (i=a;i<=b;i++)
		{
		if (tash[i]==false)
		{
			tmp=1;
			tash[i]=true;
			m=ten[lena-1];
			n=i;
			for (j=1;j<lena;j++)
			{
				n=(n%m)*10+n/m;
				tash[n]=true;
				if (n>=a&&n<=b&&n!=i) 
				{
					y=1;
					for (k=1;k<=tmp;k++)
						if (com[k]==n)
						{
							y=0;
							break;
						}
						if (y==1){tmp++;com[k]=n;}
					
				}
			}
			ans=ans+tmp*(tmp-1)/2;
			if (i==ten[lena]-1) lena++;
		}
		}
		out<<"Case #"<<tt<<": "<<ans<<endl;
	}
	in.close();
	out.close();
}