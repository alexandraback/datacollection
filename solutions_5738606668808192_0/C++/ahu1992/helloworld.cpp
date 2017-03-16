#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<numeric>
using namespace std;

typedef unsigned long long ulong;

struct newNumber
{
	int N;
	string s;
	ulong to_ullong(ulong base)
	{
		ulong b = 1;
		ulong res = 0;
		for (int i = 0; i < N; ++i)
			res = res*base + (s[i] - '0');
		return res;
	}
};

class Solution{
public:
	void solve(int N, int J)
	{
		newNumber n;
		n.N = N;
		n.s.resize(N);
		fill(n.s.begin(), n.s.end(), '0');
		n.s[0] = '1';
		n.s[n.N - 1] = '1';
		produceOneNumber(1, J, n);
	}
	const vector<vector<ulong>>& getNontrivalFactors() const
	{
		return res;
	}
	const vector<string>& getString() const
	{
		return vstr;
	}
private:
	vector<vector<ulong> > res;
	vector<string> vstr;
	bool isPrimer(ulong x, ulong& factor)
	{
		ulong factorMax = sqrt(static_cast<double>(x));
		for (factor = 2; factor <= factorMax; ++factor)
		{
			if (x%factor == 0)
				return false;
		}
		return true;
	}
	bool isCoinJam(newNumber& n)
	{
		ulong factor;
		vector<ulong> vec;
		for (int i = 2; i <= 10; ++i)
		{
			if (isPrimer(n.to_ullong(i), factor))
				return false;
			else
				vec.push_back(factor);
		}
		res.push_back(vec);
		vstr.push_back(n.s);
		return true;
	}
	void produceOneNumber(size_t idx,int& J,newNumber& n)
	{
		if (J <= 0)
			return;
		if (idx == n.N - 2)
		{
			if (isCoinJam(n))
				--J;
			if (J <= 0)
				return;
			n.s[n.N - 2] = '1';
			if (isCoinJam(n))
				--J;
			if (J <= 0)
				return;
			n.s[n.N - 2] = '0';
			return;
		}
		produceOneNumber(idx + 1, J, n);
		if (J <= 0)
			return;
		n.s[idx] = '1';
		produceOneNumber(idx + 1, J, n);
		if (J <= 0)
			return;
		n.s[idx] = '0';
	}
};

void f(string& s, int idx)
{
	if (idx == s.size() - 1)
	{
		cout << s << endl;
		s.back() = '1';
		cout << s << endl;
		s.back() = '0';
		return;
	}
	f(s, idx + 1);
	s[idx] = '1';
	f(s, idx + 1);
	s[idx] = '0';
}


int main()
{
	//ifstream in("A-large.in");
	//ofstream out("large_output.out");
	istream& in = cin;
	ostream& out = cout;
	int T;
	in >> T;
	int N, J;
	for (int i = 1; i <= T; ++i)
	{
		Solution A;
		in >> N >> J;
		out << "Case #" << i << ":" << endl;
		A.solve(N, J);
		const vector<vector<ulong>>& res = A.getNontrivalFactors();
		const vector<string>& vstr = A.getString();	
		for (int idx = 0; idx < J; ++idx)
		{
			out << vstr[idx] << ' ';
			for (int j = 0; j < 9; ++j)
				out << res[idx][j] << (j == 8 ? '\n' : ' ');
		}
	}
	return 0;
}