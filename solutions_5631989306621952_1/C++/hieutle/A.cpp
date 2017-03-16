#include <stdio.h>
#include <string.h>
#include <iostream>
#include <deque>
// #define TEST

using namespace std;
const int MAX_N = 1005;
char s[MAX_N];

int main()
{
	#ifndef TEST
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	int test;
	cin >> test;
	for (int tt = 1; tt <= test; tt++)
	{
		cin >> s;
		int n = strlen(s);
		deque<char> word;
		word.push_back(s[0]);
		for (int i = 1; i < n; i++)
		{
			char head = word.front();
			if (s[i] >= head)
				word.push_front(s[i]);
			else
				word.push_back(s[i]);
		}
		cout << "Case #" << tt << ": ";
		for (char c : word)
			cout << c;
		cout << endl;
	}
}
