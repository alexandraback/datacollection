#include <iostream>
#include <cmath>
#include <string>
using namespace std;

typedef long long LINT;

int tbl[1000][1000];

void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		int x,y;
		cin>>x>>y;

		int sum=0;
		int i;
		for(i=1; i<100000; i++)
		{
			sum+=i;
			if(sum>=abs(x)+abs(y))
				break;
		}
		int dd=sum-(abs(x)+abs(y));
		if(dd%2==0)
			dd=dd/2;
		else
		{
			i+=1;
			dd=(sum+i-(abs(x)+abs(y)))/2;
		}

		int maxn=i;
		string str(maxn+1,'E');

		sum=0;
		for(i=maxn; i>0; i--)
		{
			if(i==dd)
				sum-=i;
			else 
				sum+=i;
			if(sum>=abs(y))
			{
				sum-=i;
				i++;
				break;
			}
		}
		for(int k=i; k<=maxn; k++)
			str[k]='N';
		
		str[dd]=(str[dd] == 'N' ? 'S' : 'W');

		int cc=abs(y)-sum;
		if(cc>0 && cc==dd)
		{
			str[cc-1]=str[cc+1]='N';
			str[dd]='S';
		}
		else
			str[cc]='N';
	
		for(i=0; i<str.length(); i++)
		{
			if(x<0)
			{
				if(str[i]=='W')
					str[i]='E';
				else if(str[i]=='E')
					str[i]='W';
			}
			if(y<0)
			{
				if(str[i]=='N')
					str[i]='S';
				else if(str[i]=='S')
					str[i]='N';
			}
		}

		cout<<"Case #"<<ii+1<<": "<<str.substr(1)<<endl;
	}
}