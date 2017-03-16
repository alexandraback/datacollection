#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <time.h>
using namespace std;

typedef long long LL;

const double eps = 1e-6;
const double INF = 100000000.0;
const int maxn = 55;

struct node
{
	int op;
	double s, p;
} a[maxn], b[maxn];
int n;
double Ans;

double ABS(double X) {
	return (X>0)?X:-X;
}

double TimeCanGo()
{
	double Ans = INF, temp;
	for (int i = 1; i <= n; i++) 
		for (int j = i+1; j <= n; j++)
			if (a[i].op == a[j].op) {
				if (ABS(a[i].p-a[j].p) < 5.0) return 0.0;
				if (a[i].s!=a[j].s) {
					if (a[i].s<a[j].s && a[i].p>a[j].p) Ans = min(Ans, (double)(a[i].p-a[j].p-5)/(a[j].s-a[i].s) );
					if (a[i].s>a[j].s && a[i].p<a[j].p) Ans = min(Ans, (double)(a[j].p-a[i].p-5)/(a[i].s-a[j].s) );
				}
			}
	return Ans;
}

void LastP(double& Ans, bool bj)
{
	Ans = INF;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
		if (i!=j) {
			if (ABS(a[i].p-a[j].p) < 5.0) {
				if (bj) {
					Ans = 0.0;
					return;
				} else continue;
			}
			if (a[i].s!=a[j].s) {
				if (a[i].s<a[j].s && a[i].p>a[j].p) Ans = min(Ans, (double)(a[i].p-a[j].p-5)/(a[j].s-a[i].s) );
				if (a[i].s>a[j].s && a[i].p<a[j].p) Ans = min(Ans, (double)(a[j].p-a[i].p-5)/(a[i].s-a[j].s) );
			}
		}
	if (Ans > INF - eps) Ans = 0.0;
}

bool canChange(int k)
{
	for (int i = 1; i <= n; i++)
		if (i!=k && a[i].op!=a[k].op && (ABS(a[i].p-a[k].p)<5)) return false;
	return true;
}

void dfs(int h, double TTTT)
{
	double Temp = TimeCanGo();
	if (Temp+TTTT > Ans) Ans = Temp + TTTT;
	if (Ans > INF-eps) return;
	//if (Temp < eps) return;
	
	double TT;
	LastP(TT, h<5);
	if (TT < eps) TT = Temp / 2.0;
	if (TT > eps) {
		for (int i = 1; i <= n; i++) {
			a[i].p += a[i].s*TT;
		}
		TTTT += TT;
	}

	if (h > 20) return;

	for (int i = 1; i <= n; i++) {
		int x = rand()%2;
		if (x == 0 && canChange(i)) {
			a[i].op = 1-a[i].op;
		}
	}
	dfs(h+1, TTTT);
}

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C_S1.out", "w", stdout);

	srand((unsigned)time(NULL));
	int TextN, TT = 0;
	char ch;
	cin >> TextN;
	while (TextN--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> ch >> a[i].s >> a[i].p;
			if (ch=='L') a[i].op = 0;
			else a[i].op = 1;
			b[i] = a[i];
		}
		cout << "Case #" << ++TT << ": ";
		Ans = TimeCanGo();
		if (Ans >= INF-eps) {
			cout << "Possible" << endl;
		} else {
			for (int T = 1; T <= 10000; T++) {
				for (int i = 1; i <= n; i++) a[i] = b[i];
				dfs(0, 0);
			}
			if (Ans >= INF-eps) cout << "Possible" << endl;
			else printf("%.5lf\n", Ans);
		}
	}
	
	return 0;
}