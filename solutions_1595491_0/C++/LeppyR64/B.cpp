#include <cstdio>
using namespace std;

int surpval(int n)
{
	int ma,mb,mc=-1;
	for(int a = 0; a <= n; a++)
		for(int b = a; b <= n; b++)
			for(int c = b; c <= a+2; c++)
				if(a+b+c==n && c > mc)
				{
					ma = a;
					mb = b;
					mc = c;
				}
	//printf("S%d = %d %d %d\n", n,ma, mb, mc);
	return mc;
}

int nonsurpval(int n)
{
	int ma,mb,mc=-1;
	for(int a = 0; a <= n; a++)
		for(int b = a; b <= n; b++)
			for(int c = b; c <= a+1; c++)
				if(a+b+c==n && c > mc)
				{
					ma = a;
					mb = b;
					mc = c;
				}
	//printf("N%d = %d %d %d\n", n,ma, mb, mc);
	return mc;
}


int main()
{
	// for(int i = 0; i <= 30; i++)
	// {
		// nonsurpval(i);
		// surpval(i);
	// }
	// return 0;
	
	int tc;
	int N,S,P,T[100],SV[100],NV[100];
	scanf("%d", &tc);
	for(int z = 1; z <= tc; z++)
	{
		int result = 0;
		scanf("%d %d %d", &N, &S, &P);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &T[i]);
			SV[i] = surpval(T[i]);
			NV[i] = nonsurpval(T[i]);
			if(NV[i] >= P)
				result++;
			else if(SV[i] >= P && S > 0)
			{
				S--;
				result++;
			}
			//printf("%d = %d %d\n", T[i], NV[i], SV[i]);
		}
		printf("Case #%d: %d\n", z, result);
	}
}
