#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<iostream>
#include<cmath>
using namespace std;
long long mod = 1000000007;
map<pair<int,int>,int > mp1;
map<pair<int,int>,int > mp2;
map<pair<int,int>,int > mp3;
struct st
{
	int a,b,c;
};
vector<st> v;
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		v.clear();
		mp1.clear();
		mp3.clear();
		mp2.clear();
		printf("Case #%d: ",tc);
		int J,P,S,K; cin>>J>>P>>S>>K;
		for(int i=1;i<=J;i++)
		{
			for(int j=1;j<=P;j++)
			{
				for(int k=1;k<=S;k++)
				{
					pair<int,int> p1,p2,p3;
					p1 = make_pair(i,j);
					p2 = make_pair(j,k);
					p3 = make_pair(i,k);
					if(mp1[p1]<K && mp2[p2]<K && mp3[p3]<K)
					{
						mp1[p1] ++; mp3[p3]++; mp2[p2]++;
						st s; s.a = i; s.b= j; s.c = k;
						v.push_back(s);				
					}
					
					
				}
			}
		}
		printf("%d\n",v.size());
		for(int i= 0;i<v.size();i++)
		{
			printf("%d %d %d\n",v[i].a,v[i].b,v[i].c);
		}
	}
} 

