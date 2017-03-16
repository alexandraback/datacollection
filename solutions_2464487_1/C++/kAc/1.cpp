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


int m,n,j,k,l,i,o,p,__t;

char ch;
void read(int &a)
{
	for (ch = getchar();(ch < '0' || ch > '9') && (ch != '-');ch = getchar());
	if (ch == '-') a = 0,__t = -1; else a = ch - '0',__t = 1;
	for (ch = getchar();ch >= '0' && ch <= '9';ch = getchar()) a = a * 10 + ch - '0';
	a *= __t;
}

bool check(LL r, LL t, LL mid)
{
	LL ret = 2LL * r * mid;
	if (ret >= t)
		return 0;
	ret += (2LL + 4LL * (mid - 1LL)) * mid / 2;
	if (ret > t)
		return 0;
	return 1;
}


int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	
	int cas;
	scanf("%d", &cas);
	for (int id = 1; cas --; id ++)
	{
		printf("Case #%d: ", id);
		LL r, t, ans = 1;
		cin >> r >> t;
		for (LL lef = 1, rig = min((t) / (2LL * r), 1500000000LL); lef <= rig; )
		{
			LL mid = (lef + rig) / 2;
			if (check(r, t, mid)) 
				ans = mid, lef = mid + 1;
			 else 
				rig = mid - 1;
		}
		cout << ans << endl;
	}
}
