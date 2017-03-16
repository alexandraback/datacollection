#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;

string const name = "C";

int test, curTest, l, map[400][4], deg[4], used[10501];
long long x;
string s, s1;
vector<int> lPos[4], rPos[4];

void prepare()
{
	int oc[4] = {'1', 'i', 'j', 'k'};
	for(int i=0;i<4;++i)
		map['1'][i] = oc[i];

	int ic[4] = {'i', -('1'), 'k', -('j')};
	for(int i=0;i<4;++i)
		map['i'][i] = ic[i];

	int jc[4] = {'j', -('k'), -('1'), 'i'};
	for(int i=0;i<4;++i)
		map['j'][i] = jc[i];

	int kc[4] = {'k', 'j', -('i'), -('1')};
	for(int i=0;i<4;++i)
		map['k'][i] = kc[i];
}

void print(int v)
{
	if(v)
		printf("Case #%d: YES\n",++curTest,v);
	else
		printf("Case #%d: NO\n",++curTest);
}

int mul(int a, int b)
{
	int sign = 1;
	if(a < 0)
	{
		sign *= -1;
		a = -a;
	}

	if(b < 0)
	{
		sign *= -1;
		b = -b;
	}

	if(b == '1')
		b = 0;
	else
		if(b == 'i')
			b = 1;
		else
			if(b == 'j')
				b = 2;
			else
				b = 3;

	int r = map[a][b];
	/*if(a != b) 
		r = map[a][b];
	else
	{
		r = -49;
	}*/

	if(r < 0)
	{
		r = -r;
		sign *= -1;
	}
	return r * sign;
}

void calcDegs()
{
	int r = 49;
	deg[0] = 49;
	for(int i=1;i<4;++i)
	{
		for(int j=0;j<l;++j)
		{
			r = mul(r, s[j]);
		}
		deg[i] = r;
	}
}

int getRangeMul(int le, int ri)
{
	int r = 49;
	for(int i=le+1;i<ri;++i)
		r = mul(r, s[i]);
	return r;
}

void calcPoses()
{
	for(int i=0;i<4;++i)
	{
		lPos[i].clear();
		for(int j=0;j<l;++j)
			used[j] = 0;

		int cur = deg[i];
		for(int j=0;j<l;++j)
		{
			cur = mul(cur, s[j]);
			if(cur == 'i')
			{
				if(used[j])
					continue;
				for(int k=j;k<l;k+=5)
					used[k] = 1;
				lPos[i].push_back(j);
			}
		}
	}

	for(int i=0;i<4;++i)
	{
		rPos[i].clear();
		for(int j=0;j<l;++j)
			used[j] = 0;

		int cur = deg[i];
		for(int j=l-1;j>=0;--j)
		{
			cur = mul(s[j], cur);
			if(cur == 'k')
			{
				if(used[j])
					continue;
				for(int k=j;k>=0;k-=5)
					used[k] = 1;
				rPos[i].push_back(j);
			}
		}
	}
}

int calc(int ld, int lp, int rd, int rp)
{
	int r = 0;
	long long d =  x - ld - rd;
	if(d <= 0) 
		return 0;

	if(d == 1)
	{
		r = getRangeMul(lp, rp);
		return (r == 'j');
	}

	r = getRangeMul(lp, l);
	r = mul(r, deg[(d-2)%4]);
	r = mul(r, getRangeMul(-1, rp));

	return r == 'j';
}

int main()
{
	freopen((name + ".in").c_str(),"r",stdin);
	freopen((name + ".out").c_str(),"w",stdout);

	prepare();

	cin >> test;
	while(test--)
	{
		cin >> l >> x >> s;
		calcDegs();
		calcPoses();

		int ans = 0;
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j) 
			{
				for(int i1=0;i1<lPos[i].size();++i1)
				{
					for(int j1=0;j1<rPos[j].size();++j1)
					{
						ans = max(ans, calc(i, lPos[i][i1], j, rPos[j][j1]));
					}
				}
			}
		}
		
		print(ans);
	}

	return 0;
}
