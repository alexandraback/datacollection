
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;

int k, l, s;
int bring = 0;
int check(string str, string y){
    //cout << str << ":" << y << endl;
    int res = 0;
    REP(i, str.size()){
        int f = 0;
        REP(j, y.size()){
            if(i + j >= str.size()) break;
            if(str[i + j] != y[j]) break;
            if(j == y.size() - 1) f = 1;
        }
        if(f)res++;
    }
    bring = max(bring, res);
    return res;
}

int dfs(string str, string x, string y){
    
    if(str.size() == s) return check(str, y);
    int res = 0;
    REP(i, x.size()){
        res += dfs(str + x[i], x, y);
    }
    return res;
}

int main(void){	
	int t;
    cin >> t;
    REP(tt, t){
        bring = 0;
        cin >> k >> l >> s;
        string x, y;
        cin >> x >> y;
        int ans = dfs("", x, y);
        int a = 1;
        while(s){
            a *= k;
            s--;
        }
        //cout << ans << ":" << a << ":" << bring << endl;
        cout << "Case #" << tt + 1 << ": ";
        printf("%.9lf\n", (double)bring - (double)ans / a);
    }
    

	return 0;
}

