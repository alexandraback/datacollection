#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include <cassert>
#include <vector>
#include <bitset>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf ("Case #%d: ", t++);
		int n;
		scanf("%d", &n);
		vector<pii> vt(n);
		vector<int> id(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &vt[i].first, &vt[i].second);
			id[i] = i;
		}
		int mark[1010] = {0};
		int coin = 0, r = 0;
		while (coin < 2*n) {
			int p = -1;
			for (int i = 0; i < vt.size(); i++) {
				if (coin >= vt[i].second) {p = i; break;}
			}
			if (p != -1) {
				//cout<<"2 "<<id[p]<<endl;
				coin += (mark[id[p]] ? 1 : 2);
				vt.erase(vt.begin() + p);
				id.erase(id.begin() + p);
				r ++;
			} else {
				p = -1;
				for (int i = vt.size() - 1; i >=0 ; i--) {
					if (coin >= vt[i].first) {
						if (p == -1 || vt[p].second < vt[i].second) {
							p = i;
						}
					}
				}
				if (p == -1) break;
				//cout<<"1 "<<id[p]<<endl;
				coin ++;
				mark[id[p]] = 1;
				r ++;
			}
		}
		if (coin == 2*n) {
			printf ("%d\n", r);
		} else puts("Too Bad");
	}
	return 0;
}
