//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DR(i,a) for(int i = (a)-1; i >=0; i--)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define PB push_back
#define MP make_pair

#define F first
#define S second
#define RESET(c,x) memset(c,x,sizeof(c))
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()

#define REP(i,a) for(int i = 0; i < (a); i++)

#define sqr(x) ((x)*(x))
#define oo 1000000009
using namespace std;
/*************************TEMPLATE**********************************/
long long convertToNum(string s)
{
    long long val = 0; FR(i,s.size()) val = val * 10 + s[i] - '0';
    return val;
}
char bu[50];
string convertToString(int a) {
    sprintf(bu,"%d",a);
    return string(bu);
}
long long GCD(long long x,long long y)  {
    if (!x) return y; if (!y) return x;
    if (x == y) return x; if (x < y) return GCD(x,y%x); else return GCD(x%y,y);
}
long long POW(long long x,long long y,long long Base){
    if (!y) return 1; long long u = POW(x,y/2,Base);
    u = (u * u) % Base;
    if (y & 1) return (u * x) % Base; else return u;
}
void extended_euclid(long long A, long long B, long long &x,long long &y) {
    if (A == 1 && B == 0) {
        x = 1;
        y = 0;
        return;
    }
    if (A < B) extended_euclid(B,A,y,x);
    else {
        long long xx,yy;
        extended_euclid(A%B,B,xx,yy);
        x = xx;
        y = yy - (A/B)*xx;

    }
}
//newstate = (newstate-1) & oldstate
/*******************************CODE HERE***********************************/
int Trace[1<<20];
int Key[300];
int deg[203], T[300];
int a[203][203];
int N,K;
queue<int> q;
bool can_go(int state, int chest) {
    int key_type = T[chest];
    int cnt = Key[key_type];
    FR(i,N)
    if (state & (1 << i)) cnt += a[i][key_type];
    FR(i,N)
    if ((state & (1 << i))
        && (T[i] == key_type)) cnt--;
    return (cnt > 0);
}
void solve() {
    memset(Trace,-1,sizeof(Trace));
    while (!q.empty()) q.pop();
    q.push(0);
    while (!q.empty()) {
        int state = q.front(); q.pop();
        FR(i,N)
        if (!(state & (1 << i)) &&
        can_go(state, i)) {
            int newstate = state + (1 << i);
            if (Trace[newstate] == -1) {
                Trace[newstate] = i;
                q.push(newstate);
            }
        }
    }
    if (Trace[(1<<N)-1] == -1) cout << " IMPOSSIBLE" << endl;
    else {
        int state = (1<<N)-1;
        vector<int> res(0);
        while (state) {
            res.push_back(Trace[state]);
            state -= (1 << Trace[state]);
        }
        reverse(res.begin(),res.end());
        FR(i,res.size()) cout << " " << res[i] + 1;
        cout << endl;
    }
}
int main() {
    freopen("D_small.in","r",stdin);
    freopen("test.out","w",stdout);
	int ntest;
	cin >> ntest;
	FOR(test,1,ntest) {
		cout << "Case #" << test << ":";
		cin >> K >> N;
		memset(Key,0,sizeof(Key));
		memset(a,0,sizeof(a));
		int u;
		FOR(i,1,K) {
		    cin >> u;
		    Key[u]++;
		}
		FR(i,N) {
		    scanf("%d%d",&T[i],&deg[i]);
		    FOR(j,1,deg[i]) {
		        scanf("%d",&u);
		        a[i][u]++;
		    }
		}
		solve();
	}
    return 0;
}
