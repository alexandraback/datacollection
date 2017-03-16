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
#define maxn 111

int n,m;
pair<long long,int> a[maxn],b[maxn];

long long suma[maxn][maxn],sumb[maxn][maxn],f[maxn][maxn];

long long geta(int x,int i,int j) {
    return suma[j][x]-suma[i-1][x];
}

long long getb(int x,int i,int j) {
    return sumb[j][x]-sumb[i-1][x];
}

int main() {
    freopen("c.inp","r",stdin);
    freopen("c.out","w",stdout);
    int numtest;
    cin >> numtest;
    FOR(test,1,numtest) {
        memset(suma,0,sizeof(suma));
        memset(sumb,0,sizeof(sumb));
        memset(f,0,sizeof(f));
        cout << "Case #" << test << ": ";
        cin >> n >> m;
        FOR(i,1,n) cin >>a[i].first >> a[i].second;
        FOR(i,1,m) cin >>b[i].first >> b[i].second;
        FOR(i,1,n) FOR(j,1,100) {
            suma[i][j]=suma[i-1][j];
            if (j==a[i].second) suma[i][j]+=a[i].first;
        }
        FOR(i,1,m) FOR(j,1,100) {
            sumb[i][j]=sumb[i-1][j];
            if (j==b[i].second) sumb[i][j]+=b[i].first;
        }
        long long res=0;
        FOR(i,1,n) FOR(j,1,m) { 
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            FOR(k,0,i-1) FOR(l,0,j-1) {
                f[i][j]=max(f[i][j],f[k][l]+min(geta(a[i].second,k+1,i),getb(a[i].second,l+1,j)));
                f[i][j]=max(f[i][j],f[k][l]+min(geta(b[j].second,k+1,i),getb(b[j].second,l+1,j)));
            }
            res=max(res,f[i][j]);
        }
        cout << res << endl;
        cerr << test << endl;
    }
	return 0;
}
