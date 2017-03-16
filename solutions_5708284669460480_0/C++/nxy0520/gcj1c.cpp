// gcj1c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "string"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include "vector"
using namespace std;

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int K,L,S;
		cin>>K>>L>>S;
		string key;
		string target;
		cin>>key>>target;
		int best=0;
		for(int i=0;i<target.size();i++)
		{
			int isgood=1;
			for(int j=i;j<target.size();j++)
			{
				if(target[j]!=target[j-i])
				{
					isgood=0;
					break;
				}
			}
			if(isgood) best=i;
		}
		double prob[30]={};
		for(int i=0;i<key.size();i++)
		{
			prob[key[i]-'A']+=1.0/key.size();
		}
		int valid=1;
		for(int i=0;i<target.size();i++)
		{
			if(prob[target[i]-'A']<0.0001) valid=0;
		}
		if(!valid)
		{
			cout<<"Case #"<<tc+1<<": "<<0<<endl;
			continue;
		}
		double dp[105][105]={};
		dp[0][0]=1.0;
		double spent=0.0;
		for(int i=1;i<=S;i++)
		{
			double rest=1.0;
			for(int j=0;j<L;j++)
			{
				double p=prob[target[j]-'A'];
				dp[i][j+1]=dp[i-1][j]*p;
				rest-=dp[i][j+1];
				if(target[j]!=target[0])
				{
					double p1=prob[target[0]-'a'];
					dp[i][1]+=dp[i-1][j]*p1;
					rest-=dp[i][j+1];
				}
			}
			dp[i][0]=rest;
			spent+=dp[i][L];
			dp[i][best]+=dp[i][L];
		}
		int bring=0;
		int cur=0;
		for(int i=0;i<S;i++)
		{
			cur++;
			if(cur==L)
			{
				cur=best;
				bring++;
			}
		}
		cout<<"Case #"<<tc+1<<": ";
		printf("%.12lf\n",bring-spent);
		//cout<<bring<<" "<<spent<<endl;
	}
	return 0;
}

