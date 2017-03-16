#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vs;

#define SIZE(x) ((int)(x.size()))
#define LET(var, val) auto var = (val)
#define FOR(k, a, b) for(auto k = (a); k < (b); ++k)
#define FORR(k, a, b) for(auto k = (a); k >= (b); --k)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(LET(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PF push_front

const int INF = 1000000001;
const double EPS = 10e-9;
const double PI = acos(-1.0);

ostringstream out;

struct City
{
	vi can_go;
	int zip_code;
};

City cities[100];
set<int> zipcodes;
bool zip_codes[100];

void DFS(int current)
{
	if (zip_codes[current] == true)
		out << cities[current].zip_code;
	else
		return;
	zip_codes[current] = false;
	FOREACH(i, cities[current].can_go)
	{
		DFS(*i);
	}
}

bool cmp(int a, int b)
{
	return (cities[a].zip_code < cities[b].zip_code);
}

bool is_better(int a, int b)
{
	int min = (SIZE(cities[a].can_go) < SIZE(cities[b].can_go) ? a : b);
	vector<int>::iterator j = cities[(min == a ? b : a)].can_go.begin();
	FOREACH(i, cities[min].can_go)
	{
		if (*i < *j)
			return true;
		else if (*i > *j)
			return false;
		++j;
	}
	return true;
}

void C()
{
	int N, M;
	int min = INF;
	int m;
	cin >> N >> M;
	REP(i, N)
		cities[i].can_go.clear();
	REP(i, N)
	{
		cin >> cities[i].zip_code;
		zip_codes[i] = true;
	}

	int a, b;
	REP(i, M)
	{
		cin >> a >> b;
		a--;
		b--;
		cities[a].can_go.push_back(b);
		cities[b].can_go.push_back(a);
	}
	REP(i, N)
		sort(ALL(cities[i].can_go), cmp);
	REP(i, N)
	{
		if (cities[i].zip_code < min)
		{
			min = cities[i].zip_code;
			m = i;
		}
		else if (cities[i].zip_code == min)
		{
			if (is_better(i, m))
			{
				min = cities[i].zip_code;
				m = i;
			}
		}
	}
	DFS(m);
	out << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	REP(i, t)
	{
		out << "Case #" << i + 1 << ": ";
		C();
	}

	cout << out.str();
	return 0;
}