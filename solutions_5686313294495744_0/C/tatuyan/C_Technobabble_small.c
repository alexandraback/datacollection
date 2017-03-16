#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct topics{
  char word[24];
  int num;
  bool flg;
};

void solve(void);

int main(void){
  int T,tt;
  scanf("%d%*c",&T);
  for(tt=1;tt<=T;tt++){
    printf("Case #%d: ",tt);
    solve();
  }
  return 0;
}

void solve(void){
  int N,i,j,k,tp[2],max;
  struct topics *stu[2];
  char topi[1000][2][24];
  bool flg[1000]={};
  
  scanf("%d%*c",&N);
  stu[0]=(struct topics *)calloc(N,sizeof(struct topics));
  stu[1]=(struct topics *)calloc(N,sizeof(struct topics));
  for(i=0;i<N;i++) scanf("%s%*c%s%*c",topi[i][0],topi[i][1]);
  
  tp[0]=tp[1]=0;
  for(i=0;i<N;i++){
    for(k=0;k<2;k++){
      for(j=0;j<tp[k];j++){
	if(!strcmp(stu[k][j].word,topi[i][k])){
	  stu[k][j].num++;
	  break;
	}
      }
      if(j==tp[k]){
	strcpy(stu[k][tp[k]].word,topi[i][k]);
	stu[k][tp[k]].num++;
	tp[k]++;
      }
    }
  }

  for(i=0;i<N;i++){
    for(k=0;k<2 && !flg[i];k++){
      for(j=0;j<tp[k] && !flg[i];j++){
	if(!strcmp(stu[k][j].word,topi[i][k]) && stu[k][j].num==1){
	  flg[i]=true;
	  break;
	}
      }
    }
  }

 for(i=0;i<N;i++){
   if(!flg[i]) continue;
    for(k=0;k<2;k++){
      for(j=0;j<tp[k];j++){
	if(!strcmp(stu[k][j].word,topi[i][k])){
	  stu[k][j].num--;
	  stu[k][j].flg=true;
	  break;
	}
      }
    }
  }

 max=0;
 for(k=0;k<2;k++){
   for(j=0;j<tp[k];j++){
     if(stu[k][j].num-(stu[k][j].flg==false)>max) max=stu[k][j].num-(stu[k][j].flg==false);
   }
 }
 printf("%d\n",max);
 
}
