#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

bool vog (char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') return 1;
    return 0;
}

#define N 2000000
string s;
int v[N], n, sz;
vector <int> c;

int main (){
    int t; cin >> t;
    f (tt, 1, t+1){
        cin >> s >> n;
        sz = s.size();
        v[sz] = 0;
        c.clear();
        for (int i = sz-1; i >= 0; i--){
            if (!vog(s[i])){
                v[i] = 1+v[i+1];
                if (v[i] >= n) c.pb(i);
            }
            else v[i] = 0;
        }
        c.pb(-1);
        reverse (all(c));
        ll ans = 0;
        f (i, 1, c.size()){
            ans += (ll)(c[i]-c[i-1])*(ll)(sz-(c[i]+n-1));
        }
        printf("Case #%d: %lld\n", tt, ans);

    }
    return 0;
}



