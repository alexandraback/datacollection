// GCJ2012Qual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stdio.h"

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N,S,p;
		cin>>N>>S>>p;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int a;
			cin>>a;
			if(a%3==1)
			{
				if((a+2)/3>=p)
					ans++;
			}
			else
			{
				int score=a/3;
				if(a%3) score++;
				if(score>=p)
					ans++;
				else if(S>0 && score>0 && score+1>=p)
				{
					S--;
					ans++;
				}
			}
		}
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}