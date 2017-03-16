#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	freopen("b-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int data;
	scanf("%d", &data);
	for (int p = 1; p <= data; p++)
	{
		string s;
		cin >> s;
		s.push_back('+');
		int r = 0;
		for (int i = 0; i < s.size() - 1; i++)if (s[i] != s[i + 1])r++;
		printf("Case #%d: %d\n", p, r);
	}
}