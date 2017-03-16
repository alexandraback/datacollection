#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

int mul(int a, int b)
{
	int s = (a<0)? -1 : 1;
	s *= (b<0)? -1: 1;
	a = abs(a); b = abs(b);
	if(a == 1) return s * b;
	if(b == 1) return s * a;
	if(a == 2 && b == 2) return -s;
	if(a == 3 && b == 2) return -s*4;
	if(a == 4 && b == 2) return s*3;

	if(a == 2 && b == 3) return s*4;
	if(a == 3 && b == 3) return -s;
	if(a == 4 && b == 3) return -s*2;

	if(a == 2 && b == 4) return -s*3;
	if(a == 3 && b == 4) return s*2;
	if(a == 4 && b == 4) return -s*1;
	
}

int binpow(int a, int n)
{
	if(n==1)
		return a;
	if(n == 0)
		return 1;
	if(n&1) {int val = binpow(a, n / 2); return mul(a, mul(val, val));}
	int val = binpow(a, n / 2); return mul(val, val);
}

int compute(vector<int> v)
{
	int n = v.size();
	int val = v[0];
	for(int i = 1; i < n; ++i)
		val = mul(val, v[i]);
	return val;
}

bool ssimple(vector<int> v, int x)
{
	int n = v.size();
	vector<int> g(n * x);
	int m = n * x;
	for(int i = 0; i < m; ++i)
		g[i] = v[i % n];
	int val = 1;
	int wait = 2;
	//printf("Start ssimple for ");
	//for(int i = 0; i < m; ++i) printf("%d ", g[i]);
	//printf("\n");
	for(int i = 0; i < m; ++i)
	{
		val = mul(val, g[i]);
		if(val == wait)
			wait *= 2;
	}
	return (wait == 8);
}

bool shard(vector<int> v, int x)
{
	int n = v.size();
	int val = 1;
	bool flag = false;
	for(int i = 0; i < n * 4; ++i)
	{
		val = mul(val, v[i % n]);
		if(val == 2) flag = true;
	}
	if(!flag) return false;
	
	flag = false;
	val = 1;
	for(int i = n * 4 - 1; i >= 0; --i)
	{
		val = mul(v[i % n], val);
		if (val == 4) flag = true;
	}
	return flag;
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	cin >> T;
	for(int st = 0; st < T; ++st)
{
	int l, x;
	cin >> l >> x;
	string s;
	cin >> s;
	vector<int> v(l);
	for(int i = 0; i < l; ++i)
		if(s[i] == 1) v[i] = 1;
		else if(s[i] == 'i') v[i] = 2;
		else if(s[i] == 'j') v[i] = 3;
		else v[i] = 4;
	int val = compute(v);
	//printf("Val binpow = %d\n", val);
	val = binpow(val, x);
	//printf("Val binpow = %d\n", val);
	if(val != -1)
	{
		printf("Case #%d: NO\n" , st + 1);
		continue;
	}
	if( x < 9)
	{
		bool flag = ssimple(v, x);
		printf("Case #%d: %s\n", st + 1, (flag)?"YES":"NO");
	}
	else
	{
		
		bool flag = shard(v, x);
		printf("Case #%d: %s\n", st + 1, (flag)?"YES":"NO");
	}


}
}
