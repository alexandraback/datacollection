#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;

struct data 
{
	int s, msk;
	inline data(int s=0,int msk=0):s(s),msk(msk){};
};
bool operator < (const data&a, const data&b)
{
	return a.s < b.s;
}

vector<data> D;

int S[100], N;

void run()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i){
		scanf("%d", S+i);
	}
	D.clear();
	for(int msk=1;msk<(1<<N);++msk)
	{
		int t=0;
		for(int i=0;i<N;++i)
			if(msk & 1 << i)
				t+=S[i];
		D.push_back(data(t, msk));
	}
	sort(D.begin(), D.end());
	for(int i=1;i<D.size();++i)
		if(D[i].s==D[i-1].s)
		{
			bool flag=false;
			for(int j=0;j<N;++j)
				if(D[i-1].msk & 1 << j)
				{
					if(flag) putchar(' ');
					else flag=true;
					printf("%d", S[j]);
				}
			printf("\n");
			flag=false;
			for(int j=0;j<N;++j)
				if(D[i].msk & 1 << j)
				{
					if(flag) putchar(' ');
					else flag=true;
					printf("%d", S[j]);
				}
			printf("\n");
			return ;
		}
	printf("Impossible\n");
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int test;scanf("%d", &test);
	for(int no=1;no<=test;++no)
	{
		printf("Case #%d:\n",no);
		run();
	}
	return 0;
}