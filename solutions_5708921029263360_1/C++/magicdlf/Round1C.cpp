// Round1C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "string.h"
#include "stdio.h"
using namespace std;


void solve(int tc)
{
	int JP[15][15]={};
	int JS[15][15]={};
	int PS[15][15]={};
	int JPS[15][15][15]={};
	int J,P,S,K;
	cin>>J>>P>>S>>K;
	int ans[1005][3]={};
	int day=0;
	for(int o=0;o<10;o++)
	{
		for(int j=0;j<J;j++)
		{
			for(int p=0;p<P;p++)
			{
				int s=p+j+o;
				if(JP[j%J][p%P]<K && PS[p%P][s%S]<K && JS[j%J][s%S]<K && JPS[j%J][p%P][s%S]==0)
				{
					JP[j%J][p%P]++;
					PS[p%P][s%S]++;
					JS[j%J][s%S]++;
					JPS[j%J][p%P][s%S]=1;
					ans[day][0]=j%J+1;
					ans[day][1]=p%P+1;
					ans[day][2]=s%S+1;
					day++;
				}
			}
		}
	}
	cout<<"Case #"<<tc+1<<": "<<day<<endl;
	for(int i=0;i<day;i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
	}
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		solve(tc);
	}
	return 0;
}