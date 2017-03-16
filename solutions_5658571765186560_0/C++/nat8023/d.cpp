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
int j,k,l,i,o,p,__t;
int m, n, x;
char ch;
void read(int &a) {
	for (ch = getchar();(ch < '0' || ch > '9') && (ch != '-');ch = getchar());
	if (ch == '-') a = 0,__t = -1; else a = ch - '0',__t = 1;
	for (ch = getchar();ch >= '0' && ch <= '9';ch = getchar()) a = a * 10 + ch - '0';
	a *= __t;
}



int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);

	int cas, result;
	cin >> cas;
	

	for (int id = 1; id <= cas; id ++) {
		cin >> x >> n >> m;
		result = 0;

		if (n * m % x != 0)
			result = 1;
		if (x >= 3 && (min(n, m) <= x - 2))
			result = 1;

		printf("Case #%d: %s\n", id, result == 1 ? "RICHARD" : "GABRIEL");
	}

	//fclose(stdin); fclose(stdout);
}
