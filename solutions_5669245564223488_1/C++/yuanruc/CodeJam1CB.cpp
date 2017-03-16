#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MOD 1000000007
#define MAXN 110
#define LL long long

int T, tt = 0;
int n;
string s[MAXN];
char ns[MAXN][MAXN];
int len[MAXN];
LL ans;

LL fact(int x)
{
	LL re = 1;
	for (int i = 2; i <= x; ++i)
		re = (re * i) % MOD;
	return re;
	}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) cin >> s[i];
		memset(len, 0, sizeof(len));
		int b[26], e[26], o[26], num[26];
		memset(b, 0, sizeof(b));
		memset(e, 0, sizeof(e));
		memset(o, 0, sizeof(o));
		memset(num, 0, sizeof(num));
		bool can = true;
		for (int i = 0; i < n; ++i)
		{
			int l = s[i].size();
			ns[i][len[i]++] = s[i][0];
			num[s[i][0]-97]++;
			for (int j = 1; j < l; ++j)
				if (s[i][j] != s[i][j-1]){
					ns[i][len[i]++] = s[i][j];
					num[s[i][j]-97]++;
				}
			if (len[i]>1){
				b[s[i][0]-97]++;
				e[s[i][l-1]-97]++;
			}else o[s[i][0]-97]++;
			ns[i][len[i]] = '\0';
//			cout << ns[i] << endl;
			for (int j = 1; j < len[i]-1; ++j)
				if (num[ns[i][j]-97] > 1) can = false;
			}
		for (int i = 0; i < 26; ++i)
			if (b[i] > 1 || e[i] > 1) can = false;
		printf("Case #%d: ", (++tt));
		if (!can){
			cout << 0<< endl;
		}else{
			LL ans = 1;
			int loc = 0;
			int k = 0;
			for (int i = 0; i < 26; ++i)
				loc += b[i] + e[i];
			loc /= 2;
			for (int i = 0; i < 26; ++i)
				if (b[i] + e[i] == 1) k++;
			k /= 2;
			if (k == 0) { ans = loc; k = 1; if (ans <= 0) { ans = 1; k = 0;} }
			for (int i = 0; i < 26; ++i)
				if (o[i] > 0){
					if (num[i] == o[i]) k++;
					ans = ans * fact(o[i]) % MOD;
				}
			ans = ans * fact(k) % MOD;
			cout << ans << endl;
			}
		}
	return 0;
	}
