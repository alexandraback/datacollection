#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

#define inf 1023456789
#define linf 1023456789123456789ll
#define pii pair<int,int>
#define pipii pair<int, pii >
#define pll pair<long long,long long>
#define vint vector<int>
#define vvint vector<vint >
#define ll long long
#define pdd pair<double, double>

#define DEBUG
#ifdef DEBUG
#define db(x) cerr << #x << " = " << x << endl
#else
#define db(x)
#endif

int multi_matrix[4][4] = 
{
	{ 1, 2, 3, 4},
	{ 2,-1, 4,-3},
	{ 3,-4,-1, 2},
	{ 4, 3,-2,-1}
};

struct quaternion
{
	vint part;
	
	quaternion()
	{
		part = vint(4,0);
	}
	
	quaternion(char c)
	{
		part = vint(4,0);
		if(c == '1')part[0]++;
		if(c == 'i')part[1]++;
		if(c == 'j')part[2]++;
		if(c == 'k')part[3]++;
	}
};

quaternion operator*(quaternion a, quaternion b)
{
	quaternion res;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			int sign = 1;
			if(multi_matrix[i][j] < 0)sign = -1;
			res.part[multi_matrix[i][j] * sign -1] += a.part[i]*b.part[j]*sign;
		}
	}
	return res;
}

quaternion power(quaternion base, int exp)
{
	if(exp == 0)return quaternion('1');
	quaternion res = quaternion('1');
	if(exp % 2 == 1)res = base;
	return res * power(base*base, exp/2);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int testcase = 0; testcase<t; testcase++)
	{
		ll l,x;
		scanf("%lld %lld ",&l,&x);
		vector<char> input(l);
		quaternion whole('1');
		for(int i=0; i<l; i++)
		{
			scanf("%c",&input[i]);
			whole = whole * quaternion(input[i]);
		}
		quaternion pom = power(whole, x);
		if(pom.part[0] != -1)
		{
			printf("Case #%d: NO\n",testcase+1);
			continue;
		}
		int tl = min(l*x, l*9);
		vector<char> text(tl);
		for(int i=0; i<tl; i++)
		{
			text[i] = input[i%l];
		}
		
		bool mam_i = 0, mam_j = 0;
		int r = 0;
		quaternion cur('1');
		for(;r<tl; r++)
		{
			cur = cur*text[r];
			if(cur.part[1] == 1)
			{
				r++;
				mam_i = 1;
				break;
			}
		}
		
		cur = quaternion('1');
		for(;r<tl;r++)
		{
			cur = cur*text[r];
			if(cur.part[2] == 1)
			{
				mam_j = 1;
				break;
			}
		}
		
		if(mam_i && mam_j)
		{
			printf("Case #%d: YES\n",testcase+1);
		}
		else
		{
			printf("Case #%d: NO\n",testcase+1);
		}
		
	}
	return 0;
}