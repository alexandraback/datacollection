#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int S[100],Sum[100000*30];

void Print(int Ans,int N,int S[])
{
	bool F=true;
	for (int i=1;i<=N;++i)
		if ((Ans>>(i-1))&1)
		{
			if (!F)	printf(" ");
			F=false;
			printf("%d",S[i]);
		}
	printf("\n");
}

void Solve()
{

	int N;
	bool FindAns=false;
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
		scanf("%d",&S[i]);
	memset(Sum,0,sizeof(Sum));
	for (int x=0;x<(1<<N)&&!FindAns;++x)
	{
		int tmp=0;
		for (int i=1;i<=N;++i)
			if ((x>>(i-1))&1)
				tmp+=S[i];
		if (Sum[tmp])
		{
			Print(Sum[tmp],N,S);
			Print(x,N,S);
			FindAns=true;
		}
		Sum[tmp]=x;
	}
	if (!FindAns)
		printf("Impossible\n");
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T=0;
	scanf("%d",&T);
	for (int i=1;i<=T;++i)
	{
		printf("Case #%d:\n",i);
		Solve();
	}
	return 0;
}
