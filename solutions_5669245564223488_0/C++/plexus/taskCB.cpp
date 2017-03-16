#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF (1<<30)

using namespace std;

const int N = 11111;
const int MOD = 1000000007;

char buff[300];
int p[N];	


bool check(vector<string> &v)
{
	for(int i = 0; i<v.size(); i++)
		for(int j = i+1; j<v.size(); j++)
		{
			if (v[i][0] == v[j][v[j].size() - 1] && v[j][0] == v[i][v[i].size() - 1] && v[i][0] != v[j][0])
				return false;
		}

	for(char c = 'a'; c <= 'z'; c++)
	{
		int cnt = 0, cnte = 0, cntb = 0, cntf = 0;

		for(int i = 0; i < v.size(); i++)
		{
			int mni = INF;
			int mxi = -INF;
			for(int j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] == c)
				{
					mni = min(mni, j);
					mxi = max(mxi, j);
				}
			}

			for(int j = mni; j <= mxi; j++)		
				if (v[i][j] != c)
					return false;
		
			if (mni > 0 && mxi < v[i].size() - 1)
				cnt++;

			if (mni == 0 && mxi < v[i].size() - 1)
				cntb++;

			if (mni > 0 && mxi == v[i].size() -1 )
				cnte++;			

			if (mni == 0 && mxi == v[i].size() - 1)
				cntf++;
		}

		if (cntb > 1 || cnte > 1 || cnt > 1)
			return false;	

		if (cnt && (cntb || cntf || cnte))
			return false;
	}

	return true;

}

int64_t fact(int64_t k)
{
	int64_t res = 1;
	for(int i = 2; i <= k; i++)
	{
		res *= i;
		res %= MOD;
	}
	return res;
}

int64_t formBlock(int ind, const vector<string> &v)
{
	
	char e = v[ind][v[ind].size()-1];
	char b = v[ind][0];
	int64_t ways = 1;

	bool flag = true;
	while (flag)
	{
		int cntf = 0, inde = -1;

		flag = false;

		for(int i = 0; i < v.size(); i++)
		{
			int mni = INF;
			int mxi = -INF;
			for(int j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] == e)
				{
					mni = min(mni, j);
					mxi = max(mxi, j);
				}
			}
		
			if (p[i] == 0 && mni == 0 && mxi == v[i].size() - 1)
			{
				cntf++;
				p[i] = 1;
			}

			if (p[i] == 0 && mni == 0 && mxi < v[i].size() - 1)
			{
				inde = i;
				p[i] = 1;
			}
		}

		ways *= fact(cntf);

		if (inde != -1)
		{
			flag = true;
			e = v[inde][v[inde].size() - 1];
		}

		//cout<<cntf<<" "<<inde<<endl;
	}

	flag = true;
	while (flag)
	{
		int cntf = 0, indb = -1;

		flag = false;

		for(int i = 0; i < v.size(); i++)
		{
			int mni = INF;
			int mxi = -INF;
			for(int j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] == b)
				{
					mni = min(mni, j);
					mxi = max(mxi, j);
				}
			}
		
			if (p[i] == 0 && mni == 0 && mxi == v[i].size() - 1)
			{
				cntf++;
				p[i] = 1;
			}

			if (p[i] == 0 && mni > 0 && mxi == v[i].size() - 1)
			{
				indb = i;
				p[i] = 1;
			}
		}

		ways *= fact(cntf);

		if (indb != -1)
		{
			flag = true;
			b = v[indb][0];
		}
	}

	return ways;
}

int64_t solve(vector<string> &v)
{
	memset(p, 0, sizeof(p));
	vector<int64_t> blocks;
	for(int i = 0; i<v.size(); i++)
	{
		if (p[i] == 0)
			blocks.pb(formBlock(i, v));
	}

	int64_t res = fact(blocks.size());

	for(int i = 0; i<blocks.size(); i++)
	{
		res *= blocks[i];
		res %= MOD;
	}

	return res;
}

int main()
{
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	scanf("%d", &t);
	gets(buff);

	for(int test = 1; test <= t; test++)
	{
		printf("Case #%d: ", test);
		
		int n;
		scanf("%d", &n);
		gets(buff);

		vector<string> v;

		for(int i = 0; i<n; i++)
		{
			string s;
			cin>>s;
			v.pb(s);
		}
		gets(buff);

		if (!check(v))
		{
			printf("0");			
		}
		else
		{
			printf("%lld", solve(v));
		}

		printf("\n");
	}

	return 0;
}