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
	int* SMax;
	string *Str;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	SMax = new int[T];
	Str = new string[T];

	for (int i = 0; i < T; ++i)
	{
		cin >> SMax[i] >> Str[i];
	}

	//Processing:
	for (int i = 0; i < T; ++i)
	{
		string tempStr = Str[i];
		int totalInvitedFriends = 0;
		int total = 0;
		for (int j = 0; j < tempStr.size(); ++j)
		if (total >= j)
			total += tempStr[j] - 48;
		else
		{
			totalInvitedFriends += j - total;
			total = j + tempStr[j] - 48;
		}
		cout << "Case #" << i + 1 << ": " <<totalInvitedFriends << endl;
	}

	delete[] SMax;
	delete[] Str;

	fclose(stdout);
	return 0;
}