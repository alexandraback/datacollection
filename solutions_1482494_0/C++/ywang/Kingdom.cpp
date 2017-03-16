#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct sortb
{
	int a,b;
	int id;
	bool operator < (const sortb&t)const
	{
		if(b==t.b)
			return a<t.a;
		return b<t.b;
	}
};
//sortb sb[1010];
int a[1010];
int b[1010];
bool state[1010];
int main()
{
	int T;
	cin >> T;
	int id = 0;
	while(T--)
	{
		++id;
		int N;
		cin >> N;
		for(int i=0;i<N;++i)
			cin >> a[i] >> b[i];
		for(int i=0;i<N;++i)
		{
			/*
			sb[i].a = a[i];
			sb[i].b = b[i];
			*/
			state[i] = 0;
		}
//		sort(sb, sb+N);
		int la0 = 0,lb0 = 0;
		int la1 = -1,lb1 = -1;
		int cur = 0;int F = 2*N;
		int r=0;
		bool bad = false;
		while(cur<F)
		{
			bool succ = false;
			for(int i=0;i<N;++i)
			{
				if(state[i] || b[i]>cur)
					continue;
				cur += 2;
				state[i] = 2;
				++r;
				succ = true;
			}
			if(succ)
				continue;
			/*
			while(lb0<N && state[sb[lb0].id]!=0)
				++lb0;
			if(lb0<N)
			{
				if(sb[lb0].b<=cur)
				{
					cur += 2;
					state[sb[lb0].id] = 2;
					++lb0;
					++r;
					continue;
				}
			}
			*/
			succ = false;
			for(int i=0;i<N;++i)
			{
				if(state[i] != 1 || b[i]>cur)
					continue;
				++cur;
				state[i]=2;
				++r;
				succ = true;
			}
			if(succ)
				continue;

			int bestid=-1;
			for(int i=0;i<N;++i)
			{
				if(state[i] != 0 || a[i]>cur)
					continue;
				if(bestid<0 || b[i]>b[bestid])
					bestid = i;
			}
			if(bestid<0)
			{
				bad = true;
				break;
			}
			else
			{
				++cur;
				state[bestid]=1;
				++r;
			}
		}
		if(bad)
		{
			printf("Case #%d: Too Bad\n",id);
		}
		else
		{
			printf("Case #%d: %d\n",id,r);
		}
	}
	return 0;
}
