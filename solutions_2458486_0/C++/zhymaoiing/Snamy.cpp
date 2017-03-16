#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void redirectIO(bool changeIn, bool changeOut)
{
	string fileName;
	
	if (changeIn || changeOut)
	{
		cin >> fileName;
	}

	if (changeIn)
	{
		string input = fileName + ".in";
		freopen(input.c_str(), "r", stdin);
	}
	
	if (changeOut)
	{
		string output = fileName + ".out";
		freopen(output.c_str(), "w", stdout);
	}
}

const int Max = 20;
const int MaxK = 200;

struct Chest
{
	int key, count, v[MaxK];

	void Input()
	{
		memset(v, 0, sizeof(v));
		int k = count;
		if (k == 0) cin >> k;
		for (int i = 0; i < k; ++i)
		{
			int x;
			cin >> x; --x;
			++v[x];
		}
	}
};

Chest C[Max];

int N, g, id[1 << Max];
int ct, psb[1 << Max], S[MaxK], U[Max];

bool IsPossible(int d, int s)
{
	//cout << d << ": " << s << endl;
	if (d == N)
	{
		for (int i = 0; i < N; ++i)
			cout << " " << U[i] + 1;
		cout << endl;
		return true;
	}

	if (psb[s] == ct) return false;
	psb[s] = ct;

	int tmpS[MaxK];
	memmove(tmpS, S, MaxK * sizeof(int));

	int r = g ^ s;
	while (r)
	{
		int cr = r & -r;
		int x = id[cr];

		if (S[C[x].key] > 0)
		{
			--S[C[x].key];
			for (int i = 0; i < Max; ++i)
				S[i] += C[x].v[i];
			U[d] = x;
			if (IsPossible(d + 1, s ^ cr))
				return true;

			memmove(S, tmpS, MaxK * sizeof(int));
		}

		r ^= cr;
	}

	return false;
}

int main()
{
	redirectIO(true, true);

	for (int i = 0; i < Max; ++i)
		id[1 << i] = i;
	
	int T;
	cin >> T;
	for (ct = 1; ct <= T; ++ct)
	{
		Chest init;
		cin >> init.count >> N;
		init.Input();
		for (int i = 0; i < N; ++i)
		{
			cin >> C[i].key; --C[i].key;
			C[i].Input();
		}

		printf("Case #%d:", ct);
		g = (1 << N) - 1;
		memmove(S, init.v, MaxK * sizeof(int));
		if (!IsPossible(0, 0)) cout << " IMPOSSIBLE\n";
	}

	return 0;
}