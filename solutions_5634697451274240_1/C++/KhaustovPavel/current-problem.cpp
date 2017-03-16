#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#pragma comment(linker, "/STACK:128000000")
 
typedef pair<int, int> pii;
typedef long long int64;
typedef pair<int64, int64> pii64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<int,pii> piii;
typedef pair<int64,pii> piii64;
typedef pair<pii,pii> piiii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
 
#define y1 dsjfksdj_fks
#define y2 alksaad_sa
#define y0 _sdkfsjfs__
 
#define tm _dskfjskdfjksdf

int nt;
string s;

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 
	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		cin >> s;
		int res = 0;
		if (s[0] == '-')
			--res;
		int i = 0;
		int l = static_cast<int>(s.length());
		while (i < l)
		{
			if (s[i] == '+')
			{
				++i;
				continue;
			}
			int j = i + 1;
			while (j < l && s[j] == '-')
			{
				++j;
			}
			res += 2;
			i = j;
		}
		printf("Case #%d: %d\n", tn, res);
	}

    return 0;
}