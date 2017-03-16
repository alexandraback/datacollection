#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

#define min(x, y) (((x) > (y)) ? (y) : (x))

string calc(int X, int R, int C)
{
	if (X >= 7) return "RICHARD";
	if ((R * C) % X != 0) return "RICHARD";
	
	if (min(R, C) != 1 && X >= 2 * min(R, C)) return "RICHARD";
	for (int garo = 1; garo <= X; ++garo)
	{
		int sero = X + 1 - garo;
		if (R < garo && R < sero) return "RICHARD";
		if (C < garo && C < sero) return "RICHARD";
	}
	return "GABRIEL";
}

int main(int argc, char** argv)
{
	if (argc == 3)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int X, R, C;
		scanf("%d%d%d", &X, &R, &C);
		string ret = calc(X, R, C);
		printf("Case #%d: %s\n", cn, ret.c_str());
	}
	return 0;
}
