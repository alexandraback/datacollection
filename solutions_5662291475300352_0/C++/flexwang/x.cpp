#include <stdio.h>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

struct H{
	int s, t;
	H(int ss, int tt):s(ss), t(tt){}
	H(){}
};

int nh;
vector<H> hs;

int solve()
{
	if (hs.size() <= 1)
		return 0;

	if (hs[0].t == hs[1].t)
		return 0;

	if (hs[0].t > hs[1].t)
		swap(hs[0], hs[1]);




	////1.
	//if (hs[0].s == hs[1].s) {
		int max_t = max(hs[0].t, hs[1].t);
		int min_t = min(hs[0].t, hs[1].t);
		if ((360-hs[1].s)*hs[1].t < (360*2-hs[0].s)*hs[0].t)
			return 0;
		return 1;
	//}
	//if (hs[0].t > hs[1].t)
	//	swap(hs[0], hs[1]);


}

int main()
{
	freopen("D:\\gcj\\a\\a.txt", "r", stdin);
	freopen("D:\\gcj\\a\\r.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	for (int icase=1; icase<=ncase; icase++) {
		scanf("%d", &nh);
		hs.clear();
		for (int i=0; i<nh; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			for (int j=0; j<b; j++) {
				hs.push_back(H(a, c+j));
			}
			
		}
		printf_s("Case #%d: %d\n", icase, solve());

	}
	

	return 0;
}