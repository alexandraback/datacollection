#include <bits/stdc++.h>
using namespace std;

int rule_to[4][4] = {
	{0,1,2,3},
	{1,0,3,2},
	{2,3,0,1},
	{3,2,1,0}
};

int rule_neg[4][4] = {
	{0,0,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,0,1,1}
};

struct quaternion
{
	int what;
	int neg;
	quaternion()
	{
		what = 0;
		neg = 0;
	}
	quaternion(int w)
	{
		what = w;
		neg = 0;
	}
	quaternion operator *(quaternion t) const
	{
		quaternion ret(0);
		ret.what = rule_to[what][t.what];
		ret.neg = (neg + t.neg + rule_neg[what][t.what]) % 2;
		return ret;
	}
}One(0), I(1), J(2), K(3);

long long len, n;
quaternion x[100000];
string s;

quaternion power(quaternion q, long long e)
{
	quaternion ret(0);
	while(e)
	{
		if(e&1) ret = ret * q;
		q = q * q;
		e /= 2;
	}
	return ret;
}

bool check(quaternion all)
{
	//for(int i = 1; i <= n; i++)
	//	all = all * x[i];
	//cout << all.what << " " << all.neg << endl;
	if(all.what != 0 || all.neg != 1)
		return false;
	int leftBest = 100000000, rightBest = -1;
	quaternion t(0);
	for(int i = 1; i <= n; i++)
	{
		t = t * x[i];
		if(t.what == 1 && t.neg == 0)
		{
			leftBest = i;
			break;
		}
	}
	t = quaternion(0);
	for(int i = n; i >= 1; i--)
	{
		t = x[i] * t;
		if(t.what == 3 && t.neg == 0)
		{
			rightBest = i;
			break;
		}
	}

	return leftBest < rightBest;
}


void solve()
{
	cin >> len >> n;
	
	string t;
	cin >> t;
	s = "";

	quaternion temp(0);
	for(int i = 1; i <= len; i++)
	{
		if(t[i-1] == 'i')
			temp = temp * I;
		if(t[i-1] == 'j')
			temp = temp * J;
		if(t[i-1] == 'k')
			temp = temp * K;
	}
	temp = power(temp, n);

	n = min(n, 16LL);

	for(int i = 1; i <= n; i++)
		s += t;
	n = len * n;
	for(int i = 1; i <= n; i++)
	{
		if(s[i-1] == 'i')
			x[i] = I;
		if(s[i-1] == 'j')
			x[i] = J;
		if(s[i-1] == 'k')
			x[i] = K;
	}
	cout << (check(temp) ? "YES" : "NO") << endl;

}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	int start = clock();
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int ret = MAIN();
	#ifdef LOCAL_TEST
		cout << "[Finished in " << clock() - start << " ms]" << endl;
	#endif
	return ret;
}
