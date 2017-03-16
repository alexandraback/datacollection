#include <bits/stdc++.h>
using namespace std;
int N;
typedef pair<int, int> Pii;
char ina[30];
char inb[30];
int Dupa[30];
int Dupb[30];
void solver()
{
	scanf("%d", &N);
	map<string, int> Ma;
	map<string, int> Mb;
	Pii Tab[30];
	for(int i = 0; i < N; ++i)
	{
		scanf("%s%s", ina, inb);
		string a = ina;
		string b = inb;
		if(Ma.find(a) == Ma.end())
			Ma[a] = Ma.size()-1;
		if(Mb.find(b) == Mb.end())
			Mb[b] = Mb.size()-1;
		Tab[i] = Pii(Ma[a], Mb[b]);
	}
	int limit = (1 << (N+1)) + 100;
	int mfakes = 0;
	for(int i = 0; i < limit; ++i)
	{
		for(int j = 0; j < Ma.size(); ++j)
			Dupa[j] = 0;
		for(int j = 0; j < Mb.size(); ++j)
			Dupb[j] = 0;
		for(int j = 0; j < N; ++j)
		{
			if(i & (1 << j))
			{
				Dupa[Tab[j].first] = 1;
				Dupb[Tab[j].second] = 1;
			}
		}
		bool b = true;
		for(int i = 0; i < Ma.size() && b; ++i)
			if(Dupa[i] == 0)
				b = false;
		for(int i = 0; i < Mb.size() && b; ++i)
			if(Dupb[i] == 0)
				b = false;
		if(b == true)
		{
			int fakes = 0;
			for(int j = 0; j < N; ++j)
				if((i & (1 << j)) == 0)
					++fakes;
			mfakes = max(mfakes, fakes);
		}
	}
	/*for(int i = 0; i < N; ++i)
		printf("Tab = %d %d\n", Tab[i].first, Tab[i].second);*/
	
	//printf("%d Ma %d Mb %d limit %d", mfakes, Ma.size(), Mb.size(), limit);
	printf("%d", mfakes);
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
	{
		printf("Case #%d: ", i);
		solver();
		puts("");
	}
	
	
	return 0;
}
