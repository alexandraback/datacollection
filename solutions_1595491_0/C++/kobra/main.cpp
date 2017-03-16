#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int Dyn[200][200];

bool possibleToMakeStrange(int N)
{
	if(N >= 2 && N <= 28)
		return true;
	else
		return false;
}

bool possibleToGetGreaterStrange(int N, int P)
{
	if(!possibleToMakeStrange(N))
		return false;

	int maximum = 0;
	if(N%3 == 2)
		maximum = N / 3 + 2;
	else
		maximum = N / 3 + 1;
	if(maximum >= P)
		return true;
	else 
		return false;
}

bool possibleToGetGreaterNotStrange(int N, int P)
{
	int maximum = 0;
	if(N%3 == 0)
		maximum = N / 3;
	else
		maximum = N / 3 + 1;
	if(maximum >= P)
		return true;
	else 
		return false;
}

int N,S,P;
int Ar[3];

int rec(int current,int left)
{
	if(current == N && left == 0)
		return 0;
	else if(current == N)
		return -100;
	else if(left < 0)
		return -100;

	bool flag1 = false, flag2 = false, flag3 = false;
	for(int i = 0; i <= 10; i++)
		for(int j = 0; j <= 10; j++)
			for(int k = 0; k <= 10; k++)
				if(i + j + k != Ar[current])
					continue;
				else
				{
					if((abs(i-j) < 2) && (abs(j-k) < 2) && (abs(i-k) < 2) && (i >= P || j >= P || k >= P))
						flag1 = true;
					else if ((i >= P || j >= P || k >= P))
						flag2 = true;
					if((abs(i-j) < 2) && (abs(j-k) < 2) && (abs(i-k) < 2))
						flag3 = true;
				}
	int res1 = rec(current+1,left);
	int res2 = rec(current+1,left-1);
	if(flag1)
		res1++;
	if(flag2)
		res2++;
	if(flag2 || flag3)
		return max(res1,res2);
	else
		return res1;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z = 1; z <= T; z++)
	{
		memset(Dyn,-1,sizeof(Dyn));
		scanf("%d%d%d",&N,&S,&P);
		Dyn[0][0] = 0;
		for(int i = 0; i < N; i++)
		{
			int a;
			scanf("%d",&a);
			//Ar[i] = a;
			for(int j = 0; j <= S; j++)
			{
				if(Dyn[i][j]==-1)
					continue;
				if(possibleToGetGreaterStrange(a,P))
					Dyn[i+1][j+1] = max(Dyn[i][j] + 1, Dyn[i+1][j+1]);
				else if(possibleToMakeStrange(a))
					Dyn[i+1][j+1] = max(Dyn[i][j], Dyn[i+1][j+1]);

				if(possibleToGetGreaterNotStrange(a,P))
					Dyn[i+1][j] = max(Dyn[i][j] + 1, Dyn[i+1][j]);
				else
					Dyn[i+1][j] = max(Dyn[i][j], Dyn[i+1][j]);
			}
		}
		printf("Case #%d: %d\n",z,Dyn[N][S]);
		//printf("Case #%d: %d\n",z,rec(0,S));
	}
	return 0;
}