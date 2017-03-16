/*
  ID: nigo1
  LANG: C++
  TASK: B
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>

#define TIME pf("%f", (double)clock()/CLOCKS_PER_SEC);

using namespace std;

int T;
int N, a, b;

vector <pair <int, int> > v;

bool used1[1024];
bool used2[1024];

int main()
{
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);

    scanf ("%d", &T);

    for (int test = 1; test <= T; test++) {
        printf ("Case #%d: ", test);

        scanf ("%d", &N);
        v.clear();

        for (int i = 0; i < N; i++) {
            scanf ("%d%d", &a, &b);
            v.push_back ( make_pair (b, a) );
        }

        sort (v.begin(), v.end());

        memset (used1, 0, sizeof used1);
        memset (used2, 0, sizeof used2);

        int curr = 0, ans = 0;

        while (true) {
            int i;

            for (i = N - 1; i >= 0; i--) {
                if (curr >= v[i].first and !used2[i]) {
                    break;
                }
            }

            if (i != -1) {
                if (used1[i]) curr++;
                else curr += 2;
                ans++;
                used1[i] = used2[i] = 1;
                continue;
            }

            for (i = N - 1; i >= 0; i--) {
                if (curr >= v[i].second and !used1[i]) {
                    break;
                }
            }
            if (i != -1) {
                curr++;
                ans++;
                used1[i] = 1;
            } else {
                break;
            }
        }
        for (int i = 0; i < N; i++)
            if (used2[i] == 0) {
                ans = -1;
                break;
            }
        if (ans == -1) printf ("Too Bad\n");
        else printf ("%d\n", ans);
    }

    return 0;
}
