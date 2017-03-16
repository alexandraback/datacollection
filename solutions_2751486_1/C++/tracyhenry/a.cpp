#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

string s, s1;
int n, F[1010100], L;
int sum[1010100];
set<char> vowel;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	int T;
	cin >> T; getline(cin, s1);
	vowel.clear();
	vowel.insert('a');
	vowel.insert('e');
	vowel.insert('i');
	vowel.insert('o');
	vowel.insert('u');
	
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		cin >> s >> n;
		getline(cin, s1);
		L = s.size();
		for (int i = 1; i <= L; i ++)
			F[i] = -1;
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= L; i ++)
			sum[i] = sum[i - 1] + (vowel.count(s[i - 1]) ? 0 : 1);
		LL ans = 0;
		for (int i = 1; i <= L; i ++)
		{
			F[i] = F[i - 1];
			if (i >= n && sum[i] - sum[i - n] == n)
				F[i] = i - n + 1;
			if (F[i] != -1)
				ans += (LL) F[i];
		}
		cout << ans << endl;
	}
	return 0;
}
			
			 
		
		
		
