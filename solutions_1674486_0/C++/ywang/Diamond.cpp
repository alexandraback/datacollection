#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int Max = 1010;
int Inf[Max];
int E[Max][12];
int EN[Max];
/*
struct mpair
{
	int x,y;
	const operator < (const mpair&t)const
	{
		if(inf < t.inf)
	}
};
*/
int queue[Max];
int qs=0;
void qpush(int id)
{
	queue[qs]=id;
	++qs;
}
int qpop()
{
	--qs;
	return queue[qs];
}
set<int> src[Max];
//mpai E[Max];
int main()
{
	int T;
	int TC=0;
	scanf("%d",&T);
	while(T--)
	{
		++TC;
		int N;
		scanf("%d",&N);
		for(int i=0;i<=N;++i)
			Inf[i]=0;
		for(int i=0;i<=N;++i)
			src[i].clear();
		for(int i=1;i<=N;++i)
		{
			int M;
			scanf("%d",&M);
			EN[i] = M;
			for(int j=0;j<M;++j)
			{
				scanf("%d",&E[i][j]);
				++Inf[E[i][j]];
			}
		}
		for(int i=1;i<=N;++i)
		{
			if(Inf[i]==0)
			{
				qpush(i);
				src[i].insert(i);
			}
		}
		bool ans =false;
		while(qs>0)
		{
			int id = qpop();
			for(int i=0;i<EN[id];++i)
			{
				int t = E[id][i];
				for(set<int>::const_iterator itr = src[id].begin();itr!=src[id].end();++itr)
				{
					if(src[t].find(*itr)!=src[t].end())
					{
						ans=  true;
						break;
					}
					src[t].insert(*itr);
				}
				--Inf[t];
				if(Inf[t]==0)
					qpush(t);
				if(ans)
					break;
			}
			if(ans)
				break;
		}
		if(ans)
			cout << "Case #"<<TC<<": Yes"<<endl;
		else
			cout << "Case #"<<TC<<": No"<<endl;
	}
	return 0;
}
