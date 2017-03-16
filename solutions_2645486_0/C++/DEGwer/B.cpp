#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int main()
{
	int test;
	FILE *fr=fopen("B-small-attempt2.in","r");
	FILE *fw=fopen("out2.txt","w");
	fscanf(fr,"%d",&test);
	for(int p=0;p<test;p++)
	{
		ll gen,kai,num;
		fscanf(fr,"%lld%lld%lld",&gen,&kai,&num);
		vector<pii>vec;
		vector<ll>dat;
		for(int i=0;i<num;i++)
		{
			int zan;
			fscanf(fr,"%d",&zan);
			dat.push_back(zan);
			vec.push_back(make_pair(zan,i));
		}
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		ll now[10000];
		ll low[10000];
		fill(now,now+10000,gen);
		fill(low,low+10000,0);
		ll ans=0;
		for(int i=0;i<num;i++)
		{
			ans+=vec[i].first*(now[vec[i].second]-low[vec[i].second]);
			ll use=now[vec[i].second]-low[vec[i].second];
			for(int j=vec[i].second+1;j<vec.size();j++)
			{
				if(now[j]<=low[vec[i].second]+kai*(j-vec[i].second))
				{
					break;
				}
				now[j]=min(gen,low[vec[i].second]+kai*(j-vec[i].second));
				if(now[j]==gen)
				{
					break;
				}
			}
			for(int j=vec[i].second-1;j>=0;j--)
			{
				if(low[j]>=now[vec[i].second]-kai*(vec[i].second-j))
				{
					break;
				}
				low[j]=max(0LL,now[vec[i].second]-kai*(vec[i].second-j));
				if(low[j]==0)
				{
					break;
				}
			}
			now[vec[i].second]=low[vec[i].second];/*
			for(int j=0;j<vec.size();j++)
			{
				printf("%lld %lld  ",low[j],now[j]);
			}
			printf("\n");*/
		}
		fprintf(fw,"Case #%d: %lld\n",p+1,ans);
	}
}