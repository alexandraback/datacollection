#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

typedef long long LL;

const int maxn = 1000 + 10;
struct node
{
	int a, b;
} c[maxn];
bool mark[maxn];
int Ans, n, m, now;

bool cmp(node A, node B)
{
	return (A.b<B.b || (A.b==B.b && A.a<B.a));
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B_S.out", "w", stdout);
	
	int TextN, TT = 0;
	bool bj;
	cin >> TextN;
	while (TextN--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> c[i].a >> c[i].b;
		sort(c+1, c+1+n, cmp);
		
		m = 0, now = 0, Ans = 0;
		memset(mark, 0, sizeof(mark));
		while (1) {
			if (m == n) break;
			for (int i = m+1; i <= n; i++) 
			if (c[i].b <= now) {
				Ans++;
				if (!mark[i]) now += 2;
				else now++;
				m++;
				mark[i] = true;
			}
			if (m == n) break;
			bj = false;
			for (int i = n; i >= 1; i--) 
				if (!mark[i] && c[i].a <= now) {
					mark[i] = true;
					now++;
					Ans++;
					bj = true;
					if (c[m+1].b <= now) break;
				}
			if (!bj) break;
		}
		cout << "Case #" << ++TT << ": ";
		if (m==n)  cout <<Ans << endl;
		else cout << "Too Bad" << endl;
	}
	return 0;
}
