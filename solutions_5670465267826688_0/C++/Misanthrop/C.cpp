#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// 1  i  j  k
// i -1  k -j
// j -k -1  i
// k  j -i  1

// i*j = k

int tab[5][5] =
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 3, 4 },
	{ 0, 2,-1, 4,-3 },
	{ 0, 3,-4,-1, 2 },
	{ 0, 4, 3,-2,-1 }
};

int q(char c)
{
	switch(c)
	{
		case 'i': return 2;
		case 'j': return 3;
		case 'k': return 4;
	}
	assert(0);
}

int mult(int a, int b)
{
	return (a*b > 0 ? 1 : -1)*tab[abs(a)][abs(b)];
}

bool solve(int l, int x, const string& s)
{
	int w = 1;
	vector<int> a(l);
	for(int i = 0; i < l; ++i) w = mult(w, a[i] = q(s[i]));
	int i = 0, t = 0, v = 1;
	while(v != 2)
	{
		v = mult(v, a[i++]);
		if(i == l)
		{
			if(x) --x; else return false;
			i = 0;
			if(++t > 4) return false;
		}
	}
	t = 0; v = 1;
	while(v != 3)
	{
		v = mult(v, a[i++]);
		if(i == l)
		{
			if(x) --x; else return false;
			i = 0;
			if(++t > 4) return false;
		}
	}
	v = 1;
	if(i)
	{
		if(x) --x; else return false;
		while(i != l) v = mult(v, a[i++]);
	}
	x %= 4;
	while(x--) v = mult(v, w);
	return v == 4;
}

int main()
{
	int T; cin >> T;
	string s;
	for(int t = 1; t <= T; ++t)
	{
		int l, x; cin >> l >> x >> s;
		cout << "Case #" << t << ": " << (solve(l, x, s) ? "YES" : "NO") << endl;
	}
}
