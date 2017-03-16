#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	freopen("a-small-attempt0.in", "r", stdin);
	freopen("small.txt", "w", stdout);
	int data;
	scanf("%d", &data);
	for (int p = 1; p <= data; p++)
	{
		int dat[300];
		fill(dat, dat + 300, 0);
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++)dat[s[i]]++;
		int ans[10];
		ans[0] = dat['Z'];
		dat['E'] -= dat['Z'];
		dat['R'] -= dat['Z'];
		dat['O'] -= dat['Z'];
		dat['Z'] -= dat['Z'];
		ans[2] = dat['W'];
		dat['T'] -= dat['W'];
		dat['O'] -= dat['W'];
		dat['W'] -= dat['W'];
		ans[6] = dat['X'];
		dat['S'] -= dat['X'];
		dat['I'] -= dat['X'];
		dat['X'] -= dat['X'];
		ans[8] = dat['G'];
		dat['E'] -= dat['G'];
		dat['I'] -= dat['G'];
		dat['H'] -= dat['G'];
		dat['T'] -= dat['G'];
		dat['G'] -= dat['G'];
		ans[3] = dat['H'];
		dat['T'] -= dat['H'];
		dat['R'] -= dat['H'];
		dat['E'] -= dat['H'];
		dat['E'] -= dat['H'];
		dat['H'] -= dat['H'];
		ans[7] = dat['S'];
		dat['E'] -= dat['S'];
		dat['V'] -= dat['S'];
		dat['E'] -= dat['S'];
		dat['N'] -= dat['S'];
		dat['S'] -= dat['S'];
		ans[5] = dat['V'];
		dat['F'] -= dat['V'];
		dat['I'] -= dat['V'];
		dat['E'] -= dat['V'];
		dat['V'] -= dat['V'];
		ans[4] = dat['R'];
		dat['F'] -= dat['R'];
		dat['O'] -= dat['R'];
		dat['U'] -= dat['R'];
		dat['R'] -= dat['R'];
		ans[1] = dat['O'];
		dat['N'] -= dat['O'];
		dat['E'] -= dat['O'];
		dat['O'] -= dat['O'];
		ans[9] = dat['I'];
		dat['N'] -= dat['I'];
		dat['N'] -= dat['I'];
		dat['E'] -= dat['I'];
		dat['I'] -= dat['I'];
		for (int i = 0; i < 300; i++)if (dat[i] != 0)abort();
		printf("Case #%d: ", p);
		for (int i = 0; i <= 9; i++)for (int j = 0; j < ans[i]; j++)printf("%d", i);
		printf("\n");
	}
}