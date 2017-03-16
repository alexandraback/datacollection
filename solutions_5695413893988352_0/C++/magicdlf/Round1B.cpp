// Round1B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string.h"
#include "string"
#include "algorithm"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		string a,b;
		cin>>a>>b;
		int n=a.size();
		int flag=0; // -1 a>b  0 a=b  1 a<b
		for(int i=0;i<n;i++)
		{
			if(a[i]=='?' && b[i]=='?')
			{
				if(flag==0) { a[i]='0'; b[i]='0';}
				else if(flag>0) { a[i]='9'; b[i]='0'; }
				else {a[i]='0'; b[i]='9'; }
			}
			else if(a[i]=='?')
			{
				if(flag==0) { a[i]=b[i]; }
				else if(flag>0) { a[i]='9'; }
				else { a[i]='0'; }
			}
			else if(b[i]=='?')
			{
				if(flag==0) { b[i]=a[i]; }
				else if(flag<0) { b[i]='9'; }
				else { b[i]='0'; }
			}
			else
			{
				if(flag==0)
				{
					if(a[i]>b[i]) flag=-1;
					if(a[i]<b[i]) flag=1;
				}
			}
		}
		cout<<"Case #"<<tc+1<<": "<<a<<" "<<b<<endl;
	}
	return 0;
}