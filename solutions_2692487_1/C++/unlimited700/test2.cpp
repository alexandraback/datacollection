#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<new>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
char str[300],ch;
long long int mo[100005];
int main()
{
	long long int size,k,i=1,t,flag=0,n,a,j;
	char ch,s;
	//cout<<sizeof(a)<<i;
	//scanf("%d",&t);
	ifstream p("p.txt");
	ofstream o("pra.txt");
	p>>t;
	//p.get(ch);
	for(k=1;k<=t;k++)
	{
		p>>a>>n;size=a;
		for(i=0;i<n;i++)
		{
			p>>mo[i];
		}
		sort(mo,mo+n);
		long long int count=0,c=n;
		
		for(i=0;i<n;i++)
		{
			if(a==1) break;
			if(mo[i]<a)
			{
				a+=mo[i];
			}
			else if(i+1==n)
			{
				
				count++;
				if((count+n-1-i)<c) c=count+n-1-i;
			}
			else
			{
				
				count++;
				if((count+n-1-i)<c) c=count+n-1-i;
				a=a+a-1;i--;
			}
			//cout<<a<<endl;
		}
		if(c<count) count=c;
		//p.getline(str,300);
		o<<"Case #"<<k<<": ";
		if(a==1) o<<n<<endl;
		else if(count>n) o<<n<<endl;
		else
			o<<count<<endl;
	}
	p.close();
	o.close();
	return 0;
}

