#include <bits/stdc++.h>
using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 1e4;
map<pair<int, pii>, int> dp;
map<pair<map<pair<int, pii>, int>, pair<int, pii> >, char> dp2;
int k, j, p, s;
int taken[MAXN][3], top;
int ans[MAXN][3], topa;

pair<int, pii> _t(int j, int p, int s){
    return mp(j, mp(p, s));
}

bool can(int j, int p, int s){
    if(dp.find(_t(j, p, 0)) != dp.end()){
        if(dp[_t(j, p, 0)] == k) return 0;
    }
    if(dp.find(_t(j, 0, s)) != dp.end()){
        if(dp[_t(j, 0, s)] == k) return 0;
    }
    if(dp.find(_t(0, p, s)) != dp.end()){
        if(dp[_t(0, p, s)] == k) return 0;
    }
    return 1;
}

bool was;

void rec_sol(int jacket, int pants, int shirt){
    if(was) return;
    if(dp2.find(mp(dp, _t(jacket, pants, shirt))) != dp2.end()){
        return;
    }
    dp2[mp(dp, _t(jacket, pants, shirt))] = 1;
    if(jacket == j + 1){
        if(top > topa){
            topa = top;
            for(int i = 0; i < top; i++){
                for(int j = 0; j < 3; j++){
                    ans[i][j] = taken[i][j];
                }
            }
            was = 1;
        }
        return;
    }
    if(pants == p + 1){
        rec_sol(jacket + 1, 1, 1);
    }
    else if(shirt == s + 1){
        rec_sol(jacket, pants + 1, 1);
    }
    else{
        if(can(jacket, pants, shirt)){
            dp[_t(jacket, pants, 0)]++;
            dp[_t(jacket, 0, shirt)]++;
            dp[_t(0, pants, shirt)]++;
            taken[top][0] = jacket;
            taken[top][1] = pants;
            taken[top][2] = shirt;
            top++;
            rec_sol(jacket, pants, shirt + 1);
            top--;
            dp[_t(jacket, pants, 0)]--;
            dp[_t(jacket, 0, shirt)]--;
            dp[_t(0, pants, shirt)]--;
            if(dp[_t(jacket, pants, 0)] == 0){
                dp.erase(_t(jacket, pants, 0));
            }
            if(dp[_t(jacket, 0, shirt)] == 0){
                dp.erase(_t(jacket, 0, shirt));
            }
            if(dp[_t(0, pants, shirt)] == 0){
                dp.erase(_t(0, pants, shirt));
            }
        }
        rec_sol(jacket, pants, shirt + 1);
    }
}

void solve(){
    cin >> j >> p >> s >> k;
    top = 0;
    topa = 0;
    dp.clear();
    dp2.clear();
    was = 0;
    rec_sol(1, 1, 1);
    printf("%d\n", topa);
    for(int i = 0; i < topa; i++){
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
}

int main()
{
	#ifdef NASTYA
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
	int t = 1;
	cin >> t;
	int cs = 1;
	while(t--){
        printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}
