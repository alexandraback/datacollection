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
#define MAXN 1000
using namespace std;
typedef long long LL;

struct E{
    int a, b, c1, c2;
} e[1000];




void process(){
    int n, a, b;
    RI(n);
    FOR(i, n){
        RI(e[i].a);
        RI(e[i].b);
        e[i].c1 = 0;
        e[i].c2 = 0;
    }
    int r = 0;
    int total = 0;
    int cur = 0;
    while(total<n){
        bool c = 1;
        FOR(i, n){
            if(e[i].b<=cur && e[i].c2==0){
                total++;
                r++;
                cur+=2-e[i].c1;
                e[i].c1 = 1;
                e[i].c2 = 1;
                c = 0;
            }
        }
        if(c){
            int tmpB = -1;
            int k = -1;
            FOR(i, n){            
                if(e[i].a<=cur && e[i].c1==0 && e[i].b>tmpB){
                    k = i;
                    tmpB = e[i].b;
                }
            }
            if(k==-1){
                cout<<"Too Bad";
                return;
            }
            else{
                cur++;
                r++;
                e[k].c1=1;
            }
        }
    }
    cout<<r;
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
