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
#define LL long long
#define EPS 0.00000000000001
#define MOD 1000000009
#define INF 1000000000000000000LL
#define L 200

int T;

LL flipCount(char * st)
{
	int slen = strlen(st);
	int cnt = 0;
	for (int i = 1; i < slen; ++i)
	{
		if (st[i - 1] != st[i])cnt++;
	}
	if (st[slen - 1] == '-')cnt++;
	re cnt;
}

int main()
{
#ifdef _DINARISIO
	ifstream cin("B-large.in");
	ofstream cout("A.out");
#endif
	/*for (int i = 0; i < 1000000; ++i)
	{
		if (lastNumber(i) == -1){
			continue;
		}
	}*/
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		char s[L];
		cin >> s;
		LL res = flipCount(s);
		cout << "Case #" << t + 1 << ": " << res << endl;
	}
	
	re 0;
}