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

const int Inf = 999999999;

const int XXs[4] = {0, 1, 0, -1};
const int YYs[4] = {1, 0, -1, 0};

struct item
{
	int Time;
	int X, Y;

	item() {};
	item(int Time, int X, int Y) : Time(Time), X(X), Y(Y) {}
};

bool operator<(const item& A, const item& B)
{
	return A.Time > B.Time;
}

int NN, TT;
int N, M, InitLev;
int Ceils[100][100], Floors[100][100];
int EnableTimes[100][100];
bool Marks[100][100];
int P[100][100];
vector<item> Queue;

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> InitLev >> N >> M;
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++) cin >> Ceils[X][Y];
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++) cin >> Floors[X][Y];
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
		{
			if (Ceils[X][Y] - Floors[X][Y] < 50) EnableTimes[X][Y] = Inf;
			else if (Ceils[X][Y] - InitLev >= 50) EnableTimes[X][Y] = 0;
			else EnableTimes[X][Y] = (InitLev - (Ceils[X][Y] - 50));
		}
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++) P[X][Y] = Inf, Marks[X][Y] = false;
		P[0][0] = 0;
		Queue.clear();
		Queue.push_back(item(0, 0, 0));
		while (!Queue.empty())
		{
			item Me = Queue[0];
			pop_heap(Queue.begin(), Queue.end());
			Queue.pop_back();
			if (Marks[Me.X][Me.Y]) continue;
			Marks[Me.X][Me.Y] = true;
			for (int Dir = 0; Dir < 4; Dir++)
			{
				int X = Me.X + XXs[Dir];
				int Y = Me.Y + YYs[Dir];
				if (X < 0 || X >= N || Y < 0 || Y >= M) continue;
				if (Ceils[Me.X][Me.Y] - Floors[X][Y] < 50) continue;
				if (Ceils[X][Y] - Floors[Me.X][Me.Y] < 50) continue;
				if (Ceils[X][Y] - Floors[X][Y] < 50) continue;
				int Time = max(Me.Time, EnableTimes[X][Y]);
				if (Time > 0)
				{
					if (InitLev - Time >= Floors[Me.X][Me.Y] + 20) Time += 10;
					else Time += 100;
				}
				if (Time < P[X][Y])
				{
					Queue.push_back(item(Time, X, Y));
					P[X][Y] = Time;
					push_heap(Queue.begin(), Queue.end());
				}
			}
		}
		printf("Case #%d: %.1f\n", TT, (double)P[N - 1][M - 1] / 10);
	}
	return 0;
}
