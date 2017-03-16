#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 1010;
const int mi = 19931117;
int r1[N], r2[N], s1[N], s2[N], rec[N];

bool comp1 (const int& a, const int& b)
{
	if (r1[a] != r1[b]) return r1[a] < r1[b];
	else return r2[a] > r2[b];
}
bool comp2 (const int& a, const int& b) { return r2[a] < r2[b]; }

int main ()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kas; scanf("%d", &kas);
	for (int kase = 1; kase <= kas; kase++)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d %d", &r1[i], &r2[i]), s1[i] = s2[i] = i, rec[i] = 0;
		sort(s1, s1 + n, comp1);
		sort(s2, s2 + n, comp2);
		s1[n] = s2[n] = n;
		r1[n] = r2[n] = mi; rec[n] = 0;
		int p1 = 0, p2 = 0, star = 0, res = 0;
		while (star < n * 2)
		{
			while (rec[s1[p1]] >= 1) ++p1;
			while (rec[s2[p2]] >= 2) ++p2;
			if (r1[s1[p1]] > star && r2[s2[p2]] > star)
			{
				res = -1;
				break;
			}
			if (r2[s2[p2]] <= star)
			{
				star += (2 - rec[s2[p2]]);
				rec[s2[p2]] = 2; ++res;
			}
			else
			{
				++star;
				rec[s1[p1]] = 1; ++res;
			}
		}
		if (res == -1) printf("Case #%d: Too Bad\n", kase);
		else printf("Case #%d: %d\n", kase, res);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
