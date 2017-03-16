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


void init()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("b.out","w",stdout);
}

VI v;
int sol() {	
    int n = SZ(v);
    ass(n > 0);
    int Max = 0;
    FA(i, v) {
        if (Max < v[i]) {
            Max = v[i];
        }
    }
    int ans = Max;
    FOR(r, 1, Max - 1) {
        int tmp = r;
        FA(i, v) {
            tmp += (v[i] + r - 1)/r - 1;
        }
        if (tmp < ans) {
            ans = tmp;
        }
    }
    return ans;
}
int main()
{
	init();
    int T, h;
    cin >> T;
    FOR(t,1,T) {
        cin >> h;
        v.resize(h);
        FA(i,v) {
            cin >> v[i];
        }
        cout << "Case #" << t << ": " << sol() << std::endl;
    }
	return 0;
}