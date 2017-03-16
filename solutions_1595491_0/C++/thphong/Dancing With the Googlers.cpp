/*
ID: duongthan4
LANG: C++
TASK: test
*/
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#define FOR(i,n) for (int i=0;i<n;i++)
#define FORF(i,a,n) for (int i=a;i<=n;i++)
#define FORR(i,n) for (int i=n-1;i>=0;i--)
#define RI(a) scanf("%d", &a);
#define RS(a) scanf("%s", &a);
#define RC(a) scanf("%c", &a);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define INFY 1000000000
#define MAXN 100000
using namespace std;
typedef long long LL;

int a[101];
int f[101][101];
int sup[31];
int nsup[31];

void solve(){
    int n, s, p;
    cin >> n >> s >> p;
    FOR(i, n) cin >> a[i];
    memset(f, 0, sizeof(f));
    f[0][0] = (nsup[a[0]]>=p);
    f[0][1] = (sup[a[0]]>=p);
    FORF(i, 1, n){
        FORF(j, 0, min(i+1,s) ){
        if(j==0)
            f[i][j] = f[i-1][j]+(nsup[a[i]]>=p);        
        else 
            f[i][j] = max(f[i-1][j-1]+(sup[a[i]]>=p), f[i-1][j]+(nsup[a[i]]>=p));
        }
    }
    cout<<f[n-1][s];
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int TestCase;
    RI(TestCase);
    
    FORF(i, 0, 10)
    FORF(j, i, min(i+2, 10) )
    FORF(k, j, min(i+2, 10) ){
        if((j-i)<=1 && (k-i)<=1) nsup[i+j+k] = max(nsup[i+j+k], k);
        else sup[i+j+k] = max(sup[i+j+k], k);
    }
    
    FOR(i, TestCase){        
        cout<<"Case #"<<i+1<<": ";
        solve();
        printf("\n");
    }
    return 0;
}
