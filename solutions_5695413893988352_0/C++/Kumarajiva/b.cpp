#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

char s1[5],s2[5];
int v1[1010],v2[1010],p1,p2;
int i,j,k,n,m,a,b,ans;
int ca,cas;

void Dfs1(int x,int d){

int i,t;

  t=x;

 // printf("%d %d\n",x,d);


  if (d>n){
    v1[++p1]=x;
   // printf("%d %d\n",p1,x);
    return;
  }

  if (s1[d]=='?'){
    for (i=0;i<=9;i++){

      x=t*10+i;
      //printf("%d %d\n",x,d);
      Dfs1(x,d+1);

    }
  }
  else{
    x=t*10+(s1[d]-'0');
    Dfs1(x,d+1);
  }
  return;
}

void Dfs2(int x,int d){

int i;
int t;


  t=x;
  if (d>n){
    v2[++p2]=x;
    return;
  }

  if (s2[d]=='?'){
    for (i=0;i<=9;i++){
      x=t*10+i;
      Dfs2(x,d+1);
    }
  }
  else{
    x=t*10+(s2[d]-'0');
    Dfs2(x,d+1);
  }
  return;
}

void Pu(int x){

  if (n==3){
    if (x<100) printf("0");
    if (x<10) printf("0");
    printf("%d",x);
  }
  else if(n==2){
    if (x<10) printf("0");
    printf("%d",x);
  }
  else{
    printf("%d",x);
  }
}

int main(){

  freopen("b_s.in","r",stdin);
  freopen("b_s.out","w",stdout);
  scanf("%d",&cas);
  for (ca=1;ca<=cas;ca++){
    scanf("%s %s",s1+1,s2+1);
    n=strlen(s1+1);
  //  printf("%d",n);
    p1=0;
    p2=0;
    Dfs1(0,1);
 //   printf("%d\n",p1);
    Dfs2(0,1);
 //   printf("%d\n",p1);
  //0  for (i=1;i<=p1;i++) printf("%d\n",v1[i]);
    ans=9999;

    for (i=1;i<=p1;i++)
      for (j=1;j<=p2;j++){
        if (abs(v1[i]-v2[j])<ans){
          ans=abs(v1[i]-v2[j]);
          a=v1[i];
          b=v2[j];
        }
        else if (abs(v1[i]-v2[j])==ans && (v1[i]<a || v1[i]==a && v2[j]<b)){
          a=v1[i];
          b=v2[j];
        }
      }
    printf("Case #%d: ",ca);
   // printf("%d",a);
    Pu(a);
    printf(" ");
    Pu(b);
    printf("\n");


  }

  return 0;



}

