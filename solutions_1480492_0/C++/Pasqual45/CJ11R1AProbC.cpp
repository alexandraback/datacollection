#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;

namespace
{
struct Frac
{
	Frac(ll a=0, ll b=1) : m(a), n(b) { reduce(); }
	Frac operator+(const Frac& r) const
	{
		ll z = GCD(n,r.n); ll xd = n/z; ll yd = r.n/z;
		Frac ret(m * yd + r.m * xd, xd*yd*z); ret.reduce(); return ret;
	}
	Frac operator-(const Frac& r) const
	{
		ll z = GCD(n,r.n); ll xd = n/z; ll yd = r.n/z;
		Frac ret(m * yd - r.m * xd, xd*yd*z); ret.reduce(); return ret;
	}
	Frac operator*(const Frac& r) const
	{
		ll y = GCD(m,r.n); ll z = GCD(n,r.m); ll a=m/y, d=r.n/y, b=n/z, c=r.m/z;
		Frac ret(a*c, b*d); ret.reduce(); return ret;
	}
	Frac operator/(const Frac& r) const { Frac invr(r); invr.inv(); return (*this)*invr; }
	bool operator<(const Frac& r) const { Frac temp = *this - r; return temp.m < 0; }	
	bool operator>(const Frac& r) const { return r < (*this); }	
	bool operator==(const Frac& r) const { return m == r.m && n == r.n; }	
	
	ll m,n;
	void reduce() { if (n < 0) m*=-1, n*=-1; ll d = GCD(abs(m),n); m/=d; n/=d; if (n==0) m=1; }
	void inv() { swap(m, n); }
	static ll GCD(ll a, ll b) { return b==0 ? a : GCD(b,a%b); }
	string print() const { string ret; ostringstream s,t; s<<m; t<<n; return s.str() + "/" + t.str(); }

	// Fancier: +=, etc.
	Frac& operator+=(const Frac& r)
	{
		ll z = GCD(n,r.n); ll xd = n/z; ll yd = r.n/z;
		m *= yd; m += r.m * xd; n *= yd; reduce(); return *this;
	}
	Frac& operator-=(const Frac& r)
	{
		ll z = GCD(n,r.n); ll xd = n/z; ll yd = r.n/z;
		m *= yd; m -= r.m * xd; n *= yd; reduce(); return *this;
	}
	Frac& operator*=(const Frac& r)
	{
		ll y = GCD(m,r.n); ll z = GCD(n,r.m);
		m/=y; n/=z; m*=(r.m/z); n*=(r.n/y); return *this;
	}
	Frac& operator/=(const Frac& r)
	{
		inv(); operator*=(r); inv(); return *this;
	}
};

}

bool clash[51][51];

//int main12R1PC()
int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int N;
	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		fin >> N;
		char c;
		vector<int> S(N), P(N);

		int init(0);
		for (int i=0; i<N; ++i)
		{
			fin >> c >> S[i] >> P[i];
			if (c=='R')
				init |= (1<<i);
		}
		
		set<Frac> sTimes;
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				if (S[i] != S[j])
				{
					Frac t1(P[j]-P[i]-5, S[i]-S[j]);
					if (t1.m >= 0)
						sTimes.insert(t1);

					Frac t2(P[j]-P[i]+5, S[i]-S[j]);
					if (t2.m >= 0)
						sTimes.insert(t2);
				}

		vector<Frac> times(sTimes.begin(), sTimes.end());
		set<int> prev, next;
		prev.insert(init);

		vector<Frac> loc(N);
		int k;
		for (k=0; k<times.size(); ++k)
		{
			for (int i=0; i<N; ++i)
				loc[i] = Frac(P[i]) + times[k] * Frac(S[i]);

			memset(clash,0,sizeof(clash));
			for (int i=0; i<N; ++i)
			{
				bool canSwitch = true;
				for (int j=0; j<N; ++j)
				{
					if (i!=j)
					{
						Frac dist = loc[i] - loc[j];
						if (dist < Frac(5) && dist > Frac(-5))
						{
							canSwitch = false;
							clash[i][j] = true;
						}

						if (dist == Frac(-5) && S[i] > S[j])
							clash[i][j] = true;
						if (dist == Frac(5) && S[j] > S[i])
							clash[i][j] = true;
					}
				}

				if (canSwitch)
				{
					vector<int> temp;
					for (set<int>::const_iterator it = prev.begin(); it != prev.end(); ++it)
						temp.push_back(*it ^ (1<<i));
					prev.insert(temp.begin(), temp.end());
				}
			}

			for (set<int>::const_iterator it = prev.begin(); it != prev.end(); ++it)
			{
				int mask = *it;
				bool good = true;
				for (int i=0; i<N; ++i)
					for (int j=0; j<N; ++j)
						if (clash[i][j])
						{
							bool m1 = (mask & (1<<i)) != 0;
							bool m2 = (mask & (1<<j)) != 0;
							if (m1 == m2)
								good = false;
						}

				if (good)
					next.insert(mask);
			}

			next.swap(prev);
			next.clear();

			if (prev.empty())
				break;
		}

		if (k==times.size())
		{
			fout << "Case #" << zz << ": " << "Possible" << endl;
		}
		else
		{
			double result = double(times[k].m) / times[k].n;
			fout << "Case #" << zz << ": " << result << endl;
		}
		
	}

	return 0;
}