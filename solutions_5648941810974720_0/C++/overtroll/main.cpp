#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

int a[256];
int b[10];
string s;

void dec(string t)
{
	for (int i = 0; i < t.length(); i++) a[t[i] - 'A']--;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int iter = 1; iter <= t; iter++)
	{
		cin >> s;
		cout << "Case #" << iter << ": ";
		for (int i = 0; i < 26; i++) a[i] = 0;
		for (int i = 0; i < 10; i++) b[i] = 0;
		for (int i = 0; i < s.length(); i++)
		{
			a[s[i] - 'A']++;		
		}	
		while (a['Z' - 'A'] > 0) 
		{
			b[0]++;
			dec("ZERO");
		}
		while (a['W' - 'A'] > 0) 
		{
			b[2]++;
			dec("TWO");
		}
		while (a['X' - 'A'] > 0) 
		{
			b[6]++;
			dec("SIX");
		}
		while (a['G' - 'A'] > 0) 
		{
			b[8]++;
			dec("EIGHT");
		}
		while (a['T' - 'A'] > 0) 
		{
			b[3]++;
			dec("THREE");
		}
		while (a['R' - 'A'] > 0) 
		{
			b[4]++;
			dec("FOUR");
		}
		while (a['F' - 'A'] > 0) 
		{
			b[5]++;
			dec("FIVE");
		}
		while (a['O' - 'A'] > 0) 
		{
			b[1]++;
			dec("ONE");
		}
		while (a['S' - 'A'] > 0) 
		{
			b[7]++;
			dec("SEVEN");
		}
		while (a['N' - 'A'] > 0) 
		{
			b[9]++;
			dec("NINE");
		}
		for (int i = 0; i < 26; i++)
		{
			if (a[i] != 0) cout << "dlkfjdslfldskfjdslfjdksjflkdsf" << endl;
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < b[i]; j++) cout << i;
		}
		cout << endl;
	}
	return 0;
}