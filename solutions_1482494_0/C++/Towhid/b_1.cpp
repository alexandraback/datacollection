#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define SZ 10005

using namespace std;

typedef pair<int, int> PII;
vector<PII> data;

int memo[59050][35];
int tot;

vector<int> unmsk(int msk, int n)
{
	vector<int> ret;
	while(n--)
	{
		ret.push_back(msk % 3);
		msk /= 3;
	}
	
	return ret;
}

int getmsk(vector<int> vv)
{
	int ret = 0;
	int i;
	for(i = 0; i < vv.size(); i++)
	{
		ret = ret * 3 + vv[i];
	}
	return ret;
}

int go(int msk, int n, int tot, int s)
{
	if(n == tot)
		return 0;
	if(memo[msk][s] != -1)
		return memo[msk][s];
	vector<int> vv = unmsk(msk, tot);
	bool flag  = false;
	int i;
	int t =  vv.size();
	int ret = 3000;
	for(i = 0; i < t; i++)
	{
		int tmp = 0;
		if(vv[i] < 2 && data[i].second <= s)
		{
			int tt = vv[i];
			vv[i] = 2;
			int tmsk = getmsk(vv);
			if(tt == 1)
				tmp = go(tmsk, n + 1, tot, s + 1);
			else
				tmp = go(tmsk, n + 1, tot, s + 2);
			if(tmp + 1 < ret)
			{
				ret = tmp + 1;
				flag = true;
			}
			
			vv[i] = tt;
		}
		else if(vv[i] < 1 && data[i].first <= s)
		{
			int tt = vv[i];
			vv[i] = 1;
			int tmsk = getmsk(vv);
			tmp = go(tmsk, n, tot, s + 1);
			
			if(tmp + 1 < ret)
			{
				ret = tmp + 1;
				flag = true;
			}
			
			vv[i] = tt;
		}
	}
	if(flag == false)
	{
		memo[msk][s] = 3000;
	}
	else
	{
		memo[msk][s] = ret;
	}
	return memo[msk][s];
}

int main()
{
	int i, j, k, n, a, b, tot;
	freopen("b-small-attempt1.in", "rt", stdin);
	freopen("b-small11.out", "wt", stdout);

	int inp, kase;
	scanf("%d", &inp);
	//long double pp = 0.1;

	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d", &n);
		memset(memo, -1, sizeof(memo));
		tot = n;
		data.clear();
		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			data.push_back(make_pair(a, b));
		}
		
		i = j = 0;
		int ret = go(0, 0, n, 0);
		if(ret > 300)
			printf("Case #%d: Too Bad\n", kase);
		else
			printf("Case #%d: %d\n", kase, ret);
	}
	return 0;
}

