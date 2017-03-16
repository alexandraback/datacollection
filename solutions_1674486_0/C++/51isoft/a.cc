#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1024;
vector<int>adj[N];
int q[N];
int hash[N];
int n;
bool check () {
    for ( int i = 1;i <= n;++i ) {
        int l = 0, r = 0;
        memset ( hash, -1, sizeof ( hash ) );
        q[r++] = i;
        hash[i] = 1;
        while ( l < r ) {
            int v = q[l++];
            for ( int i = 0;i < adj[v].size();++i ) {
                int u = adj[v][i];
                if ( hash[u] == -1 ) {
                    q[r++] = u;
                    hash[u] = 1;
                } else {
                    return true;
                }
            }
        }
    }
    return false;
}
int main() {
    int nCases;
    scanf ( "%d", &nCases );
    for ( int nCase = 1;nCase <= nCases;++nCase ) {
        scanf ( "%d", &n );
        for ( int i = 1;i <= n;++i ) {
            int m;
            adj[i].clear();
            scanf ( "%d", &m );
            for ( int v;m--; ) {
                scanf ( "%d", &v );
                adj[i].push_back ( v );
            }
        }
        printf ( "Case #%d: %s\n", nCase, check() ? "Yes" : "No" );
    }
    return 0;
}