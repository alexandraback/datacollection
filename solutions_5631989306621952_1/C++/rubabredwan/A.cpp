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

#define MAX			100050
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

string s;
char str[MAX];
int n;

int main(){
    READ("A-large.in");
    WRITE("A-large.out");
    int tc, cas=1;
    scanf("%d", &tc);
    while(tc--){
        scanf("%s", str);
        s = str;
        n = s.size();

        int cur = 1;
        string ret = "";

        ret += s[0];

        while(cur < n){

            //cout << ret << ' ' << cur << ' ' << s[cur] << endl;

            if(s[cur] >= ret[0]){
                string f;
                f += s[cur];
                ret = f + ret;
            }
            else{
                ret += s[cur];
            }
            cur++;

        }

        printf("Case #%d: ", cas++);
        cout << ret << endl;

    }
	return 0;
}
