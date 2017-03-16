#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z = 1; z <= T; z++)
	{
		int A,B;
		int result = 0;
		scanf("%d%d",&A,&B);
		int copy = A;
		int tenth = 1;
		int len = 0;
		while(copy != 0)
		{
			len++;
			copy /= 10;
			tenth *= 10;
		}
		tenth /= 10;
		
		for(int i = A; i <= B; i++)
		{
			set<int> Pairs;
			int N = i;
			int M = i;
			for(int j = 1; j < len; j++)
			{
				int digit = M % 10;
				M /= 10;
				M += digit * tenth;
				if(M > N && M <= B && M >= A)
				{
					//printf("%d %d\n", N, M);
					Pairs.insert(M);
				}
			}
			result += Pairs.size();
		}
		printf("Case #%d: %d\n",z,result);
	}
	return 0;
}
