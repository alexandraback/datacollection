#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <ctime>
#include <memory.h>

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,Be,En) for(int (i)=(Be);(i)<=(En);++(i))
#define DFOR(i,Be,En) for(int (i)=(Be);(i)>=(En);--(i))
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a,0,sizeof(a))

#define LL  long long
#define VI  vector<int>
#define PAR pair<int ,int> 

using namespace std;
void __never(int a){printf("\nOPS %d", a);}
void __die(int a){printf("%d",(a*a)/(a+a));}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();__die(0);}}


#define MN 10000005

int ord[MN + 10];
bool flag[MN];
int d[MN];

void init()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}

int rev(int a) {
    int res = 0;
    while (a > 0) {
        int c = a % 10;
        a /= 10;
        res = res * 10 + c;
    }
    return res;
}

void prepare() {
    int be, en;
    CLR(flag);
    flag[ord[be=en=1] = 1] = true;
    d[1] = 1;
    int cand[2];
    while (be <= en) {
        int cur = ord[be++];
        cand[0] = cur + 1;
        cand[1] = rev(cur);
        FOR(i,0,1) {
            if (cand[i] >= MN) continue;
            if (!flag[cand[i]]) {
                flag[cand[i]] = true;
                d[cand[i]] = d[cur] + 1;
                ord[++en] = cand[i];
            }
        }
    }
    // LL sum = 0;
    // FOR(i,1,1000000) {
        // sum += d[i];
    // }
    // std::cout << sum << std::endl;
}

int sol(int n){	
    ass(n < MN);
    return d[n];
    
}
int main()
{
    int T, n;
	init();
    prepare();
    cin >> T;
    FOR(t,1,T) {
        cin >> n;
        cout << "Case #" << t << ": " << sol(n) << std::endl;
    }
	return 0;
}