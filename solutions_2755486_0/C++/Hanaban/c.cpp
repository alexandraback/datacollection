#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class att {
	public :
		int d, w, e, h;
		
		bool operator<(const att &b) const {
			return d < b.d;
		}
};

int main()
{
	int t;
	cin >> t;
	
	for (int c = 1; c <= t; ++c) {
		int n;
		cin >> n;
		vector<att> va;
		int maxw = 0, maxd = 0;
		
		for (int i = 0; i < n; ++i) {
			int d, ni, wi, ei, si, ddi, dpi, dsi;
			
			cin >> d >> ni >> wi >> ei >> si >> ddi >> dpi >> dsi;
			wi += 300;
			ei += 300;
			
			for (int j = 0; j < ni; ++j) {
				att a;
				a.d = d + ddi * j;
				a.w = wi + dpi * j;
				a.e = ei + dpi * j;
				a.h = si + dsi * j;
				va.push_back(a);
				maxw = max(maxw, a.e);
				maxd = max(maxd, a.d);
			}
		}
		sort(va.begin(), va.end() );
		vector<int> W(maxw + 1, 0), NW(maxw + 1, 0);
		int z = 0;
		for (int i = 0; i < va.size(); ++i) {
			bool ok = false;
			for (int j = va[i].w; j < va[i].e; ++j) {
				if (W[j] < va[i].h) {
					ok = true;
					NW[j] = max(NW[j], va[i].h);
				}
			}
			if (ok) {
				++z;
			} else {
			}
			if (i < va.size() - 1 && va[i].d < va[i + 1].d) {
				W = NW;
				NW = W;
			}
		}
				
		printf("Case #%d: %d\n", c, z);
	}
	
	return 0;
}
