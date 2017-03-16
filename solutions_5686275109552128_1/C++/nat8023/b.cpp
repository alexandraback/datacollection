#include <cstdio>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
//#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pint;
typedef pair<LL,LL> pll;
#define fi first
#define se second
typedef map<int,int> mapint;
typedef vector<int> vint;
typedef vector<vint> vintp;
#define rep(i,j,k) for (int i = (j);i <= (k);i ++)
#define repd(i,j,k) for (int i = (j);i >= (k);i --)
#define ran2 (rand() % 32000 * 32000 + rand() % 32000)
#define pb push_back
#define mp make_pair
#define SIZE(i) ((int)(i.size()))
int m,n,j,k,l,i,o,p,__t;
char ch;
void read(int &a) {
	for (ch = getchar();(ch < '0' || ch > '9') && (ch != '-');ch = getchar());
	if (ch == '-') a = 0,__t = -1; else a = ch - '0',__t = 1;
	for (ch = getchar();ch >= '0' && ch <= '9';ch = getchar()) a = a * 10 + ch - '0';
	a *= __t;
}

int a[11000];

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	int cas, ans;
	cin >> cas;
	

	for (int id = 1; id <= cas; id ++) {
		cin >> m;
		rep(i, 0, m - 1)
			cin >> a[i];

		ans = 0xafff;

		rep(i, 1, 1000) {
			int move = 0;

			rep(j, 0, m - 1) {
				if (a[j] != 0)
					move += (a[j] - 1) / i;
			}
			if (move + i < ans)
				ans = move + i;
		}


		printf("Case #%d: %d\n", id, ans);
	}

	//fclose(stdin); fclose(stdout);
}
