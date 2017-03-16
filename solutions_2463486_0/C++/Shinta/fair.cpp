#include<cassert>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
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
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long long ld;
vector<ll> todos;
char s[20], t[20];
bool es(ll x){
    sprintf(s, "%lld", x);
    sprintf(t, "%lld", x);
    int l = strlen(t);
    reverse(t, t + l);
    f(i, 0, l) if(t[i] != s[i]) return false;
    return true;
}
int main(){
    for(ll i = 1; i * i <= 100000000000000LL; i++)
        if(es(i) && es(i * i)) todos.push_back(i * i);
    int t; cin >> t;
    f(tt, 1, t + 1){
        int a, b; cin >> a >> b;
        cout << "Case #" << tt << ": " << upper_bound(all(todos), b) - lower_bound(all(todos), a) << endl;
    }
    
}

