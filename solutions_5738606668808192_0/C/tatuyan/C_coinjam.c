#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char outbit[500][34];
int now=0;

void solve(int keta,int kosu);
int check(char *bit);

int main(void){
  int t,i,N,J;
  scanf("%d",&t);
  for(i=1;i<=t;i++){
    printf("Case #%d:\n",i);
    scanf("%d%d",&N,&J);
    solve(N,J);
  }
  return 0;
}

void solve(int keta,int kosu){
  int i,outnum=0,flg=0;
  int mod=1<<keta-2;
  int rnd=-1;
  char bit[34]="";

  srand(time(NULL));
  for(outnum=0;outnum<kosu;outnum+=flg){
    rnd=rand()%mod;
    for(i=0;i<keta;i++){
      if(i==0 || i==keta-1) bit[i]=1+'0';
      else bit[i]=((rnd>>(keta-2-i))&1)+'0';
    }
    flg=check(bit);
  }
}

int check(char *bit){
  int nums[11]={0};
  int i,j,k,mods;

  for(i=0;i<now;i++){
    if(strcmp(outbit[i],bit)==0){
      srand(time(NULL)+i);
      return 0;
    }
  }
  
  for(i=2;i<=10;i++){
    for(j=3;j<32768;j+=2){
      mods=(bit[0]-'0');
      for(k=1;bit[k]!='\0';k++){
	mods*=i;
	mods%=j;
	mods+=bit[k]-'0';
      }
      if(mods%j==0){
	nums[i]=j;
	break;
      }
    }
    
    if(nums[i]==0) return 0;
  }
  
  printf("%s ",bit);
  strcpy(outbit[now++],bit);
  for(i=2;i<=10;i++) printf("%d%c",nums[i],i==10?'\n':' ');
  return 1;
}

