#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;

string lltostr(ll i)
{
	stringstream ss;
	ss << i;
	string res;
	ss >> res;
	return res;
}

//data for prob:
int kr[1000001];
ll brsnach[1000001];
string str;
int n, L;

inline bool vowel(char c)
{
	return c == 'i' || c == 'a' || c == 'o' || c == 'e' || c == 'u';
}

void read()
{
	cin >> str >> n;
	L = str.size();
	memset(kr, -1, sizeof(kr));
	memset(brsnach, 0, sizeof(brsnach));
}



string solve()
{
	int cons = 0;
	for (int i = L - 1; i >= 0; --i)
	{
		if (!vowel(str[i])) cons++;
		else cons = 0;
		if (cons >= n)
		{
			kr[i] = i + n - 1;
		} else kr[i] = kr[i + 1];
	}
	for (int i = 0; i < L - n + 1; ++i)
	{
		if (kr[i] >= 0)
			brsnach[i] += L - kr[i];
	}
	ll rez = 0;
	for (int i = 0; i < L; ++i)
		rez += brsnach[i];
	return lltostr(rez);
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//program
	int tests;
	scanf("%d\n", &tests);
	for (int CASE = 1; CASE <= tests; ++CASE)
	{
		read();
		printf("Case #%d: %s\n", CASE, solve().c_str());
	}
	//end program
	return 0;
}




