#include <bits/stdc++.h>

#define ll long long
#define __(x) cout << #x << " : " << x << endl;
#define out(a, i, n) for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

#define INOUT
#define TIME	

using namespace std;

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x)
{
	s << "(" << x.first << ", " << x.second << ")";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &v)
{
	s << "[";
	bool was = false;
	for (auto it : v)
	{
		if (was) 
		{
			s << ", ";
		}
		was = true;
		s << it;
	}
	s << "]";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x)
{
	s << "{";
	bool was = false;
	for (auto it : x)
	{
		if (was)
		{
			s << ", " << endl;
		}
		was = true;
		s << it;
	}
	s << "}";
	return s;
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const map<U, V> &m)
{
	s << "{";
	bool was = false;
	for (auto it : m)
	{
		if (was)
		{
			s << ", " << endl;
		}
		was = true;
		s << it.first << ": " << it.second;
	}
	s << "}";
	return s;
}

struct choice
{
	int a, b, c;
	choice(int a, int b, int c) : a(a), b(b), c(c){};

	void print() 
	{
		printf("%d %d %d\n", a, b, c);
	}
};

void print(int test, int ans)
{
	cout << "Case #" << test << ": " << ans << endl;
	//printf("Case #%d: %d\n", test, ans);
}



int main()
{
#ifdef INOUT
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	
	int tests;
	cin >> tests;
	ll ans = 0;
	for (int test = 1; test <= tests; test++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vector <choice> out; 
		vector < map < pair<int, int>, int > > v;
		v.resize(10);
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				for (int k = 1; k <= c; k++)
				{
					if (v[3][mp(i, j)] < d &&
						v[5][mp(i, k)] < d && 
						v[6][mp(j, k)] < d)
					{
						v[3][mp(i, j)]++;
						v[5][mp(i, k)]++;
						v[6][mp(j, k)]++;
						out.pb(choice(i, j, k));
					}
				}
			}
		}
		print(test, out.size());
		for (auto it : out)
		{
			it.print();
		}
	}

#ifdef TIME
	cerr << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
