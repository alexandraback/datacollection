#pragma comment(linker, ”/STACK:36777216“)
#include<bits/stdc++.h>

#define x first
#define y second
#define y0 hi1
#define y1 hi2
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(a) (a)*(a)
#define ld long double
#define all(a) (a).begin(), (a).end()

using namespace std;

const int inf = 2000000000;

int getbit(int x){
    int r = 0;
    while(x > 0){
        r += x & 1;
        x >>= 1;
    }
    return r;
}

const int N = 20;

int n;
pair<string, string> a[N];

bool can(int x){
    vector<pair<string, string> > cor;
    vector<pair<string, string> > fake;
    for(int i = 1; i <= n; i++){
        if(x & (1 << (i - 1))){
            cor.pb(a[i]);
        } else {
            fake.pb(a[i]);
        }
    }
    for(int i = 0; i < fake.size(); i++){
        string x = fake[i].x;
        string y = fake[i].y;
        vector<int> q, w;
        for(int j = 0; j < cor.size(); j++){
            if(cor[j].x == x){
                q.pb(j);
            }
            if(cor[j].y == y){
                w.pb(j);
            }
        }
        if(q.size() == 0 || w.size() == 0)return false;
        if(q.size() == 1 && w.size() == 1 && q[0] == w[0])return false;
    }
    return true;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int T;
    cin >> T;
    for(int num = 1; num <= T; num++){
        cout << "Case #" << num <<": ";
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y;
        }
        int ans = 0;
        for(int mask = 0; mask < (1 << n); mask++){
            int res = getbit(mask);
            if(n - res <= ans){
                continue;
            }
            if(can(mask)){
                ans = n - res;
            }
        }
        cout << ans << "\n";
    }
}
