#include <iostream>
#include <cstdio>
using namespace std;

long long findDependentPosition(int k,int c,int lastTerm){
    //printf("last term = %d\n",lastTerm);
    long long base = 1,ans = 0,term = lastTerm;
    for(int i=0;i<c;i++){
        if(term>1) ans += base*(term-1);
        term--;
        base *= k;
    }
    return ans+1;
}

void makePosition(int k,int c){
    for(int lastTerm=c;lastTerm<=k;lastTerm+=c){
        printf(" %lld",findDependentPosition(k,c,lastTerm));
    }
    if(k%c!=0) printf(" %lld",findDependentPosition(k,c,k));
}

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("d_large_out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        if(s*c<k) printf("Case #%d: IMPOSSIBLE\n",i+1);
        else{
            printf("Case #%d:",i+1);
            makePosition(k,c);
            puts("");
        }
    }
    return 0;
}
