#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
#include <fstream>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 207;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 18;

string R[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int cnt[26];
int res[10];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt" , "w", stdout);
	//freopen("equation.in", "r", stdin);
	//freopen("equation.out", "w", stdout);

	int t;
	cin >> t;
	FOR(tt,0,t)
	{
		printf("Case #%d: " , tt + 1);
		string s;
		cin >> s;
		FILL(cnt, 0);
		FOR(i,0,26)
		{
			cnt[s[i] - 'A'] ++;
		}
		FILL(res,0);

		while (cnt['X' - 'A'] > 0)
		{
			res[6]++;
			FOR(j,0,R[6].size())
			{
				cnt[R[6][j]-'A']--;
			}
		}

		while (cnt['W' - 'A'] > 0)
		{
			res[2]++;
			FOR(j,0,R[2].size())
			{
				cnt[R[2][j]-'A']--;
			}
		}

		while (cnt['Z' - 'A'] > 0)
		{
			res[0]++;
			FOR(j,0,R[0].size())
			{
				cnt[R[0][j]-'A']--;
			}
		}

		while (cnt['G' - 'A'] > 0)
		{
			res[8]++;
			FOR(j,0,R[8].size())
			{
				cnt[R[8][j]-'A']--;
			}
		}

		while (cnt['H' - 'A'] > 0)
		{
			res[3]++;
			FOR(j,0,R[3].size())
			{
				cnt[R[3][j]-'A']--;
			}
		}

		while (cnt['U' - 'A'] > 0)
		{
			res[4]++;
			FOR(j,0,R[4].size())
			{
				cnt[R[4][j]-'A']--;
			}
		}

		while (cnt['F' - 'A'] > 0)
		{
			res[5]++;
			FOR(j,0,R[5].size())
			{
				cnt[R[5][j]-'A']--;
			}
		}

		while (cnt['S' - 'A'] > 0)
		{
			res[7]++;
			FOR(j,0,R[7].size())
			{
				cnt[R[7][j]-'A']--;
			}
		}
		while (cnt['I' - 'A'] > 0)
		{
			res[9]++;
			FOR(j,0,R[9].size())
			{
				cnt[R[9][j]-'A']--;
			}
		}
		while (cnt['O' - 'A'] > 0)
		{
			res[1]++;
			FOR(j,0,R[1].size())
			{
				cnt[R[1][j]-'A']--;
			}
		}
		FOR(i,0,10)
			FOR(j,0,res[i])
				cout << i;
		cout << endl;
	}
}
