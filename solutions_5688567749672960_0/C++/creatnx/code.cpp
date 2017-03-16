#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define red(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define RED true
#define BLACK false
#define pb push_back
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ii, int> iii;
typedef vector<int> vi;
const int N = 1e6 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const int base = 1e9 + 9;
const double pi = acos(-1);
const double ep = 1e-9;

int dp[N];

int rev(int x){
    int tmp = 0;
    while (x > 0){
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }
    return tmp;
}

int main(){
    freopen("A-small-attempt0 (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    rep(i, 0, N) dp[i] = inf;
    dp[1] = 1;
    for(int i = 1; i < N - 3; i++){
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        int c = rev(i);
        if (c < N)dp[c] = min(dp[c], dp[i] + 1);
    }
    //cout<<dp[23]<<endl;
    int test;
    cin >> test;
    rep(ii, 1, test + 1){
        int u;
        scanf("%d", &u);
        printf("Case #%d: %d\n", ii, dp[u]);
    }
}

// 1 2 3 4 5 6
// 6 5 4 3 2 1

