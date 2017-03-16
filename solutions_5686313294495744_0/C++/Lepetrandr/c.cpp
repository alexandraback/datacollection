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
#include <cassert>

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
	// freopen("c.in","r",stdin);
	freopen("C-small-attempt0.in","r",stdin);
	freopen("c.out","w",stdout);
}


int id(string s, std::map<string, int>& m) {
    if (m.find(s) != m.end()) return m[s];
    int ret = m.size();
    return m[s] = ret;
}

int m[20][2];

int sol(){
    int n;
    cin >> n;
    assert(n <= 16);
    std::map<string, int> w0, w1;
    string s0, s1;
    
    FOR(i,0,n-1) {
        cin >> s0 >> s1;
        m[i][0] = id(s0, w0);
        m[i][1] = id(s1, w1);
    }
    
    int res = 0;
    FOR(mask,0,(1<<n) - 1) {
        vector<bool> v0(n, false);
        vector<bool> v1(n, false);
        FOR(i, 0, n - 1) {
            if (mask & (1<<i)) {
                v0[m[i][0]] = true;
                v1[m[i][1]] = true;
            }
        }
        bool ok = true;
        int fakers = 0;
        FOR(i, 0, n-1) {
            if ((mask & (1 << i)) == 0) {
                if (!v0[m[i][0]] || !v1[m[i][1]]) {
                    ok = false;
                    break;
                }
                ++fakers;
            }
        }
        if (ok && fakers > res) res = fakers;
    }
    return res;
}
int main()
{
	init();
    int T;
    cin >> T;
    FOR(t,1,T) {
        std::cout << "Case #" << t << ": " << sol() << std::endl;
    }
	return 0;
}