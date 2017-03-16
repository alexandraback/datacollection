// Alfonso2 Peterssen
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(c) ((int)(c).size())
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)

typedef long long int64;

int N;
string S;

bool isVowel(char c)
{
	return c == 'a' || c == 'e'  || c == 'i'  || c == 'o'  || c == 'u';
}

int main()
{
	int testCount;
	cin >> testCount;
	FOR(test, 1, testCount)
	{
		cin >> S >> N;
		int L = SZ(S);

		int lo = 0;

		int hi = 0;
		int cnt = 0;

		int64 answer = 0;

		while (hi < N)
		{
			// push
			if (!isVowel( S[hi] )) cnt++;
			hi++;
		}

		set< int > st;

		if (cnt == N) st.insert(0);

		while (hi < L)
		{
			// pop
			if (!isVowel( S[lo] )) cnt--;
			lo++;
			// push
			if (!isVowel( S[hi] )) cnt++;
			hi++;
			if (cnt == N)
				st.insert(lo);
		}

		REP(i, L)
		{
			set< int >::iterator it = st.lower_bound(i);
			int hi = L;
			if (it != st.end())	hi = *it + N - 1;
			answer += hi - i;
		}

		int64 nn = L;
		answer = nn * (nn + 1) / 2 - answer;

		cout << "Case #" << test << ": " << answer << endl;
	}

	return 0;
}
