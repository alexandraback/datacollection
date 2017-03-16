/* In the name of ALLAH, most gracious, most merciful */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <ios>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <queue>
#include <cassert>
#include <cmath>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;



#define MAX 1000010
string keys;
string pat;
int pre[MAX];
vector<int> res;
//int dp[MAX][256];
int getlen(int l, char c) {
    while (l && pat[l] != c)
        l = pre[l - 1];
    if (pat[l] == c)
        l++;

    return l;
}
void compute_pre() {
    pre[0] = 0;
    int l = 0;
    if (pat[0])
        for (int i = 1; pat[i]; ++i) {
            l = getlen(l, pat[i]);
            pre[i] = l;
        }
}

int S;

const int N = 103;
int dp1[N][N];

int solveMax(int idx, int match){
    //cout << idx << " " << match << endl;
    if(idx == S){
        return 0;
    }
    int& ret = dp1[idx][match];
    if(ret != -1) return ret;
    ret = -1e9;
    for(int i = 0; i < keys.size(); i++){
        char c = keys[i];
        int nextMatch = getlen(match, c);
        //cout << nextMatch << endl;
        int isMatch = 0;
        if(nextMatch == pat.size()){
            isMatch = 1;
            nextMatch = pre[nextMatch - 1];
        }
        ret = max(ret, solveMax(idx + 1, nextMatch) + isMatch);
    }
    return ret;
}

int Have;

double dp2[N][N];
bool vis[N][N];

double solveExp(int idx, int match){
    if(idx == S){
        return 0;
    }
    double& ret = dp2[idx][match];
    if(vis[idx][match]) return ret;
    vis[idx][match] = true;
    ret = 0;
    for(int i = 0; i < keys.size(); i++){
        char c = keys[i];
        int nextMatch = getlen(match, c);
        //cout << nextMatch << endl;
        int isMatch = 0;
        if(nextMatch == pat.size()){
            isMatch = 1;
            nextMatch = pre[nextMatch - 1];
        }
        ret += solveExp(idx + 1, nextMatch) + isMatch;
    }
    return ret = ret / keys.size();
}

int main()
{
    /*freopen("in.in", "w", stdout);
    cout << 2000 << endl;
    for(int i = 1; i <= 2000; i++){
        cout << i << endl;
    }
    return 0;*/
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int t, K, L;
    cin >> t;

    for(int T = 1; T <= t; T++){
        cin >> K >> L >> S;
        cin >> keys >> pat;
        compute_pre();
        for(int i = 0; i < pat.size(); i++){
            //cout << pre[i] << endl;
        }
        memset(dp1, -1, sizeof dp1);
        memset(vis, false, sizeof vis);
        Have = solveMax(0, 0);
        double exp = solveExp(0, 0);
        //cout << Have << " " << exp << endl;
        double ans;
        if(Have == 0){
            ans = 0;
        }else{
            ans = Have - exp;
        }
        cout << fixed << setprecision(9) << "Case #" << T << ": "<< ans << endl;
    }

}
