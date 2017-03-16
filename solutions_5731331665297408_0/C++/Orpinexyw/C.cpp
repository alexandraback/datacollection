#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//#include <map>

using namespace std;


int T, n, m;
string c[108];
vector<int> v[108];
int map[108][108];
bool vis[108], vv[108], inq[108];
void add(int a, int b)
{
	v[a].push_back(b);
}
bool cmp(int a, int b)
{
	return c[a] < c[b];
}
void dfs(int x)
{
    vv[x] = true;
    for (int i = 1; i <= n; i++) {
        if (map[x][i] && !vv[i]) {
            dfs(i);
        }
    }
}

bool can(int a, int b)
{
    memset(vv, 0, sizeof vv);
	dfs(a);
	return vv[b] == true;
}
bool check(int x)
{
    memset(vv, 0, sizeof vv);
	dfs(x);
    for (int i = 1; i <= n; i++) {
        if ((!vis[i] && !vv[i])) {
            return false;
        }
    }
    return true;
}

string bfs(int st)
{
	string ret;
	int q[10008], l = 0, r = 1,  pre;
	memset(vis, 0, sizeof vis);
	memset(inq, 0, sizeof inq);
	q[0] = st;inq[st] = true;vis[st] = true;pre = 0;
	while (l != r) {
		int x = q[l++];
		map[pre][x] = 0;vis[x] = true;
		ret += c[x];
		for (int i = 1; i <= n; i++) {
			if (map[x][i] && !inq[i]) {
				inq[i] = true;
				q[r++] = i;
			}
		}
		sort(q + l, q + r, cmp);
		for (int i = l; i < r; i++) {
			if (can(x, q[i]) && check(q[i])) {
				swap(q[l], q[i]);
				break;
			}
		}
		pre = x;
	}
	return ret;
}
void work()
{
	memset(map, 0, sizeof map);
	string minn = "99999";
	int pos;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin>>c[i];
		if (c[i] <= minn) {
			minn = c[i];
			pos = i;
		}
	}
	int a, b;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
 	}
	cout << bfs(pos) << endl;
}
int main()
{
		freopen("C.in", "r", stdin);
			freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		work();
	}
}
