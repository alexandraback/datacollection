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

double p[MAXN];
double f[MAXN];

void process(){
    int a, b;
    RI(a);
    RI(b);
    FOR(i, a){
        cin >> p[i];
        if(i==0) f[i] = p[i];
        else f[i] = p[i]*f[i-1];
    }
    double r = b+2.0;
    //k==0
    r = min(r, a+b+1.0);
    //k==a
    r = min(r, f[a-1]*(b-a+1)+(1-f[a-1])*(2*b-a+2));
    //
    FORF(k, 1, a-1){
        r = min(r, f[k-1]*(a+b-2*k+1)+(1-f[k-1])*(a+2*b-2*k+2));
    }
    printf("%.6lf", r);    
}


int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    RI(t);
    FORF(i, 1, t){
        cout<<"Case #"<<i<<": ";
        process();        
        cout<<endl;
    }
    return 0;
}
