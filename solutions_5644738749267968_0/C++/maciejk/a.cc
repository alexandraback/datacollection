
#include<algorithm>
#include<cassert>
#include<cstdio>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#include<stack>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4) { a4 = in(a4, b4); }
#define maxn 1005
bool done[maxn];
int main(){
    int cas;
    cin >> cas;
    fup(c, 1, cas) {
        int n;
        cin >> n;
        vector<pair<string, int> > t;
        fup(i, 1, n) {
            string x; cin >> x; while (siz(x) < 8) x += "0";
            t.PB(MP(x, 0));
        }

        fup(i, 1, n) {
            string x; cin >> x; while (siz(x) < 8) x += "0";
            t.PB(MP(x, 1));
        }
        CLR(done);
        sort(ALL(t));
        //debugv(a);
        //debugv(b);
        stack<int> u;
            int x = 0;
        FORE(it, t) {
         //   cout << it -> FI << " " << it -> SE << endl;
            int a = it -> SE;
            if (a == 0) u.push(0);
            else if (!u.empty() && u.top() == 0) u.pop(), ++x;
        }
        while (!u.empty()) u.pop();
        int y = 0;

        FORE(it, t) {
        //    cout << it -> FI << " " << it -> SE << endl;
            int a = it -> SE;
            if (a == 1) u.push(1);
            else if (!u.empty() && u.top() == 1) u.pop(), ++y;
        }
        printf("Case #%d: %d %d\n", c, y, n - x);
    }

    return 0;
}

