#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i = (a); i != b; i++)
#define Rep(i,n) For(i,0,n)
#define debug(x) cout<<#x<<": "<<x<<endl
#define Pb push_back
#define Mp make_pair

template<class T>void show(T a,int n) {Rep(i,n)cout<<a[i]<<' ';cout<<endl;}
template<class T>void show(T a,int n,int m) {Rep(i,n){Rep(j,m)cout<<a[i][j]<<' ';cout<<endl;}}


int main() {
	int T;
	scanf("%d\n", &T);

	int n;
	vector<int> s, ret1, ret2;
	map<int,int> mii1, mii2;
	map<int,int>::iterator it1, it2;

	Rep(iT, T) {

		scanf("%d", &n);
		s.resize(n);
		Rep(i,n) {
			scanf("%d", &s[i]);
		}
		mii1.clear();
		mii2.clear();
		ret1.clear();
		ret2.clear();

		mii1[0] = 0;
		bool found = false;
		Rep(i,n) {
			mii2 = mii1;
			for (it1 = mii1.begin(); it1 != mii1.end(); ++it1) {
				if (mii1.count(it1->first + s[i]) > 0) {
					// find;
					int v = it1->first;
					ret2.push_back(s[i]);
					while (v != 0) {
						ret2.push_back(v - mii1[v]);
						v = mii1[v];
					}
					v = it1->first + s[i];
					while (v != 0) {
						ret1.push_back(v - mii1[v]);
						v = mii1[v];
					}
					found = true;
					break;
				} else {
					mii2[it1->first + s[i]] = it1->first;
				}
			}
			if (found) break;
			else mii1 = mii2;
		}

		sort(ret1.begin(), ret1.end());
		sort(ret2.begin(), ret2.end());
		vector<int> mk1 = ret1, mk2 = ret2;
		Rep(i,ret1.size()) Rep(j, ret2.size()) {
			if (ret1[i] == ret2[j]) {
				mk1[i] = mk2[j] = -1;
			}
		}
		vector<int> r1, r2;
		Rep(i,mk1.size()) {
			if (mk1[i] > 0) r1.push_back(mk1[i]);
		}
		Rep(i,mk2.size()) {
			if (mk2[i] > 0) r2.push_back(mk2[i]);
		}

		printf("Case #%d:\n", iT+1);
		if (found) {
			printf("%d", r1[0]);
			For(i, 1, r1.size()) {
				printf(" %d", r1[i]);
			}
			printf("\n%d", r2[0]);
			For(i, 1, r2.size()) {
				printf(" %d", r2[i]);
			}
			printf("\n");
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}
