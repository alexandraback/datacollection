#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout
vector <int> q[5000000];
int ans[50000];

pair <int, pair <int, int> > a[500];

int tot = 0;
int S[5000000];

int sum(int j)
{
	int ret = 0;
 	for (; j >= 0; (j&=(j+1))--)
 		ret += S[j];
 	return ret;
}

void upd(int j)
{
 	for (; j < 2000001; j |= (j+1))
 		S[j]++;
}

inline int num(string &a)
{
 	int ret = 0;

 	for (int i = 0; i < SIZE(a); i++)
 		ret = ret*10 + a[i]-'0';

 	return ret;
}

string s, t;
inline void proceed(int x, vector <int> &a)
{
 	s = "";
	for (; x; x /= 10)
		s += x%10+'0';
	reverse(s.begin(), s.end());

	for (int i = 1; i < SIZE(s); i++)
	{
		if (s[i] == '0') continue;

		t = s.substr(i) + s.substr(0, i);

		if (t[0]!='0' && t < s)
			a.PB(num(t));
	}
}

int main ()
{
	for (int i = 1; i <= 2000000; i++)
	{
	 	proceed(i, q[i]);
	 	sort(q[i].begin(), q[i].end());
	 	q[i].resize(unique(q[i].begin(), q[i].end())-q[i].begin());
	}

	scanf ( "%d", &test_num );
	int t = test_num;
	for (int i = 0; i < t; i++)
		scanf("%d%d", &a[i].second.first, &a[i].first),
		a[i].second.second = i;

	sort(a, a + t);

	for (int i = 0, j = 1; i < t; i++)
	{
	 	for (; j <= a[i].first; j++)
	 		for (int k = 0; k < SIZE(q[j]); k++)
	 			tot++,
	 			upd(q[j][k]);
	 	ans[a[i].second.second] = tot-sum(a[i].second.first-1);
	}

	for (int i = 0; i < t; i++)
		gout << ans[i] << endl;

	return 0;
}
