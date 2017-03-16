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

int NN, TT;
int N;
double Scores[1000], P[1000];
double Sum;

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> N;
		for (int I = 0; I < N; I++) cin >> Scores[I];
		Sum = 0;
		for (int I = 0; I < N; I++) Sum += Scores[I];
		for (int I = 0; I < N; I++) Scores[I] /= Sum, P[I] = Scores[I];
		sort(P, P + N);
		double Temp = 0;
		for (int I = 0; I < N; I++) Temp += P[N - 1] - P[I];
		int Pos = N - 1;
		while (Temp > 1 && Pos > 0)
		{
			Temp -= (P[Pos] - P[Pos - 1]) * Pos;
			Pos--;
		}
		Temp = P[Pos] + (1 - Temp) / (Pos + 1);
		printf("Case #%d:", TT);
		for (int I = 0; I < N; I++)
		{
			double Ans = Temp - Scores[I];
			if (Ans < 0) Ans = 0;
			printf(" %.10f", Ans * 100);
		}
		printf("\n");
	}
	return 0;
}
