#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define iscons(c) (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))

int start, end;

char str[1000010];
int cons[1000010];
int cum[1000010];
queue<int> poss;
bool hasConsec(int start, int end, int N)
{
	return (end - poss.front() + 1) >= N;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N;
		scanf("%s %d", str, &N);
		int L = strlen(str);
		for (int i = 0; i < L; i++)
			cons[i] = iscons(str[i])?1:0;
		int c = 0;
		for (int i = 0; i < L; i++)
		{
			if (cons[i]) c++;
			else c = 0;
			if (c >= N)
			{
				poss.push(i-N+1);
			}
		}
		int end = 0;
		int total = 0;
		for (int start = 0; start < L; start++)
		{
			if (poss.empty()) break;
			while (end < L && !hasConsec(start, end, N)) end++;
			if (end >= L)break;
			total += (L-end);
			//printf("start = %d, end = %d, added %d\n", start, end, (L-end));
			if (poss.size() && poss.front() == start)
			{
				//printf("removed %d from poss\n", poss.front());
				poss.pop();
			}
		}
		printf("Case #%d: %d\n", t+1, total);
	}
}