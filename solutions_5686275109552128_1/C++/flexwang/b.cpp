#include <stdio.h>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <utility>


using namespace std;

int d;
vector<int> p;

inline int get_max(vector<int>& v)
{
	int ans = 0;
	for (int i=1; i<v.size(); i++)
		if (v[ans] < v[i])
			ans = i;
	return ans;
}

inline int cut(int x, int t) {
	if (x <= t) return 0;
	int ans = (x/t+((x%t!=0)?1:0))-1;
	return ans;
}
inline int solve(vector<int> v)
{
	int xi = v[get_max(v)];
	int ans = INT_MAX;
	for (int i=1; i<=xi; i++) {
		int la = i;
		for (int j=0; j<v.size(); j++)
			la += cut(v[j], i);
		ans = min(ans, la);
	}
	return ans;
}

int main()
{
	int ncase; 
	scanf("%d", &ncase);
	for (int icase=1; icase <= ncase; icase++) {
		scanf("%d", &d);
		p.resize(d);
		for (int i=0; i<d; i++)
			scanf("%d", &p[i]);
		printf("Case #%d: %d\n", icase, solve(p));
	}
	return 0;
}