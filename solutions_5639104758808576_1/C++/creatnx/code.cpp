#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define red(i, a, b) for(int i = a; i > b; i--)
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
const int N = 1e5 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const ll base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;


int n;
string s;


int main(){
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test;
    cin >> test;
    rep(ii, 1, test + 1){
        cin >> n >> s;
        int tol = 0;
        int res = 0;
        rep(i, 0, s.size()){
            int c = s[i] - '0';
            if (c > 0){
                if (tol >= i) tol += c;
                else{
                    res += i - tol;
                    tol = i + c;
                }
            }
        }
        printf("Case #%d: %d\n", ii, res);
    }
}
