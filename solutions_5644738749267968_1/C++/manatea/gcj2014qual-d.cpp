#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
const int MAX_N = 1000;
double w1[MAX_N], w2[MAX_N];
bool use1[MAX_N], use2[MAX_N];

void solve()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &w1[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &w2[i]);
	}
	sort(w1, w1 + N);
	sort(w2, w2 + N);

	//memset(use1, 0, sizeof(use1));
	memset(use2, 0, sizeof(use2));
	int w = 0;
	for (int i = 0; i < N; ++i) {
		double n = w1[i];
		bool kenwin = false;
		int jmin = -1;
		for (int j = 0; j < N; ++j) {
			if (use2[j] == false) {
				if (n < w2[j]) {
					kenwin = true;
					use2[j] = true;
					break;
				} else if (jmin == -1) {
					jmin = j;
				}
			}
		}
		if (kenwin == false) {
			w++;
			use2[jmin] = true;
		}
		//cout << jmin << endl;
	}

	memset(use1, 0, sizeof(use1));
	//memset(use2, 0, sizeof(use2));
	int dw = 0;
	for (int j = 0; j < N; ++j) {
		double k = w2[j];
		int imin = -1;
		bool nwin = false;
		for (int i = 0; i < N; ++i) {
			if (use1[i] == false) {
				if (k < w1[i]) {
					nwin = true;
					use1[i] = true;
					break;
				} else if (imin == -1) {
					imin = i;
				}
			}
		}
		if (nwin == false) {
			use1[imin] = true;
		} else {
			++dw;
		}
	}

	printf("%d %d", dw, w);
    return;
}

int main()
{
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 1; i <= nCases; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
