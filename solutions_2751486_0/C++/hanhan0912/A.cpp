/* hanhanw v1.2 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=(y); x<=(z); x++)
#define FORD(x,y,z) for(int x=(y); x>=(z); x--)
#define FLST(x,y,z) for(int x=(y); x; x=z[x])
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define SZ(x) ((int)x.size())
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

const int N = (int)1e8 + 5;

int n,ok[N],f[N],vow[300];
string s;

void solve(int T){
	LL ans=0;
	cin >> s >> n;
	int cnt=0;
	int lst=-1;
	for (int i=SZ(s)-1; i>=0; i--){
		if (!vow[(int)s[i]]){
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt >= n){
			ok[i]=1;
			lst=i;
		}
		f[i]=lst;
	}
	for (int i=0; i<SZ(s); i++){
		if (f[i] != -1)
			ans += (LL)SZ(s)-(f[i]+n-1);
	}

	printf("Case #%d: %I64d\n", T, ans);
}

int main(){
	MSET(vow,0);
	vow['a'] = vow['e'] = vow['i'] = vow['o'] = vow['u'] = 1;
	int nT; scanf("%d", &nT);
	for (int i=1; i<=nT; i++)
		solve(i);

	return 0;
}
