#define _CRT_SECURE_NO_WARNINGS 0
#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#define gc getchar
using namespace std;
inline void write(int a){ if (a > 0){ char s[12]; int k = 0; while (a > 0) s[k++] = a % 10 + '0', a /= 10; for (register int i = k - 1; i >= 0; i--)putchar(s[i]); } else putchar('0'); }
inline void read(int *a){ register char c = 0; while (c<33) c = gc(); *a = 0; while (c>33) *a = *a * 10 + c - '0', c = gc(); }
inline void newline(){ putchar('\n'); }
inline void newspace(){ putchar(' '); }
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int main()
{
	int T;
	int X, R, C;

	freopen("input4.txt", "r", stdin);
	freopen("output4.txt", "w", stdout);

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		bool result = true;

		cin >> X >> R >> C;
		if (X >= 7)
			result = false;
		else if (X > R && X > C)
			result = false;
		else if (R * C % X != 0)
			result = false;
		else if ((X + 1) / 2 > min(R, C))
			result = false;
		else if (X == 1 || X == 2 || X == 3)
			result = true;
		else if (X == 4)
			result = min(R, C) > 2;
		else if (X == 5)
			result = !(min(R, C) == 3 && max(R, C) == 5);
		else if (X == 6)
			result = min(R, C) > 3;

		cout << "Case #" << (i + 1) << ": ";
		cout << ((result) ? "GABRIEL\n" : "RICHARD\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}