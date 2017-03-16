#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),e.end()

int n;
vector<pair<string,string> > vec;
set<string> f,s;

int calc()
{
	f.clear();
	s.clear();
	forn(i,n)
	{
		f.insert(vec[i].first);
		s.insert(vec[i].second);
	}
	int res = max(f.size(),s.size());
	return n-res;
}

int main()
{
	int casos;
	cin >> casos;
	for(int casito=1;casito<=casos;casito++)
	{
		cin >> n;
		vec.resize(n);
		forn(i,n)
			cin >> vec[i].first >> vec[i].second;
		printf("Case #%d: %d\n",casito,calc());
	}
}
