#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

int A[1005];
bool vis[1005];
int make[1005];
bool tr[1005];
int last[1005][2];
pair<int, int> B[1005];

bool comp(const pair<int, int> &A, const pair<int, int> &B)
{
	return A.second < B.second;
}

int main()
{
	int T, F[1005], i, N, count, c = 0, n, sum, j, b, flag;

	scanf("%d", &T);

	while(T--)
	{
		c++;
		scanf("%d", &N);

		for(i = 1; i <= N; i++)
		{
			tr[i] = 0;
			last[i][0] = last[i][1] = 0;
			vis[i] = 0;
			A[i] = 0;
			scanf("%d", &b);
			F[i] = b;
		}
		// printf("3, %d\n", N);

		for(i = 1; i <= N; i++)
		{
			// printf("2, %d\n", i);
			if(A[i] > 0)
			{
				continue;
			}
			j = i;
			count = 1;
			vis[i] = true;

			while(vis[F[j]] == false)
			{
				count++;
				j = F[j];
				vis[j] = true;
			}
			// printf("1, %d %d\n", i, count);
			if(F[F[j]] == j)
			{
				last[i][1] = j;
				last[i][0] = F[j];
				A[i] = -count;
			}
			else if(F[j] == i)
			{
				A[i] = count;
			}
			for(j = 1; j <= N; j++)
			{
				vis[j] = false;
			}
		}
		for(i = 1; i <= N; i++)
		{
			if(A[i] < 0)
			{
				j = F[i];
				while(j != i && A[j] < 0)
				{
					A[j] = 0;
					j = F[j];
				}
			}
		}
		for(i = 1; i <= N; i++)
		{
			// printf("1, %d=%d\n", i, A[i]);
			// printf("3, %d %d\n", last[i][0], last[i][1]);
			B[i] = make_pair(i, A[i]);
		}
		sort(B + 1, B + N + 1, comp);
		sum = 0;
		for(i = 1; i <= N; i++)
		{
			if(B[i].second >= 0)
			{
				break;
			}
			for(j = 1; j <= N; j++)
			{
				if(B[j].second >= 0)
				{
					break;
				}
				// printf("4, %d %d\n", B[i].first, B[j].first);
				if(last[B[i].first][0] == last[B[j].first][1] && last[B[i].first][1] == last[B[j].first][0])
				{
					make[B[i].first] = A[B[i].first] + A[B[j].first] + 2;
					break;
				}
			}
			if(B[j].second >= 0)
			{
				make[B[i].first] = B[i].second;
			}
			// printf("2, %d %d\n", B[i].first, make[B[i].first]);
		}
		for(i = 1; i <= N; i++)
		{
			if(B[i].second >= 0)
			{
				break;
			}
			j = B[i].first;
			if(tr[B[i].first])
			{
				continue;
			}
			flag = 0;
			vis[B[i].first] = 0;
			while(vis[F[j]] == false)
			{
				vis[F[j]] = true;
				j = F[j];
				if(tr[j] == true)
				{
					flag = 1;
					break;
				}
			}
			for(j = 1; j <= N; j++)
			{
				vis[j] = false;
			}
			if(flag == 1)
			{
				continue;
			}
			tr[B[i].first] = true;
			j = B[i].first;
			while(tr[F[j]] == false)
			{
				tr[F[j]] = true;
				j = F[j];
			}
			sum += -make[B[i].first];
		}
		for(i = 1; i <= N; i++)
		{
			if(A[i] > sum)
			{
				sum = A[i];
			}
		}
		printf("Case #%d: %d\n", c, sum);
	}
	return 0;
}