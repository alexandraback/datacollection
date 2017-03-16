#include<iostream>
#include<cstdio>
#include<set>
#include<map>

using namespace std;

int main()
{
	int T;
	scanf("%d ", &T);
	for(int t=1; t<=T; t++)
	{
		int N, n;
		int F[1000];
		int I[1000];
		int max = 0;
		typedef map< pair<int,int>, int> MyType;
		MyType m;

		scanf("%d ", &N);
		for(n=0;n<N;n++)
		{
			I[n] = 0;
			scanf("%d ", &F[n]);
			F[n]--;
		}
		for(n=0;n<N;n++)
		{
			if(I[n])
				continue;
			set<int> g;
			int i = 1;
			int next = n;
			while(g.find(next) == g.end())
			{
				g.insert(next);
				I[next] = i++;
				next = F[next];
			}
			int len = i-I[next];
			if(len == 2)
			{
				int a,b;
				a = next;
				b = F[next];
				MyType::iterator it = m.find( pair<int,int>(a,b) );
				if(it == m.end())
				{
					m[pair<int,int>(a,b)] = i-1;
				}
				else if(it->second < i)
					it->second = i-1;
			}
			else if(len > max)
				max = len;
		}
		int sum = 0;
		for(MyType::iterator it = m.begin(); it != m.end(); it++)
		{
			sum += it->second;
			if( it->first.first < it->first.second &&
				m.find(pair<int,int>(it->first.second, it->first.first)) != m.end())
				sum-=2;
		}
		if(sum > max)
			max = sum;
		cout<<"Case #"<<t<<": "<<max<<endl;
	}
	return 0;
}
