#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define re return
#define LL unsigned long long
#define EPS 0.00000000000001
#define MOD 1000000009
#define INF 1000000000000000000LL
#define K 101
#define N 2001

char s[N];
int counts[1000];
int digitsCount[10];
char result[200000];
int nresult;
int main()
{
#ifdef _DINARISIO
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A.out");
#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << t + 1 << ": ";
		cin >> s;
		
		memset(&counts, 0, sizeof(counts));
		memset(&digitsCount, 0, sizeof(digitsCount));
		
		int slen = strlen(s);
		for (int i = 0; i < slen; ++i)
		{
			counts[s[i]] += 1;
		}
		if (counts['Z'] > 0)
		{
			digitsCount[0] += counts['Z'];
			counts['E'] -= counts['Z'];
			counts['R'] -= counts['Z'];
			counts['O'] -= counts['Z'];
			counts['Z'] = 0;
		}
		if (counts['W'] > 0)
		{
			digitsCount[2] += counts['W'];
			counts['T'] -= counts['W'];
			counts['O'] -= counts['W'];
			counts['W'] = 0;
		}
		if (counts['X'] > 0)
		{
			digitsCount[6] += counts['X'];
			counts['S'] -= counts['X'];
			counts['I'] -= counts['X'];
			counts['X'] = 0;
		}
		if (counts['S'] > 0)
		{
			digitsCount[7] += counts['S'];
			counts['E'] -= counts['S'];
			counts['V'] -= counts['S'];
			counts['E'] -= counts['S'];
			counts['N'] -= counts['S'];
			counts['S'] = 0;
		}
		if (counts['V'] > 0)
		{
			digitsCount[5] += counts['V'];
			counts['F'] -= counts['V'];
			counts['I'] -= counts['V'];
			counts['E'] -= counts['V'];
			counts['V'] = 0;
		}
		if (counts['F'] > 0)
		{
			digitsCount[4] += counts['F'];
			counts['O'] -= counts['F'];
			counts['U'] -= counts['F'];
			counts['R'] -= counts['F'];
			counts['F'] = 0;
		}
		if (counts['O'] > 0)
		{
			digitsCount[1] += counts['O'];
			counts['E'] -= counts['O'];
			counts['N'] -= counts['O'];
			counts['O'] = 0;
		}
		if (counts['N'] > 0)
		{
			int n = counts['N'] / 2;
			digitsCount[9] += n;
			counts['E'] -= n;
			counts['I'] -= n;
			counts['N'] = 0;
		}
		if (counts['I'] > 0)
		{
			digitsCount[8] += counts['I'];
			counts['E'] -= counts['I'];
			counts['G'] -= counts['I'];
			counts['H'] -= counts['I'];
			counts['T'] -= counts['I'];
			counts['I'] = 0;
		}
		if (counts['H'] > 0)
		{
			digitsCount[3] += counts['H'];
		}
		nresult = 0;
		for (int i = 0; i < 10; ++i){
			for (int j = 0; j < digitsCount[i]; ++j){
				result[nresult++] = '0' + i;
			}
		}
		result[nresult] = 0;
		cout << result<<endl;
	}
	re 0;
}