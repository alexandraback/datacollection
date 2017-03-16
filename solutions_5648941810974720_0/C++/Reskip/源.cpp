#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int ans[10];
int data[30];

void get()
{
	if (data['Z' - 'A'])
	{
		int temp = data['Z' - 'A'];
		ans[0] += temp;
		data['Z' - 'A'] -= temp;
		data['E' - 'A'] -= temp;
		data['R' - 'A'] -= temp;
		data['O' - 'A'] -= temp;
	}
	if (data['W' - 'A'])
	{
		int temp = data['W' - 'A'];
		ans[2] += temp;
		data['T' - 'A'] -= temp;
		data['W' - 'A'] -= temp;
		data['O' - 'A'] -= temp;
	}
	if (data['X' - 'A'])
	{
		int temp = data['X' - 'A'];
		ans[6] += temp;
		data['S' - 'A'] -= temp;
		data['I' - 'A'] -= temp;
		data['X' - 'A'] -= temp;
	}
	if (data['S' - 'A'])
	{
		int temp = data['S' - 'A'];
		ans[7] += temp;
		data['S' - 'A'] -= temp;
		data['E' - 'A'] -= temp;
		data['V' - 'A'] -= temp;
		data['E' - 'A'] -= temp;
		data['N' - 'A'] -= temp;
	}
	if (data['V' - 'A'])
	{
		int temp = data['V' - 'A'];
		ans[5] += temp;
		data['F' - 'A'] -= temp;
		data['I' - 'A'] -= temp;
		data['V' - 'A'] -= temp;
		data['E' - 'A'] -= temp;
	}
	if (data['F' - 'A'])
	{
		int temp = data['F' - 'A'];
		ans[4] += temp;
		data['F' - 'A'] -= temp;
		data['O' - 'A'] -= temp;
		data['U' - 'A'] -= temp;
		data['R' - 'A'] -= temp;
	}
	if (data['R' - 'A'])
	{
		int temp = data['R' - 'A'];
		ans[3] += temp;
		data['T' - 'A'] -= temp;
		data['H' - 'A'] -= temp;
		data['R' - 'A'] -= temp;
		data['E' - 'A'] -= 2*temp;
	}
	if (data['G' - 'A'])
	{
		int temp = data['G' - 'A'];
		ans[8] += temp;
		data['E' - 'A'] -= temp;
		data['I' - 'A'] -= temp;
		data['G' - 'A'] -= temp;
		data['H' - 'A'] -= temp;
		data['T' - 'A'] -= temp;
	}
	if (data['O' - 'A'])
	{
		int temp = data['O' - 'A'];
		ans[1] += temp;
		data['O' - 'A'] -= temp;
		data['N' - 'A'] -= temp;
		data['E' - 'A'] -= temp;
	}
	if (data['E' - 'A'])
	{
		int temp = data['E' - 'A'];
		ans[9] += temp;
		data['N' - 'A'] -= temp;
		data['I' - 'A'] -= temp;
		data['N' - 'A'] -= temp;
		data['E' - 'A'] -= temp;
	}
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int t;
	cin >> t;
	int ss = 1;
	while (t--)
	{
		cout << "Case #" << ss << ": ";
		ss++;
		memset(data, 0, sizeof(data));
		memset(ans, 0, sizeof(ans));
		char temp[2005];
		cin >> temp;
		int len = strlen(temp);
		for (size_t i = 0; i < len; i++)
		{
			data[temp[i] - 'A'] += 1;
		}
		get();
		for (size_t i = 0; i < 10; i++)
		{
			for (int s = 0; s < ans[i]; s++)
				cout << i;
		}
		cout << "\n";
	}
	fclose(stdin);
	fclose(stdout);
}