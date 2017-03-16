#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<string>
#include<bitset>
#include<set>
#include<algorithm>

#define FOR(a,b) for(int a=0;a<(b);a++)
#define FORR(a,b) for(int a=(b)-1;a>=0;a--)
#define FOR2(a,b,c) for(int a=(b);a<(c);a++)
#define FORR2(a,b,c) for(int a=(c)-1;a>=(b);a--)
#define EACH(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

#define VI vector<int>
#define VVI vector< vector<int> >
#define PII pair<int,int>
#define VS vector<string>

#define MAXN  1000
#define BSIZE 1010

using namespace::std;

typedef long long lint;

char buffer[10], winner;
int board[4][4];

inline bool win(){
    int sum[10];
    FOR(x,10) sum[x] = 0;
    FOR(i,4) {
        FOR(j,4) sum[i] += board[i][j], sum[4+j] += board[i][j];
        sum[8] += board[i][i], sum[9] += board[i][3-i];
    }
    FOR(x,10) {
        if(sum[x]==301 || sum[x] == 400) {winner='X';return true;}
        if(sum[x]==31 || sum[x] == 40) {winner='O';return true;}
    }
    return false;
}

int main(){
    int tot_cases;
    scanf("%d",&tot_cases);
    FOR2(case_num,1,tot_cases+1){
        printf("Case #%d: ",case_num);
        bool draw = true;
        FOR(i,4) {
            scanf("%s",buffer);
            FOR(j,4) {
                if(buffer[j]=='X') board[i][j] = 100;
                else if(buffer[j]=='O') board[i][j] = 10;
                else if(buffer[j]=='T') board[i][j] = 1;
                else board[i][j] = 0, draw = false;
            }
        }
        if(win()) printf("%c won\n",winner);
        else if(draw) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}
