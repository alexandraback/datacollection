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
#include<cassert>
#include<algorithm>

using namespace std;

//#define _INFILE		"B.in"
//#define _OUTFILE	"B.out"

#define _INFILE		"B-small-attempt3.in"
#define _OUTFILE	"B-small.out"

//#define _INFILE		"B-large.in"
//#define _OUTFILE	"B-large.out"


typedef long long ll;


string solve()
{
	int n;
	scanf("%d",&n);
	vector<pair<int, pair<int, int> > > v1;
	vector<pair<int, pair<int, int> > > v2;
	vector<int> v;
	vector<pair<int, int> > vv;

	for(int i=0; i<n; i++)
	{
		int s1, s2;
		scanf("%d%d",&s1,&s2);
		assert(s1 <= s2);
		v.push_back(0);
		vv.push_back(make_pair(s1, s2));
	}
	int p1 = 0, p2 = 0;

	int cur_star = 0;
	int cnt = 0;

	while(cur_star < n * 2)
	{
		int pos = -1;
		int s1 = 0, s2 = 0;
		for(int i=0; i<n; i++)
		{
			if (v[i] < 2 && vv[i].second <= cur_star)
			{
				if (pos == -1 || s1 < vv[i].first) {
					pos = i;
					s1 = vv[i].first;
				}
			}

		}
		if (pos != -1)
		{
			cur_star += 2 - v[pos];
			v[pos] = 2;
			cnt++;
			continue;
		}

		pos = -1;
		for(int i=0; i<n; i++)
		{
			if (v[i] < 1 && vv[i].first <= cur_star)
			{
				if (pos == -1 || s2 < vv[i].second) {
					pos = i;
					s2 = vv[i].second;
				}
			}

		}
		if (pos != -1)
		{
			cur_star ++;
			v[pos] = 1;
			cnt++;
			continue;
		}
		
		return "Too Bad";
	}

	assert(cur_star == n * 2);
	assert(cnt <= n * 2);
	char buffer[20];
	sprintf(buffer,"%d",cnt);

	return (string)buffer;
}


int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d: %s\n", i+1, solve().c_str());
	}
	return 0;
}

