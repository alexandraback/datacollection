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
#define pb push_back
#define mp make_pair
#define SIZE(i) ((int)(i.size()))


int m,n,j,k,l,i,o,p,__t,E,R,N,V[1000000],ans,pre[1000],suf[10000];

char ch;
void read(int &a)
{
	for (ch = getchar();(ch < '0' || ch > '9') && (ch != '-');ch = getchar());
	if (ch == '-') a = 0,__t = -1; else a = ch - '0',__t = 1;
	for (ch = getchar();ch >= '0' && ch <= '9';ch = getchar()) a = a * 10 + ch - '0';
	a *= __t;
}

int F[100][1000];

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);

	int cas;
	cin >> cas;
	for (int id = 1; cas --; id ++)
	{
		printf("Case #%d: ", id);
		
		cin >> E >> R >> N;
		for (int j = 1; j <= N; j ++)
			cin >> V[j];
		
		if (R > E)
			R = E;
		
		memset(F, -1, sizeof F);
		ans = 0;
		F[1][E] = 0;
		for (int j = 1; j <= N; j ++)
			for (int res_power = R; res_power <= E; res_power ++)
				if (F[j][res_power] != -1)
					for (int spend = 0; spend <= res_power; spend ++)
						F[j + 1][min(res_power + R - spend, E)] = max(F[j + 1][min(res_power + R - spend, E)], F[j][res_power] + V[j] * spend);
		for (int j = 0; j <= E; j ++)
			ans = max(ans, F[N + 1][j]);
		cout << ans << endl;
	}

}
