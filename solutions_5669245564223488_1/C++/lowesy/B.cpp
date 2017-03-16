#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> 
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

const int MAXN = 1010 * 2;

const int MOD = 1000000007;

LL fac[MAXN];

string dic[MAXN];
int cnt[30][30];
int N, res;
bool vst[30];


bool check ()
{
	memset (cnt, 0, sizeof (cnt));
	res = 1;
	sort (dic, dic + N);
	
	for (int i = 0; i < N; ++ i)
	{
		int L = unique (dic[i].begin(), dic[i].end()) - dic[i].begin();
		dic[i] = dic[i].substr (0, L);
		if (dic[i].size() > 30)	return false;
		for (int j = 2; j < dic[i].size(); ++ j)
			if (dic[i][j] != dic[i][j - 1])
				for (int k = 0; k < j; ++ k)
					if (dic[i][j] == dic[i][k])
						return false;
		++ cnt[dic[i][0] - 'a'][dic[i][dic[i].size() - 1] - 'a'];
	}
	
	for (int i = 0; i < N; ++ i)
	{
		for (int j = 0; j < N; ++ j)
		{
			if (i == j)	continue;
			
			for (int k = 1; k + 1 < dic[i].size(); ++ k)
				for (int l = 0; l < dic[j].size(); ++ l)
					if (dic[i][k] == dic[j][l])
						return false;	
		}	
	}

	for (int i = 0; i < 26; ++ i)
	{
		int sum1 = - cnt[i][i], sum2 = -  cnt[i][i];
		for (int j = 0; j < 26; ++ j)
		{
			sum2 += cnt[j][i];
			sum1 += cnt[i][j];	
		}
		if (sum1 > 1 || sum2 > 1)	return false;
		res = res * fac[cnt[i][i]] % MOD;
	}
				
	return true;
}

int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++ i)
	{
		fac[i] = fac[i - 1] * i % MOD;	
	}
	
	int T;	cin >> T;
	for (int cas = 1; cas <= T; ++ cas)
	{
		cin >> N;
		for (int i = 0; i < N; ++ i)
		{
			cin >> dic[i];	
		}
		
		cout << "Case #" << cas << ": ";
		
		if (!check ())
		{
			cout << "0" << endl;
			continue;
		}
		
		for (int k = 0; k < 26; ++ k)
			for (int i = 0; i < 26; ++ i)
				for (int j = 0; j < 26; ++ j)
					if (cnt[i][k] > 0 && cnt[k][j] > 0)
						cnt[i][j] = 1;
						
		int in[30] = {0}, out[30] = {0};
		int sum = 0;
		bool error = false;
		for (int i = 0; i < 26; ++ i)
		{
			for (int j = 0; j < 26; ++ j)
			{
				out[i] += cnt[i][j];
				if (j != i)	
				{
					in[i] += cnt[j][i];	
					error |= cnt[i][j] * cnt[j][i] > 0; 	
				}
			}	
			if (in[i] == 0 && out[i] > 0)	++ sum;
		}
		
		res = res * (!error) * fac[sum] % MOD;
		cout << res << endl;
	}
	
	
	
	return 0;	
}
