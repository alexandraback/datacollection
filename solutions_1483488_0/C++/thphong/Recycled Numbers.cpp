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
#define MAXN 2000001
using namespace std;
typedef long long LL;

vector<int> f[MAXN];

void solve(){
    int a, b;
    int r = 0;
    cin >> a >> b;
    FORF(i, a, b){
        FOR(j, f[i].size()){
            r += (f[i][j]>=a) && (f[i][j]<=b);
        }
    }
    cout<<r;
}

int num(int x){
    if(x<10) return 1;
    return 1+num(x/10);
}

int a[10];

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int TestCase;
    RI(TestCase);
    int n, t;
    FOR(i, MAXN){
        n = num(i);
        t = i;
        FORR(k, n){
            a[k] = t%10;
            t/=10;
        }
        FOR(k, n){
            t = 0;
            FOR(j, n){
                t = t*10+a[(j+k)%n];
            }
            if(t>i){
                bool c = 1;
                FOR(j, f[i].size()) if(f[i][j]==t){
                    c=0;
                    break;
                }
                if(c) f[i].pb(t);
                //f[i].pb(t);
            }
        }
    }
        
    FOR(i, TestCase){        
        cout<<"Case #"<<i+1<<": ";
        solve();
        printf("\n");
    }
    return 0;
}
