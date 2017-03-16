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
const int N = 1000 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const ll base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;

map<char, int> gt;
string s;
int r, l;

int a[4][4] = {
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1}
    };

void init(){
    gt['1'] = 1;
    gt['i'] = 2;
    gt['j'] = 3;
    gt['k'] = 4;
}

bool check(string s){
    string x ="";
    rep(i, 0, r){
        rep(j, 0, s.size())
            x = x +  s[j];
    }

    int tol = 1;
    rep(i, 0, x.size()){
        //cout<<abs(tol) - 1<<" "<<gt[x[i]] - 1<<endl;
        int pre = tol;
        tol = a[abs(tol)-1][gt[x[i]]-1];
        if (pre < 0) tol = -tol;

    }


    if (tol != -1) return false;
    bool has_i = (x[0] == 'i');
    tol = gt[x[0]];
    rep(i, 1, x.size() - 1){
        int pre = tol;
        tol = a[abs(tol)-1][gt[x[i]]-1];
        if (pre < 0) tol = -tol;
        //cout<<tol<<endl;
        if (tol == 4 && has_i) return true;
        if (tol == 2) has_i = true;
    }
    return false;
}

int main(){
    freopen("C-small-attempt2.in", "r", stdin);

    freopen("out.txt", "w", stdout);
    //freopen("in.txt", "r", stdin);
    init();
    int test;
    cin >> test;
    rep(ii, 1, test + 1){
        cin >> l >> r >> s;
        printf("Case #%d: ", ii);
        if (check(s)) printf("YES\n");
        else printf("NO\n");
    }

}
