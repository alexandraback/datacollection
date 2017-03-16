#include<bits/stdc++.h>
#define f(i,x,y) for (int i = int(x); i < int(y); i++)
#define fd(i,x,y) for(int i = int(x); i>= int(y); i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define oo 100000000
#define MAX 1000009
//#define N 1010
using namespace std;

int TC,E,R,N;
int val[109],memo[200][200];

int sol(int id = 0 , int ener = E){
    if(id==N)   return 0;
    if(memo[id][ener]!=-1)     return memo[id][ener];
    int ans = -oo;
    f(i,0,ener+1){
        ans = max(ans , (val[id]*i) + sol(id+1, min(E,(ener-i)+R)));
    }
    return memo[id][ener] = ans;
}

int main(){
    freopen("in.c","r",stdin);
    freopen("out.c","w",stdout);
    int NC = 1;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d%d",&E,&R,&N);
        f(i,0,N){
            scanf("%d",&val[i]);
        }
        clr(memo,-1);
        printf("Case #%d: %d\n",NC++,sol());
    }
    return 0;
}
