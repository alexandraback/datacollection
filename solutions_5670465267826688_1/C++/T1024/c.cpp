#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int mat[4][4] = {
	{1, 2, 3, 4},
	{2,-1, 4,-3},
	{3,-4,-1, 2},
	{4, 3,-2,-1},
};

int mult(int a, int b)
{
	int q = mat[abs(a)-1][abs(b)-1];
	q *= (0 < a*b ? 1 : -1);
	return q;
}

int main() {
	int t;
	static int sq[240001];
	
	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		string s0, s;
		int l;
		ll x, xx;
		cin >> l >> xx;
		x = xx % 12;
		if(12 <= xx)
			x += 12;
		cin >> s0;
		for(int i=0; i<l; ++i)
		{
			if(s0[i] == 'i')
				s0[i] = 2;
			else if(s0[i] == 'j')
				s0[i] = 3;
			else if(s0[i] == 'k')
				s0[i] = 4;
		}
		for(int i=0; i<x; ++i)
		{
			s += s0;
		}
		
		l *= x;
		
		//cout << "si: ";
		int q = 1;
		for(int i=0; i<l; ++i)
		{
			q = mult(q, s[i]);
			sq[i] = q;
			//cout << q << " ";
		}
		//cout << "\n";
		
		bool ok = false;
		if(sq[l-1] == -1)
		{
			int i2;
			for(i2=l-1; 0<i2; --i2)
			{
				if(sq[i2] == 4)
					break;
			}
			
			for(int i1=0; i1<i2 && !ok; ++i1)
			{
				int si = sq[i1];
				if(si == 2)
					ok = true;
			}
		}
		
		cout << "Case #" << tt << ": " << (ok ? "YES" : "NO") << "\n";
	}

	return 0;
}
