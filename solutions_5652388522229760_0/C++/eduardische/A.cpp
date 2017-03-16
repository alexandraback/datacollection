#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main ()
{
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++)
	{
		long long N;
		scanf("%lli",&N);
		printf("Case #%d: ",iT+1);
		if (N == 0) printf("INSOMNIA\n");
		else
		{
			char b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			long long num = 0;
			while (1)
			{
				num += N;
				long long i = num;
				while (i > 0LL)
				{
					b[(int)(i % 10LL)] = 1;
					i /= 10LL;
				}
				i = 0;
				while ((i < 10) && (b[i] == 1)) i++;
				if (i == 10)
				{
					printf("%lli\n",num);
					break;
				}
			}
		}
	}
	return 0;
}
