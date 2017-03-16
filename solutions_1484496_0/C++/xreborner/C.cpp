#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable: 4018)
#ifdef NDEBUG
	#define _SECURE_SCL 0
#endif
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

const int Mid = 2500000;
const int Len = 2000000;

int NN, TT;
int N;
int P[20];
bool Marks[21][5000000];
vector<int> A, B;

void find_it(int Pos, int Val)
{
	if (Pos == 0) return;
	if (!A.empty() || !B.empty()) Marks[Pos - 1][Mid] = true;
	if (Marks[Pos - 1][Val]) return find_it(Pos - 1, Val);
	if (Marks[Pos - 1][Val - P[Pos - 1]])
	{
		A.push_back(P[Pos - 1]);
		return find_it(Pos - 1, Val - P[Pos - 1]);
	}
	if (Marks[Pos - 1][Val + P[Pos - 1]])
	{
		B.push_back(P[Pos - 1]);
		return find_it(Pos - 1, Val + P[Pos - 1]);
	}
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> N;
		for (int I = 0; I < N; I++) cin >> P[I];
		memset(Marks, 0, sizeof(Marks));
		for (int I = 0; I < N; I++)
		{
			bool Save = Marks[I][Mid];
			Marks[I][Mid] = true;
			for (int J = Mid - Len; J <= Mid + Len; J++)
				Marks[I + 1][J] = Marks[I][J] | Marks[I][J - P[I]] | Marks[I][J + P[I]];
			Marks[I][Mid] = Save;
			int J = Mid;
			Marks[I + 1][J] = Marks[I][J] | Marks[I][J - P[I]] | Marks[I][J + P[I]];
		}
		printf("Case #%d:\n", TT);
		if (!Marks[N][Mid])
			printf("Impossible\n");
		else
		{
			A.clear();
			B.clear();
			find_it(N, Mid);
			for (int I = 0; I < A.size(); I++) printf("%d ", A[I]);
			printf("\n");
			for (int I = 0; I < B.size(); I++) printf("%d ", B[I]);
			printf("\n");
		}
	}
	return 0;
}
