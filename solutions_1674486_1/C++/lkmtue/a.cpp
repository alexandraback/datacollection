//Written by technolt
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define DOWN(i,a,b) for(int i = a; i >= b; i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define maxn 1111

int n;
vector <int> a[maxn];
bool Free[maxn];
bool res;


void dfs(int u) {
    Free[u]=false;
    FORN(i,0,a[u].size()) {
        int v=a[u][i];
        if (Free[v]) dfs(v);
        else res=true;
    }
}

int main() {
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    int numtest;
    cin >> numtest;
    FOR(test,1,numtest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i,1,n) {
            a[i].clear();
            int z;
            cin >> z;
            FOR(j,1,z) {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        res=false;
        FOR(i,1,n) {
            memset(Free,true,sizeof(Free));
            dfs(i);
        }
        if (res) cout<<"Yes";else cout <<"No";
        cout << endl;
        cerr << test << endl;
    }
	return 0;
}
