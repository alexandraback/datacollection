#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define maxn 1111
using namespace std;

int n,a[maxn],t[maxn];
vector <int> f[10011100];

void att(int x,int s) {
    if (x>n) {
        int z=0;
        FOR(i,1,n) if (((s >> (i-1)) & 1)==1) z+=a[i];
        f[z].push_back(s);
        return;
    }
    att(x+1,s);
    att(x+1,s+(1<<(x-1)));
}

int main() {
    freopen("c.inp","r",stdin);
    freopen("c.out","w",stdout);
    
    int numt;
    cin >> numt;
    FOR(_,1,numt) {
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        FOR(i,0,10000000) f[i].clear();
        att(1,0);
        int res1=-1,res2=-1;
        FOR(i,0,10000000) {
            int m=f[i].size();
            FORN(j,0,m) FORN(k,j+1,m) if ((f[i][j] & f[i][k]) ==0) {
                res1=f[i][j];
                res2=f[i][k];
                break;
            }
            if (res1!=-1) break;
        }
        cout << "Case #" << _ << ": \n";
        if (res1==-1) cout << "Impossible\n";
        else {
            FOR(i,1,n) if ((res1 >> (i-1)) & 1==1) cout << a[i] << " ";
            cout << endl;
            FOR(i,1,n) if ((res2 >> (i-1)) & 1==1) cout << a[i] << " ";
            cout << endl;
        }
        cerr << _ << endl;
    }
}
