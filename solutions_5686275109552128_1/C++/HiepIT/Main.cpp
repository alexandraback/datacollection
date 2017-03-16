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

int P[1000];

int findMaxArray(int *arr, int n)
{
	int _max = arr[0];
	for (int i = 1; i < n; ++i)
	if (arr[i] > _max)
		_max = arr[i];

	return _max;
}

int findIdxMaxArray(int *arr, int n)
{
	int _maxIdx = 0;
	for (int i = 1; i < n; ++i)
	if (arr[i] > arr[_maxIdx])
		_maxIdx = i;

	return _maxIdx;
}

int numberElementEqualValue(int *arr, int n, int value)
{
	int counter = 0;
	for (int i = 0; i < n; ++i)
	if (arr[i] == value)
		counter++;

	return counter;
}

int main()
{
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int T;
	cin >> T;
	int D;

	for (int i = 0; i < T; ++i)
	{
		cin >> D;
		for (int j = 0; j < D; ++j)
		{
			cin >> P[j];
		}
		int ans = findMaxArray(P, D); //Init ans with max minute posible
		int p = 2;
		while (p < ans)
		{
			int sum = 0;
			for (int k = 0; k < D; ++k)
				sum += (P[k] - 1) / p;
			ans = min(ans, sum + p); //Find min minutes posible
			p++;
		}

		cout << "Case #" << (i + 1) << ": " << ans << endl;
	}

	fclose(stdout);
	fclose(stdin);
	return 0;
}