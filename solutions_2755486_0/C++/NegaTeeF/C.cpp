#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))

using namespace std;

struct TPole {
	int l, r, s;
	TPole () {}
	TPole (int L, int R, int S) {l = L, r = R, s = S;}
};

int h[2000]={0};
int h2[2000]={0};

vector<TPole> days[7000000];

int main () {
	int T;
	cin >> T;
	for (int tests = 0; tests < T; tests++) {
		printf ("Case #%d: ", tests+1);
		for (int i = 0; i < 7000000; i++) days[i].clear();
		for (int i = 0; i < 2000; i++) {h[i] = 0; h2[i] = 0;}
		int N;
		cin >> N;
		int result = 0;
		for (int q = 0; q < N; q++) {
			int d, n, l, r, s, del_d, del_p, del_s;
			cin >> d >> n >> l >> r >> s >> del_d >> del_p >> del_s;
			int nDay = d, nL = l, nR = r, nS = s;
			for (int i = 0; i < n; i++) {
				days[nDay].push_back(TPole(nL, nR, nS));
				nDay += del_d;
				nL += del_p;
				nR += del_p;
				nS += del_s;
			}
		}
		for (int q = 0; q < 7000000; q++) {
			int len = days[q].size();
			for (int i = 0; i < len; i++) {
				int l = days[q][i].l, r = days[q][i].r, s = days[q][i].s;
				for (int pos = l; pos <= r; pos++) {
					if (h[pos+1000] < s) {
						//cout << "Number " << result+1 << " " << l << " " << r << " " << s << endl;
						result++;
						break;
					}
					if (pos != r && h2[pos+1000] < s) {
						result++;
						break;
					}
				}
			}
			for (int i = 0; i < len; i++) {
				int l = days[q][i].l, r = days[q][i].r, s = days[q][i].s;
				for (int pos = l; pos <= r; pos++) {
					if (h[pos+1000] < s) h[pos+1000] = s;
					if (pos != r && h2[pos+1000] < s) h2[pos+1000] = s;
				}
			}
		}
		printf ("%d\n", result);
	}
}

