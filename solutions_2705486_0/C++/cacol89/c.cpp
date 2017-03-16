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

#define FOR(a,b) for(int a=0;a<b;a++)
#define FORR(a,b) for(int a=b-1;a>=0;a--)
#define FOR2(a,b,c) for(int a=b;a<c;a++)
#define FORR2(a,b,c) for(int a=c-1;a>=b;a--)
#define EACH(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

#define VI vector<int>
#define VVI vector< vector<int> >
#define PII pair<int,int>
#define VS vector<string>

#define MAXN  51
#define BSIZE 1000
#define INF 1<<28

using namespace::std;

typedef long long lint;

vector<string> dic;

char buffer[BSIZE];
int dp[MAXN][5],n;

inline int pos(int x, int w,int r,int &nr){
    int sz = dic[w].size();
    if(x+sz>n) return -1;

    FOR(i,min(r,sz))
        if(buffer[x+i]!=dic[w][i]) return -1;
    if(r>=sz) {nr = r-sz;return 0;}

    int cnt = 0;
    nr = 0;
    FOR2(i,r,sz){
        if(buffer[x+i]==dic[w][i]) continue;
        cnt++,nr = 4;
        for(int j=1;j<=4 && i+j<sz;j++,nr--)
            if(buffer[x+i+j]!=dic[w][i+j]) return -1;
        i+=4;
    }
    return cnt;
}

int f(int x,int r){
    if(x==n) return 0;
    if(dp[x][r]!=-1) return dp[x][r];
    int &sol = dp[x][r];
    sol = INF;
    FOR(i,dic.size()) {
        int nr;
        int cnt = pos(x,i,r,nr);
        if(cnt!=-1) sol = min(sol, cnt+f(x+dic[i].size(),nr));
    }
    return sol;
}

int main(){
    FILE *fr = fopen("garbled_email_dictionary.txt","r");
    while(fscanf(fr,"%s",buffer) != EOF) dic.push_back(string(buffer));

    int tot_cases;
    scanf("%d",&tot_cases);
    for(int case_num=1;case_num<=tot_cases;case_num++){
        scanf("%s",buffer);
        n = strlen(buffer);
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",case_num,f(0,0));
    }
    return 0;
}
