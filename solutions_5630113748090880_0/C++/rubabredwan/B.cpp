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

#define MAX			2500
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

int n;
int M[MAX][MAX], cnt[MAX*4];

int main(){
    READ("B-small-attempt0.in");
    WRITE("B-small-attempt0.out");
    int tc, cas=1;
    scanf("%d", &tc);
    while(tc--){
        SET(cnt, 0);
        scanf("%d", &n);
        REP(i, 2*n-1){
            REP(j, n){
                scanf("%d", &M[i][j]);
                cnt[ M[i][j] ]++;
            }
        }
        printf("Case #%d:", cas++);
        REPN(i, 2500){
            if(cnt[i] % 2 == 1) printf(" %d", i);
        }
        printf("\n");

    }
	return 0;
}
