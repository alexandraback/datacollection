// GCC (c++ 4.3.2)
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int recycle(char s[10],long);
long a,b;
int main()
{	char strn[10];
	int t,i=1;
	long j,k,cnt;
	cin>>t;
	while(i<=t)
	{	
		cin>>a>>b;
		cnt=0;
		for(j=a;j<b;j++)
		{	ltoa(j,strn,10);
			cnt+=recycle(strn,j);
		}
		cout<<"Case #"<<i<<": "<<cnt<<endl;
		i++;
	}
	return 0;
}
int recycle(char str[10],long q)
{	int c=0;
	int i,l,j,flag;
	for(l=0;str[l];l++);
	char tmp;
	long x;
	char set[10][10];
	for(i=0;i<(l-1);i++)
	{	
		tmp=str[0];
		for(j=0;str[j]!='\0';j++)
			str[j]=str[j+1];
		str[l-1]=tmp;
		strcpy(set[i],str);
		flag=0;
		for(j=0;j<i;j++)
		{	if(!strcmp(set[j],str))
			{	flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		x=atol(str);
		if(x>=a && x<=b && x>q)
			c++;
		
	}
	return c;
}