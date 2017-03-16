#include<stdio.h>

int d[101];

int main(int agrc,char*argv[]){
  int T;scanf("%d",&T);
  for(int tc=1;tc<=T;tc++){
    int C,D,V;scanf("%d%d%d",&C,&D,&V);
    for(int i=0;i<D;i++)
      scanf("%d",&d[i]);
    int res=0;
    bool changed=true;
    while(changed){
     // for(int i=0;i<D;i++) printf("%d ",d[i]); printf("\n");
      changed=false;
      bool ps[33]; for(int i=0;i<33;i++) ps[i]=false;
      for(int index=1;index<(2<<D);index++){
        int sum=0;
        for(int i=0;i<D;i++){
          if((index&(1<<i)) != 0) sum+=d[i];
        }
        if(sum<=V) ps[sum]=true;
      }
      for(int i=1;i<=V && !changed ;i++)
        if(!ps[i]){
          changed=true;
          d[D++]=i;
          res++;
        }
    }
    printf("Case #%d: %d\n",tc,res);
  }
  return 0;
}
