#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

char x[9999];
char y[9999];
int n;
vector<string> s1, s2;
string a[9999];
string b[9999];
int aa[9999];
int bb[9999];
int an, bn;

#define INF 1040000000
#define MAX_V 3005
struct edge {        // to : 목적지, c : 용량 , r: 역변 정보 : ad[i][j] 의 역엣지 = ad[ad[i][j].to][ad[i][j].r]
	int to, c, r;
};

vector<edge> ad[MAX_V]; // 그래프 인접리스트
bool chk[MAX_V];        // DFS에서 방문 체크
int adn;
void inil()
{
	int i, j, k;
	for (i = 0; i < adn; i++)
		ad[i].clear();
	for (i = 0; i < adn; i++)
		chk[i] = false;
	adn = 0;
}

void add_edge(int v1, int v2, int c) 
{
	edge e1;
	e1.to = v2;
	e1.c = c;
	e1.r = ad[v2].size();
	ad[v1].push_back(e1);
	edge e2;
	e2.to = v1;
	e2.c = 0;
	e2.r = ad[v1].size()-1;
	ad[v2].push_back(e2);
}

int DFS(int s, int t, int f) {  // s -> t 경로탐색
	if (s == t) return f;
	chk[s] = true;
	for (int i = 0; i<ad[s].size(); i++) {
		edge &now = ad[s][i];
		if (now.c>0 && !chk[now.to]) {
			int ret = DFS(now.to, t, min(f, now.c));
			if (ret>0) {
				now.c -= ret;
				ad[now.to][now.r].c += ret;
				return ret;
			}
		}
	}
	return 0;
}

int network_flow(int s, int t) { // s->t 최대흐름
	int ret = 0, flow = -1;
	while (flow != 0) {
		memset(chk, 0, sizeof(chk));
		flow = DFS(s, t, INF);
		ret += flow;
	}
	return ret;
}
int main()
{
//	freopen("C-small-attempt0.in", "rt",stdin);
//	freopen("C-small-attempt0.out", "wt",stdout);
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.out", "wt", stdout);

	int t;
	int tv;
	tv = 1;
	scanf("%d", &t);
	while (t--)
	{
		int i, j, k;
		inil();
		scanf("%d", &n);
		s1.clear();
		s2.clear();
		for (i = 0; i < n; i++)
		{
			scanf("%s %s", x, y);
			a[i] = x;
			b[i] = y;
			s1.push_back(a[i]);
			s2.push_back(b[i]);
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		s1.erase(unique(s1.begin(), s1.end()), s1.end());
		s2.erase(unique(s2.begin(), s2.end()), s2.end());

		an = s1.size();
		bn = s2.size();
		for (i = 0; i < n; i++)
		{
			aa[i] = lower_bound(s1.begin(), s1.end(), a[i]) - s1.begin();
			bb[i] = lower_bound(s2.begin(), s2.end(), b[i]) - s2.begin();
		}

		adn = an + bn + 2;

		for (i = 0; i < n; i++)
		{
			add_edge(aa[i], an + bb[i], 1);
		}
		for (i = 0; i < an; i++)
		{
			add_edge(adn - 2, i, 1);
		}
		for (i = 0; i < bn; i++)
		{
			add_edge(an + i, adn - 1, 1);
		}

		printf("Case #%d: ", tv);
		int fl = network_flow(adn - 2, adn - 1);

		for (i = 0; i < ad[adn - 2].size(); i++)
		{
			edge &e = ad[adn - 2][i];
//			printf("sink : %d %d\n", e.to, e.c);
			if (e.c > 0) fl++;
		}
		for (i = 0; i < ad[adn - 1].size(); i++)
		{
			edge &e = ad[adn - 1][i];
	//		printf("tank : %d %d\n", e.to, e.c);
			if (e.c == 0) fl++;
		}
		printf("%d\n", n - fl);
		tv++;
	}
}