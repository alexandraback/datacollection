#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound

const double eps = 1e-8;
const double pi = acos(-1.0);

int n, C[110], s[110], p[110], bl[510000], la[510000], ro[2501000], pr[2501000], now, flag;
double P[110];
vector <double> depart;

void dfs(int a, int b)
{
	bl[a] = b;
	for (int tmp = la[a]; tmp; tmp = pr[tmp])
		if (bl[ro[tmp]] == -1)
			dfs(ro[tmp], b ^ 1);
		else if (bl[ro[tmp]] == bl[a]) {
			flag = 0;
		}
}
void ins(int a, int b)
{
	//cout << a << ' ' << b << endl;
	now++;
	pr[now] = la[a];
	la[a] = now;
	ro[now] = b;
}
int index(int a, int b, int c)
{
	return a * 100 + b * 2 + c;
}
int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf(" %c %d%d", C + i, s + i, p + i);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (p[i] > p[j]) swap(C[i], C[j]), swap(s[i], s[j]), swap(p[i], p[j]);
		depart.clear();
		depart.PB(0);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (s[i] > s[j] && p[j] - p[i] >= 5)
					depart.PB((p[j] - p[i] - 5.) / (s[i] - s[j]));
				if (s[i] > s[j] && p[j] - p[i] >= -5)
					depart.PB((p[j] - p[i] + 5.) / (s[i] - s[j]));
			}
		sort(depart.begin(), depart.end());
		int ans = -1;
		int l = 0, r = depart.size();
		//r (int i = 0; i < r; i++)
//			cout << depart[i] << ' ';
	//	cout << endl;
		while (r - l > 1) {
			int mi = (l + r) / 2;
			//mi = 2;
			memset(la, 0, sizeof la); now = 0;
			for (int i = 1; i <= mi; i++) {
				double t = (depart[i - 1] + depart[i]) / 2.;
				for (int j = 0; j < n; j++) P[j] = p[j] + t * s[j];
				for (int j = 0; j < n; j++) {
					int un = 0;
					for (int k = 0; k < n; k++)	if (j != k && fabs(P[j] - P[k]) < 5 - eps) {
						ins(index(i, j, 0), index(i, k, 0));
						//cout << i << ' ' << j << ' ' << " to " << i << ' ' << k << endl;
						un = 1;
					}
					if (un) {
						ins(index(i, j, 0), index(i, j, 1));
						ins(index(i, j, 1), index(i - 1, j, 0));
						
						ins(index(i - 1, j, 0), index(i, j, 1));
						ins(index(i, j, 1), index(i, j, 0));
						//cout << "un " << i <<  ' ' << j << endl;
					}
				}
			}
			flag = 1;
			memset(bl, -1, sizeof bl);
			for (int j = 0; j < n; j++)
				bl[index(0, j, 0)] = (C[j] == 'R');
			for (int j = 0; j < n; j++)
				dfs(index(0, j, 0), bl[index(0, j, 0)]);
			for (int j = 0; j <= index(mi, n - 1, 1); j++)
				if (bl[j] == -1 && la[j] != 0) {
					dfs(j, 0);
					//cout << "!" << flag << endl;
				}
			//r (int j = 0; j <= index(mi, n - 1, 1); j++)
			//f (la[j] != 0)
			//cout << j << ' ' << bl[j] << endl;
			//out << endl;
			if (!flag) r = mi;
			else l = mi;
			
			//ut << mi << ' ' << flag << "!" << endl;
			//cout << "=========" << endl;
			//eak;
		}
		printf("Case #%d: ", ++ca);
		if (l == (int)depart.size() - 1)
			puts("Possible");
		else
			printf("%.9f\n", depart[l]);
	}
}
