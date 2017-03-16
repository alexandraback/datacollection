#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<string> Ret[50][50][2500];

int A[50][50], B[50][50], C[50][50];

int N, M, X, T;
int Flag;

void Open(int l1, int l2)
{
	if(l1 < 0 || l2 < 0 || l1 >= N || l2 >= M) return;
	if(C[l1][l2] == 0) return;
	C[l1][l2] = 0;
	if(B[l1][l2] == 0)
	{
		Open(l1-1, l2-1);
		Open(l1-1, l2);
		Open(l1-1, l2+1);
		Open(l1, l2-1);
		Open(l1, l2+1);
		Open(l1+1, l2-1);
		Open(l1+1, l2);
		Open(l1+1, l2+1);
	}
}

void Go(void)
{
	int l1, l2, l3, l4;

	for(l1 = 0; l1 < N; l1++) for(l2 = 0; l2 < M; l2++)
	{
		if(A[l1][l2] == 1) B[l1][l2] = -1;
		else
		{
			B[l1][l2] = 0;
			for(l3 = l1-1; l3 <= l1+1; l3++) for(l4 = l2-1; l4 <= l2+1; l4++)
			{
				if(l1 == l3 && l2 == l4) continue;
				if(l3 < 0 || l3 >= N || l4 < 0 || l4 >= M) continue;
				if(A[l3][l4]) B[l1][l2]++;
			}
		}
	}

	for(l1 = 0; l1 < N; l1++) for(l2 = 0; l2 < M; l2++) C[l1][l2] = 1;
	l3 = -1; l4 = -1;
	for(l1 = 0; l1 < N; l1++) for(l2 = 0; l2 < M; l2++) if(B[l1][l2] > 0)
	{
		l3 = l1;
		l4 = l2;
	}
	for(l1 = 0; l1 < N; l1++) for(l2 = 0; l2 < M; l2++) if(B[l1][l2] == 0)
	{
		l3 = l1;
		l4 = l2;
	}
	Open(l3, l4);
	for(l1 = 0; l1 < N; l1++) for(l2 = 0; l2 < M; l2++)
	{
		if(B[l1][l2] != -1 && C[l1][l2] == 1)
		{
			return;
		}
	}
	Flag = 1;
	Ret[N-1][M-1][X].clear();
	for(l1 = 0; l1 < N; l1++)
	{
		string str = "";
		for(l2 = 0; l2 < M; l2++)
		{
			if(A[l1][l2] == 0) str += ".";
			else str += "*";
		}
		Ret[N-1][M-1][X].push_back(str);
	}
	Ret[N-1][M-1][X][l3][l4] = 'c';
}

void Rec(int row, int prev, int left)
{
	if(Flag) return;
	if(left < 0) return;
	if(left > (row+1)*prev) return;
	if(row == -1)
	{
		Go();
	}
	else
	{
		int curr;
		for(curr = 1; curr <= prev; curr++)
		{
			A[row][M-curr] = 1;
		}
		for(curr = prev; curr > 0; curr--)
		{
			Rec(row-1, curr, left-curr);
			A[row][M-curr] = 0;
		}
		Rec(row-1, 0, left);
	}
}

int main(void)
{
	int l0, l1;

	for(N = 1; N <= 50; N++)
	{
		fprintf(stderr, "..%d\n", N);
		for(M = 1; M <= 50; M++)
		{
			for(X = 0; X < N*M; X++)
			{
				Flag = 0;
				Rec(N-1, M, X);
				if(Flag == 0)
				{
					Ret[N-1][M-1][X].push_back("Impossible");
				}
			}
		}
	}

	fprintf(stderr, "OK!\n");

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%d %d %d", &N, &M, &X);
		printf("Case #%d:\n", l0);
		N--; M--;
		for(l1 = 0; l1 < Ret[N][M][X].size(); l1++)
		{
			printf("%s\n", Ret[N][M][X][l1].c_str());
		}
		fflush(stdout);
	}
}
