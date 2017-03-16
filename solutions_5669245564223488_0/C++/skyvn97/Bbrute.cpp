#include<bits/stdc++.h>
#define MAX   13
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
string a[MAX];
int pr[30];
int mask[1<<MAX];
int n,res,len;
void init(void) {
    scanf("%d",&n);
    REP(i,n) cin>>a[i];
    REP(i,n) FORE(it,a[i]) *it-='a';
    memset(pr,-1,sizeof pr);
    REP(i,n) mask[1<<i]=i;
    res=len=0;
}
bool canput(int x) {
    //printf("CHECK FOR %d while %d\n",x,len);
    int tmp=len;
    FORE(it,a[x]) {
        tmp++;
        if (pr[*it]<0) pr[*it]=tmp;
        else {
            if (pr[*it]!=tmp-1) return (false);
            pr[*it]=tmp;
        }
    }
    //printf("OK %d while %d\n",x,len);
    len=tmp;
    return (true);
}
void backtrack(int stt) {
    //printf("BACK %d\n",stt);
    //REP(i,26) printf("%d ",pr[i]); printf("\n");
    if (stt==0) {
        res++;
        return;
    }
    int opr[30];
    REP(i,26) opr[i]=pr[i];
    int tmp=stt;
    while (tmp>0) {
        int id=mask[tmp&(-tmp)];
        tmp^=1<<id;
        if (canput(id)) {
            //printf("CHOOSE %d\n",id);
            backtrack(stt^(1<<id));
            len-=a[id].size();
        }
        FORE(it,a[id]) pr[*it]=opr[*it];
    }
}
void process(int tc) {
    backtrack((1<<n)-1);
    printf("Case #%d: %d\n",tc,res);
}
int main(void) {
    //reopen("tmp.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    REP(zz,tc) {
        cerr<<"TEST "<<zz<<endl;
        init();
        process(zz+1);
    }
    return 0;
}
