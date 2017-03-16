#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <complex>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int T, J, P, S, K;
int A[30][3];
int cnt, best, bits;
int JP[4][4], PS[4][4], SJ[4][4];

bool check()
{
	for (int i = 1; i <= J; i++)
		for (int j = 1; j <= P; j++)
			if (JP[i][j] > K)
				return false;
	for (int i = 1; i <= P; i++)
		for (int j = 1; j <= S; j++)
			if (PS[i][j] > K)
				return false;
	for (int i = 1; i <= S; i++)
		for (int j = 1; j <= J; j++)
			if (SJ[i][j] > K)
				return false;
	return true;
}

void go()
{
	cnt = 0;
	for (int i = 1; i <= J; i++)
		for (int j = 1; j <= P; j++)
			for (int k = 1; k <= S; k++)
			{
				A[cnt][0] = i, A[cnt][1] = j, A[cnt][2] = k;
				cnt++;
			}

	if (K >= 3)
	{
		best = (1 << cnt) - 1;
		bits = cnt;
		return;
	}

	best = -1, bits = 0;
	for (int i = 0; i < (1 << cnt); i++)
	{
		memset(JP, 0, sizeof(JP));
		memset(PS, 0, sizeof(PS));
		memset(SJ, 0, sizeof(SJ));
		int total = 0;
		for (int j = 0; j < cnt; j++)
			if ((i&(1 << j)))
			{
				total++;
				JP[A[j][0]][A[j][1]]++;
				PS[A[j][1]][A[j][2]]++;
				SJ[A[j][2]][A[j][0]]++;
			}
		if (check())
		{
			if (bits < total)
			{
				bits = total;
				best = i;
			}
		}
	}
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	ios::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> J >> P >> S >> K;
		
		go();
		cout << "Case #" << t << ": " << bits << "\n";
		for (int i = 0; i < cnt; i++)
			if ((best&(1 << i)))
				cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << "\n";
	}

	return 0;
}