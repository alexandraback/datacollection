#include<bits/stdc++.h>
using namespace std;
int times[200],K,L,S,ans,M;
char key[100],str[100],now[100];
void create(int pos){
    int i,j;
    if(pos==S){
        int cnt=0;
        //printf("now %s\nstr %s\n",now,str);
        for(i=0;i<=S-L;i++){
            int fail=0;
            for(j=0;j<=L-1;j++)if(now[i+j]!=str[j]){fail=1;break;}
            if(!fail)cnt++;
        }
        M=max(cnt,M);
        ans+=cnt;
        return;
    }
    for(i=0;i<K;i++){
        now[pos]=key[i];
        create(pos+1);
    }
    return;
}
main(){
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("pB.txt","w",stdout);
    int T,cs=1;
    scanf("%d",&T);
    while(T--){
        memset(times,0,sizeof(times)),ans=M=0;
        scanf("%d %d %d",&K,&L,&S);
        scanf(" %s %s",key,str);
        create(0);
        double fin=abs((double)M-(double)ans/pow(K,S));
        printf("Case #%d: %f\n",cs++,fin);
    }
    return 0;
}
