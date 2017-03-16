#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define MM(a , x) memset(a , x , sizeof(a))
#define sqr(x) ((x) * (x))
#define abs(x) ((x > 0) ? (x) : -(x))
#define REP(i , n) for ((i) = 0; (i) < (n); ++(i))
#define FOR(i , a , b) for ((i) = (a); (i) <= (b); ++(i))
#define FORD(i , a , b) for ((i) = (a); (i) >= (b); --(i))
typedef long long LL;

int n , m , len , maxlen , T , testcase;
int f[100][10];
string str;
vector<string> dict[20];
int index[20][27] , ed[20][27];

void init()
{
	freopen("garbled_email_dictionary.txt" , "r" , stdin);
	int i , j , k;
	string st;
	maxlen = 0;
	FOR (i , 1 , 521196)
	{
		cin >> st;
		k = st.length();
		dict[k].push_back(st);
		maxlen = max(maxlen , k);
	}
}

inline int check(const string &s1 , const string &s2 , const int &l2 , int &l1)
{
	int i , pre , cnt = 0;;
	pre = -1;
	for (i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
		{
			cnt++;
			if (pre == -1)
			{
				pre = i;
				if (i + l2 < 4) cnt = 10000;
			}
			else
			{
				if (i - pre < 5) cnt = 10000;
				pre = i;
			}
		}
	}
	if (pre == -1) l1 = s1.length() + l2;
	else l1 = s1.length() - pre - 1;
	l1 = min(l1 , 5);

	return cnt;
}

void work()
{
	int i , j , k , x , l1 , l2 , tmp , tp;
	n = str.length();
	FOR (i , 0 , n) FOR (j , 0 , 9) f[i][j] = 10000;
	string st;
	f[0][5] = 0;
	FOR (j , 0 , n - 1) FOR (l2 , 0 , 5)
	{
		if (f[j][l2] >= 10000) continue;
		FOR (i , j + 1 , n)
		{
			tmp = 10000;
			st.clear();
			FOR (k , j , i - 1) st.push_back(str[k]);
			len = st.length();
			for (x = 0; x < dict[len].size(); x++)
			{
				tmp = check(dict[len][x] , st , l2 , l1);
				f[i][l1] = min(f[i][l1] , f[j][l2] + tmp);
			}
		}
	}
	int ans = 10000;
	FOR (l1 , 0 , 5) ans = min(ans , f[n][l1]);
	printf("Case #%d: %d\n" , testcase , ans);
	/*
	FOR (i , 0 , n)
	{
		FOR (l1 , 0 , 5) printf("f[%d][%d]=%d " , i , l1 , f[i][l1]);
		printf("\n");
	}
	*/
}

int main()
{
	init();
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	cin >> T;
	FOR (testcase , 1 , T)
	{
		cin >> str;
		work();
	}
}
