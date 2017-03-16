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

#define MAXN  101
#define BSIZE 1010

using namespace::std;

typedef long long lint;

vector< vector< PII > > sq;
int m,n;
bool rban[MAXN], cban[MAXN];

bool possible(){
    memset(rban,false,sizeof(bool)*n);
    memset(cban,false,sizeof(bool)*m);
    FORR(x,MAXN){
        FOR(y,sq[x].size()) if(rban[sq[x][y].first] && cban[sq[x][y].second]) return false;
        FOR(y,sq[x].size()) rban[sq[x][y].first] = cban[sq[x][y].second] = true;
    }
    return true;
}

int main(){
    int tot_cases,a;
    scanf("%d",&tot_cases);
    for(int case_num=1;case_num<=tot_cases;case_num++){
        scanf("%d %d",&n,&m);
        sq = vector< vector< PII > >(MAXN,vector< PII >());
        FOR(i,n) FOR(j,m) {
            scanf("%d",&a);
            sq[a].push_back(make_pair(i,j));
        }
        if(possible()) printf("Case #%d: YES\n",case_num);
        else printf("Case #%d: NO\n",case_num);
    }
    return 0;
}
