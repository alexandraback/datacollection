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

LL solve(int lef, int rig, LL lef_power, LL rig_power)
{
	if (lef > rig)
		return 0;
	int max_pos = lef;
	for (int i = lef + 1; i <= rig; i ++)
		if (V[i] > V[max_pos])
			max_pos = i;
	LL max_pos_power = lef_power + (LL(max_pos - lef)) * ((LL)R);
	if (max_pos_power > E)
		max_pos_power = E;
	
	LL min_pos_power = (rig_power) - ((LL)(rig - max_pos)) * ((LL)R);
	if (min_pos_power < 0)
		min_pos_power = 0;
	
	LL need_power = max_pos_power - min_pos_power;
	
	LL ret = ((LL)V[max_pos]) * need_power;
	
	LL p1 = solve(lef, max_pos - 1, lef_power, max_pos_power - R);
	
	LL p2 = solve(max_pos + 1, rig, min(max_pos_power - need_power + ((LL)R), ((LL)E)), rig_power);
	
	return ret + p1 + p2;
}

int main()
{
	freopen("2.in","r",stdin);
	freopen("22.out","w",stdout);

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
		
		cout << solve(1, N, E, 0) << endl;
		
		
	}

}
