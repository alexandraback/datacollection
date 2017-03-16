#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main() 
{
	int t,i,a[100],n[30],mm,j1,len,k,nc,nj,conj[3],conc[3],l,minj,minc,min,flag,x;
	char ch,c[100],j[100];
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>c>>j;
		len=strlen(c);
		l=pow(10,len);
		flag=0;
		for(j1=0;j1<len;j1++)
		{
//			cout<<flag<<endl;
			if(flag == 0)
			{	
				if(c[j1]==63 && j[j1] == 63 )
				{
					c[j1]='0';
					j[j1]='0';
				}
				else
				{
					if(c[j1]!=63&&j[j1]!=63 )
					{
						if((c[j1]-j[j1])>5 && j1>0)
							{
								j[j1-1]='1';
							}
						else if((j[j1]-c[j1])>5 && j1>0)
							{
								c[j1-1]='1';
							}
					}
		//			cout<<"sdsa";
					flag=1;
					if(c[j1]==63)
						c[j1]=j[j1];
					else if(j[j1]==63)
						j[j1]=c[j1];
					mm=0;
					if(c[j1]>j[j1])
						mm=1;
					else if(c[j1]<j[j1])
						mm=2;
				}
			}
			else if(flag==1)
			{
				if(c[j1]==63 && j[j1] == 63 )
				{
					if(mm==0)
					{
						c[j1]='0';
						j[j1]='0';
					}
					else if(mm==1)
					{
						c[j1]='0';
						j[j1]='9';
					}
					else
					{
							j[j1]='0';
							c[j1]='9';
					}
				}
				else if(c[j1]==63 && j[j1] != 63 )
				{
					if(mm==0)
					{
					
						c[j1]=j[j1];
					}
					else if(mm==1)
					{
						c[j1]='0';
					//	j[j1]='9';
					}
					else
					{
					//		j[j1]='0';
							c[j1]='9';
					}
				}
				else if(c[j1]!=63 && j[j1] == 63 )
				{
						if(mm==0)
					{
					
						j[j1]=c[j1];
					}
					else if(mm==1)
					{
					//	c[j1]='0';
						j[j1]='9';
					}
					else
					{
							j[j1]='0';
					//		c[j1]='9';
					}
				}
				else
				{
					if(c[j1]>j[j1])
						mm=1;
					else if(c[j1]<j[j1])
						mm=2;
				}
			}
		}
		
		cout<<"Case #"<<i+1<<": "<<c<<" "<<j;
		cout<<endl;
	}
	return 0;
}
