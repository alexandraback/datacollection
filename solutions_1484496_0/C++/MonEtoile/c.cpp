#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

//#define _INFILE		"C.in"
//#define _OUTFILE	"C.out"

#define _INFILE		"C-small-attempt0.in"
#define _OUTFILE	"C-small.out"

//#define _INFILE		"C-large.in"
//#define _OUTFILE	"C-large.out"


typedef long long ll;

void solve()
{
	int n;
	scanf("%d",&n);
	map<int, set<int> > m;
	bool found = false;

	for(int i=0; i<n; i++)
	{
		int t;
		scanf("%d",&t);
		if (found) continue;
		vector<pair<int, set<int> > > v;
		set<int> st;
		st.insert(t);
		v.push_back(make_pair(t,st));
		
		for(auto it = m.begin(); it != m.end(); ++it)
		{
			int next = it->first + t;
			set<int> s = it->second;
			s.insert(t);

			auto it2 = m.find(next);
			if (it2 != m.end() && it2->second != s)
			{
				for(auto ii = s.begin(); ii != s.end(); ++ii)
				{
					if (ii != s.begin()) printf(" %d", *ii);
					else printf("%d", *ii);
				}
				printf("\n");

				for(auto ii = it2->second.begin(); ii != it2->second.end(); ++ii)
				{
					if (ii != it2->second.begin()) printf(" %d", *ii);
					else printf("%d", *ii);
				}
				printf("\n");

				found = true;
				break;
			}
			v.push_back(make_pair(next, s));
		}

		for(int i=0; i<v.size(); i++)
		{
			m[v[i].first] = v[i].second;
		}
	}
	if (!found)
		printf("Impossible\n");
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d:\n", i+1);
		solve();
	}
	return 0;
}

