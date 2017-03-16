#include <iostream>
#include<cstring>
#include<cmath>
#include<stdio.h>
using namespace std;
int main() 
{
	int t,i,a[100],n[30],j1,len,k,nc,nj,conj[3],conc[3],l,minj,minc,min,flag,x;
	char ch,c[100],j[100];
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>c>>j;
		
	
		len=strlen(c);
		
		min=100000000;
	//	lenj=strlen(j);
		l=pow(10,len);
		for(nc=0;nc<l;nc++)
		{
			for(nj=0;nj<l;nj++)
			{
			//	if(nc!=10 || nj!=20)
			//		continue;
			//	cout<<nj<<" "<<nc<<endl;
				flag=0;
				for(j1=0;j1<len;j1++)
				{
						x=pow(10,len-1-j1);
						//cout<<x<<endl;
						if(j[j1]!=63 && (j[j1]-48) !=((((nj)/x)%10) ))
							flag=1;
					//	cout<<flag<<endl;
				}
				for(j1=0;j1<len;j1++)
				{
							x=pow(10,len-1-j1);
						if(c[j1]!=63 && (c[j1]-48)!=((((nc)/x)%10)))
							flag=1;
							
				}
				//
				if(flag==1)
					continue;
			//	cout<<nj<<" "<<nc<<endl;
				if(abs(nj-nc)<min)
				{
					min=abs(nj-nc);
					minj=nj;
					minc=nc;
				}
			}
		}
		
		cout<<"Case #"<<i+1<<": ";
		if(len==1)
		printf("%d %d",minc,minj);
			if(len==2)
		printf("%02d %02d",minc,minj);
			if(len==3)
		printf("%03d %03d",minc,minj);
		cout<<endl;
	}
	return 0;
}
