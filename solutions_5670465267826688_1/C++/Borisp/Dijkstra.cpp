#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

char table[256][256];
char oppositeChar(char c)
{
	if (islower(c))
		return (c - 'a') + 'A';
	else
		return (c  - 'A') + 'a';
}
void initializeTable()
{
	int characters[8] = {'l','i','j','k','L','I','J','K'};
	for (int i = 0; i < 8; i++)
		table['l'][characters[i]] = characters[i];
	table['i']['l'] = 'i';
	table['i']['i'] = 'L';
	table['i']['j'] = 'k';
	table['i']['k'] = 'J';
	table['j']['l'] = 'j';
	table['j']['i'] = 'K';
	table['j']['j'] = 'L';
	table['j']['k'] = 'i';
	table['k']['l'] = 'k';
	table['k']['i'] = 'j';
	table['k']['j'] = 'I';
	table['k']['k'] = 'L';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			table[characters[i]][characters[j]] = table[characters[i % 4]][characters[j % 4]];
			if ((i < 4 && j < 4) || (i >= 4 && j >= 4))
				continue;
			else
				table[characters[i]][characters[j]] = oppositeChar(table[characters[i]][characters[j]]);
		}
	}
}
int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	initializeTable();
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int l;
		long long x;
		cin >> l >> x;
		string str;
		cin >> str;
		if (x % (long long)4 == 0)
		{
			cout << "NO" << endl;
			continue;
		}
		string check = "";
		long long rem = x % (long long)4;
		for (int i = 0; i < rem; i++)
			check += str;
		char cur = 'l';
		for (int i = 0; i < check.size(); i++)
		{
			cur = table[cur][check[i]];
		}
		if (cur != 'L')
		{
			cout << "NO" << endl;
			continue;
		}
		check = "";
		int lim = min((long long)8, (long long)x);
		for (int i = 0; i < lim; i++)
			check += str;
		bool firstReached = false;
		bool secondReached = false;
		cur = 'l';
		for (int i = 0; i < check.size(); i++)
		{
			cur = table[cur][check[i]];
			if (!firstReached && cur == 'i')
			{
				firstReached = true;
				cur = 'l';
				continue;
			}
			if (firstReached && !secondReached && cur == 'j')
			{
				secondReached = true;
				break;
			}
		}
		if (secondReached)
		{
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
