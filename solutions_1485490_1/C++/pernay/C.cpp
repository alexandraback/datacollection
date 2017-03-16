#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <deque>
#include <cstdio>

using namespace std;

void init()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
}

struct par
{
	long long int n;
	long long int tip;
};

long long int GetAnswer(int N, vector <par> toys, int M, vector <par> box, int f1, int f2)
{
	if ((f1 == N) || (f2 == M))
	{
		return 0;
	}
	if (toys[f1].tip == box[f2].tip)
	{
		long long int s = min(toys[f1].n, box[f2].n);
		toys[f1].n -= s;
		box[f2].n -= s;
		return s + max(GetAnswer(N, toys, M, box, f1, f2 + 1), GetAnswer(N, toys, M, box, f1 + 1, f2));
	}
	return max(GetAnswer(N, toys, M, box, f1, f2 + 1), GetAnswer(N, toys, M, box, f1 + 1, f2));
}
	
long long int Answer(int N, const vector <par> &toys, int M, const vector <par> &box)
{
	return GetAnswer(N, toys, M, box, 0, 0);
}

int main()
{
	init();
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N, M;
		cin >> N >> M;
		vector <par> toys(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> toys[i].n >> toys[i].tip;
		}
		vector <par> box(M);
		for (int i = 0; i < M; ++i)
		{
			cin >> box[i].n >> box[i].tip;
		}
		cout << "Case #" << t + 1<< ": " << Answer(N, toys, M, box) << endl;
	}
	return 0;
}
