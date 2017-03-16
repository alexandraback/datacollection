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

#define MAXN  201
#define BSIZE 1010

using namespace::std;

typedef long long lint;

int n,myk[MAXN],chest[MAXN];
vector< vector<int> > cont;

int stk[MAXN];
bitset<(1<<20)> visit;

bool dfs(int x, int mask){
    if(x==n) return true;
    visit[mask] = true;
    
    FOR(i,n) if(myk[chest[i]]>0 && !visit[mask|(1<<i)]){
        myk[chest[i]]--;
        FOR(j,cont[i].size()) myk[cont[i][j]]++;

        stk[x] = i;
        if(dfs(x+1,mask|(1<<i))) return true;

        myk[chest[i]]++;
        FOR(j,cont[i].size()) myk[cont[i][j]]--;
    }
    return false;
}

int main(){
    int tot_cases,k,a,m;
    scanf("%d",&tot_cases);
    for(int case_num=1;case_num<=tot_cases;case_num++){
        scanf("%d %d",&k,&n);
        
        memset(myk,0,sizeof(myk));
        cont = vector< vector<int> >(n,vector<int>());

        FOR(i,k) scanf("%d",&a), myk[a]++;
        FOR(i,n){
            scanf("%d %d",&chest[i],&m);
            FOR(j,m) scanf("%d",&a),cont[i].push_back(a);
        }
        printf("Case #%d:",case_num);
        
        visit.reset();
        if(dfs(0,0)){
            FOR(i,n) printf(" %d",stk[i]+1);
            printf("\n");
        }
        else printf(" IMPOSSIBLE\n");
    }
    return 0;
}
