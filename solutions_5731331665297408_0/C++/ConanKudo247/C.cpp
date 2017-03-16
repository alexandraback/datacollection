#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i = (a); i <= (b);i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
#define maxn 100
int n,m;
string s[maxn];
int order[maxn],a[maxn];
pair<string,int> p[maxn];
bool c[maxn][maxn];

int top, st[maxn];
bool possible() {
    int now = order[1];
    top = 1;
    st[top] = order[1];
    FOR(i,2,n) {
        while ((top > 0) && (!c[st[top]][order[i]]))
            top--;
        if (top == 0) return false;
        st[++top] = order[i];
    }
    return true;
}
void solve() {
    FOR(i,1,n) p[i] = make_pair(s[i],i);
    sort(p+1,p+n+1);
    FOR(i,1,n) a[i] = i;
    do {
        FOR(i,1,n) order[i] = p[a[i]].second;
        if (possible()) {
            FOR(i,1,n) cout << s[order[i]];
            cout << endl;
            return;
        }
    } while (next_permutation(a+1,a+n+1));
}
int main() 
{
    freopen("Csmall.in","r",stdin);
    freopen("C.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n >> m;
        FOR(i,1,n) cin >> s[i];
        memset(c,false,sizeof(c));
        int u,v;
        FOR(i,1,m) {
            cin >> u >> v;
            c[u][v] = true;
            c[v][u] = true;
        }
        solve();
    }
    return 0;
}
