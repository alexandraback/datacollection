#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 15

using namespace std;

int GetLen (int num)
{
	int res = 0;
	while (num)
	{
		res++;
		num /= 10;
	}
	return res;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int q[MAXN];
	int qc;
	for (iT = 0; iT < T; iT++)
	{
		int res = 0;
		int A, B;
		scanf("%d %d",&A,&B);
		int i, j, k;
		for (i = A; i <= B; i++)
		{
			int len = GetLen(i);
			int add = 1;
			for (j = 0; j < len-1; j++) add *= 10;
			qc = 0;
			for (j = 0; j < len; j++)
			{
				k = i % 10;
				i /= 10;
				i += k * add;
				if (j == (len-1)) break;
				q[qc] = i;
				qc++;
			}
			if (qc)
			{
				sort(&(q[0]),&(q[qc-1]));
				//printf("%d:",i);
				for (j = 0; j < qc; j++)
				{
					if (((j == 0) || (q[j] != q[j-1])) && (q[j] >= add) && (q[j] > i) && (q[j] <= B)) res++;
					//printf(" %d",q[j]);
				}
				//printf("\n");
			}
		}
		printf("Case #%d: %d\n",iT+1,res);
	}
}
