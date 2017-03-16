#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

#define FOR(I,A,B) for (int I=int(A);I<int(B);++I)
#define MEM(A,B) memset(A,B,sizeof(A));
#define CPY(A,B) memcpy(A,B,sizeof(B));
typedef __int64 LL;
const int N(1010);
int cnt[2 * N];
bool bo[N];
int q, n, ca;
int a[N], b[N];
vector<int> l;
bool cmp(int x, int y) {return b[x] > b[y];}
int main()
{
    freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	for (scanf("%d", &q); q; --q) {
	    scanf("%d", &n);
	    MEM(cnt, 0);
		FOR(i, 0, n) {
		   scanf("%d%d", &a[i], &b[i]);
		   cnt[b[i]] += 2;
		}
		MEM(bo, 0);
		int ans = n, s = 0;
		FOR(i, 0, 2 * n + 1) {
           if (i > s) {
              l.clear();
              FOR(j, 0, n)
                 if (!bo[j] && a[j] <= i - 1 && b[j] >= i) l.push_back(j);
              sort(l.begin(), l.end(), cmp);
              FOR(j, 0, l.size()) {
                 bo[l[j]] = true;
                 ++s; ++ans;
                 ++cnt[a[l[j]]]; --cnt[b[l[j]]];
                 if (i <= s) break;
              }
              if (i > s) {
                 ans = -1;
                 break;
              }
           } 
           s += cnt[i];
        }
		if (ans == -1) printf("Case #%d: Too Bad\n", ++ca);
		else printf("Case #%d: %d\n", ++ca, ans);
	}
	return 0;
}
