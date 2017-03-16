#include <cstdio>
#include <vector>
using namespace std;

int T, A, B;

int numCif(int x)
{
	int cnt = 0;
	while (x) { cnt++; x /= 10;}
	return cnt;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	int i, j, k;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		int cnt = 0;
		
		scanf("%d %d", &A, &B);
		int N = numCif(A);
		for (i = A; i <= B; i++)
		{
			vector<int> v;
			int m10 = 1;
			int r10 = 1;
			for (j = 1; j <= N; j++) r10 *= 10;
			for (j = 1; j < N; j++)
			{				
				m10 *= 10;
				r10 /= 10;
				int newNum = ((i % r10) * m10) + (i / r10);
				int found = 0;
				for (k = 0; k < v.size(); k++) if (v[k] == newNum) found = 1;
				if (newNum > i && newNum <= B && !found) {
					v.push_back(newNum);
					cnt++;
				}
			}			
		}
		printf("%d\n", cnt);
	}
	return 0;
}