#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

char Buf[5000000];
int Ptr;

char* Words[1000000];
int Next[1000000];
int Node[11];
int nDict;

void ReadDict()
{
	memset(Node, -1, sizeof(Node));
	FILE* In = fopen("garbled_email_dictionary.txt", "r");
	Ptr = nDict = 0;
	int MaxLen = 0;
	while (fscanf(In, "%s", Buf + Ptr) != EOF)
	{
		int Len = strlen(Buf + Ptr);
		Words[nDict] = Buf + Ptr;
		Next[nDict] = Node[Len];
		Node[Len] = nDict ++;
		Ptr += Len + 1;
	}
	fclose(In);
}

char Str[5000];
int DP[5000][6];
int Diff[20], nDiff;

int Compare(char* W, char* S, int k, int& first, int& last)
{
	nDiff = 0;
	for (int i = 0; i < k; i ++)
		if (W[i] != S[i])
		{
			Diff[nDiff ++] = i;
			if (nDiff > k / 4 + 1)
				return -1;
		}
	sort(Diff, Diff + k);
	for (int i = 1; i < nDiff; i ++)
		if (Diff[i] - Diff[i - 1] < 5)
			return -1;
	if (nDiff == 0)
	{
		first = last = -1;
		return nDiff;
	}
	else
	{
		first = Diff[0];
		last = Diff[nDiff - 1];
		return nDiff;
	}
}

int Work()
{
	scanf("%s", Str);
	memset(DP, 10, sizeof(DP));
	int Inf = DP[0][0];
	DP[0][0] = 0;
	int Len = strlen(Str);
	for (int i = 0; i <= Len; i ++) // [0, i - 1]
	{
		{
//			if (DP[i][j] == Inf)
//				continue;
			for (int k = 1; k <= 10 && i + k <= Len; k ++)
			{
				for (int r = Node[k]; r != -1; r = Next[r])
				{
					if (r == 121952)
					{
						//printf("%d\n", r);
					}
					int first, last;
					int Res = Compare(Words[r], Str + i, k, first, last);
					if (Res == -1)
						continue;
					for (int j = 0; j < 5; j ++)
					if (Res == 0 || j <= first)
					{
						int Forbid;
						if (Res == 0)
							Forbid = max(j - k, 0);
						else
							Forbid = max(4 - (k - last), 0);
						if (DP[i][j] + Res < DP[i + k][Forbid])
							DP[i + k][Forbid] = DP[i][j] + Res;
					}
				}
			}
		}
	}
	int Ans = Inf;
	for (int j = 0; j < 5; j ++)
		Ans = min(Ans, DP[Len][j]);
	return Ans;
}

int main()
{
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	ReadDict();

	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d: %d\n", Case, Work());
		fflush(stdout);
	}
	return 0;
}