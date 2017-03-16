#include<stdio.h>

char word[101];
int cnt[26];

bool fit(int pos, int L){
   for(int i=pos;i<L;i++){
     if(word[i]!=word[i-pos]) return false;
   }
   return true;
}

int main(int agrc,char*argv[]){
  int T;scanf("%d",&T);
  for(int tc=1;tc<=T;tc++){
    int K,L,S;scanf("%d%d%d",&K,&L,&S);
    for(int i=0;i<26;i++) cnt[i]=0;
    for(int i=0;i<K;i++){
      char hv;scanf(" %c ",&hv);
      cnt[hv-65]++;
    }
    for(int i=0;i<L;i++) scanf(" %c ",&word[i]);
    int best=1;
    while(best<L && !fit(best,L)) best++;
    double res=1; S-=L;
    res+=(S/best);
    for(int i=0;i<L;i++)
      if(cnt[word[i]-65]==0) res=0;
    double av=1;
    for(int i=0;i<L;i++){
      av*=(1.0/K)*cnt[word[i]-65];
    }
    av*=S+1;
    res-=av;
    printf("Case #%d: %f\n",tc,res);
  }
  return 0;
}
