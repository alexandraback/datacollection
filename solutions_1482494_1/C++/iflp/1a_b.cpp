#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1024 * 2;
//c++11
int vis[N];
int star[N][2], f[N][N];

struct node
{
	int id, ty, nd;
	bool operator< (const node &b) const
	{
		if (nd == b.nd)
		{
			return star[id][1] < star[b.id][1];
		}
		return nd > b.nd;
	}
} V[N];

typedef vector<node> pque;

void solve ()
{
	int n, cv;
	static int kase = 0;
	scanf("%d", &n); cv = 0;
	static pque que1, que2;
	while (!que1.empty()) que1.pop_back();
	while (!que2.empty()) que2.pop_back();
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &star[i][0], &star[i][1]);
		que1.push_back((node){i, 0, star[i][0]});
		que2.push_back((node){i, 1, star[i][1]});
		vis[i] = 0;
	}
	int curstar = 0, res = 0;
	bool flag = false;
	que2.push_back((node){0, 0, 0x3f3f3f3f});
	que1.push_back((node){0, 0, 0x3f3f3f3f});
	sort(que1.begin(), que1.end());
	sort(que2.begin(), que2.end());
	while (1)
	{
		if (que2.back().nd > curstar)
		{
			if (!que1.empty() && que1.back().nd > curstar)
			{
				flag = false;
				break;
			}
			else
			{
				vector<node>::iterator it = que1.end(), best = it;
				--it; --best;
				while (it->nd <= curstar)
				{
					if (star[it->id][1] > star[best->id][1]) best = it;
					if (it == que1.begin()) break;
					--it;
				}
				++res;
				if (vis[best->id] != 2)
				{
					curstar += 1;
					vis[best->id] = 1;
				}
				que1.erase(best);
			}
		}
		else
		{
			++res;
			node t=que2.back();
			if (vis[t.id] == 1) curstar += 1;
			else curstar += 2;
			vis[t.id] = 2;
			que2.pop_back();
		}
		if (que2.back().nd == 0x3f3f3f3f)
		{ flag = true; break; }
	}
	if (flag) printf("Case #%d: %d\n", ++kase, res);
	else printf("Case #%d: Too Bad\n", ++kase);
}

int main ()
{
	freopen("in.txt", "r", stdin);
	int kase;
	scanf("%d", &kase);
	while (kase--) solve();
	return 0;
}
