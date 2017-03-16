#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <complex>
#include <random>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int T, N;
string S;

string go()
{
	string ret = "";
	ret += S[0];
	for (int i = 1; i < N; i++)
	{
		if (S[i] >= ret[0])
			ret = S[i] + ret;
		else
			ret += S[i];
	}
	return ret;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	ios::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> S;
		N = S.size();
		cout << "Case #" << t << ": " << go() << "\n";
	}

	return 0;
}