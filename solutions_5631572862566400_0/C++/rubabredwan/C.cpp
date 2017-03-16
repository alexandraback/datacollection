/*

 #####  ###### #####  #    #   ##   #    #
 #    # #      #    # #    #  #  #  ##   #
 #    # #####  #    # #    # #    # # #  #
 #####  #      #    # # ## # ###### #  # #
 #   #  #      #    # ##  ## #    # #   ##
 #    # ###### #####  #    # #    # #    #


handle	: rubabredwan (Codeforces/CodeChef/HackerRank)
task 	:

*/

#include <bits/stdc++.h>

#define READ(x)		freopen(x,"r",stdin)
#define WRITE(x)	freopen(x,"w",stdout)
#define REP(i,n)	for(int i=0;i<n;i++)
#define REPN(i,n)	for(int i=1;i<=n;i++)
#define FOR(i,a,b)	for(int i=a;i<b;i++)
#define SET(i,n)	memset(i,n,sizeof(i))

#define MAX			11
#define INF			1e9
#define EPS			1e-9
#define PII			acos(-1)

#define in			insert
#define pb			push_back
#define cl			clear
#define sz			size

using namespace std;

typedef long long 		ll;
typedef unsigned long long	ull;
typedef double			db;

//template ends here

int Set(int mask, int at){
    return mask | (1 << at);
}

bool Check(int mask, int at){
    return mask & (1 << at);
}

int ret, st;
int n, M[MAX][MAX], vis[MAX][MAX][(1 << MAX)][2], t=1, BF[MAX];

void recur(int at, int past, int mask, bool flag){
    if(past == BF[at]){
        if(flag){
            ret = max(ret, __builtin_popcount(mask));
        }
        else if(BF[st] == at) {
            ret = max(ret, __builtin_popcount(mask));
        }
    }
    else if(BF[at] == st){
        if(flag || (BF[st] == at)){
            ret = max(ret, __builtin_popcount(mask));
        }
    }
    if(vis[at][past][mask][flag] == t) return;
    vis[at][past][mask][flag] = t;

    if(at == st){

        recur(BF[at], at, Set(mask, BF[at]), 1);

        for(int i=0;i<n;i++){
            if(M[at][i] && !Check(mask, i)) recur(i, at, Set(mask, i), 0);

        }

    }
    else{
        if(past == BF[at]){
            for(int i=0;i<n;i++){
                if(!Check(mask, i) && M[at][i]) recur(i, at, Set(mask, i), flag);
            }
        }
        else{
            if(!Check(mask, BF[at])) recur(BF[at], at, Set(mask, BF[at]), flag);
        }
    }
}

int main(){
    READ("C-small-attempt0.in");
    WRITE("C-small-attempt0.out");
    int tc, cas=1;
    scanf("%d", &tc);
    while(tc--){
        SET(M, 0);
        scanf("%d", &n);
        REP(i, n){
            scanf("%d", &BF[i]);
            BF[i]--;
            M[BF[i]][i] = 1;
        }
        int ans = 0;
        REP(i, n){
            t++;
            ret = 0; st = i;
            recur(i, 0, Set(0, i), 0);
            ans = max(ans, ret);
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
