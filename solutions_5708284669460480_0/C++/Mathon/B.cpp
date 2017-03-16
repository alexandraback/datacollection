#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

char s[100],t[100];
char a[100];

int i,j,k,ls,lt,ca,cas,n;
int d;
double num,cnt;

void Check(){

int i,j;
int f;
int c;

  c=0;
  for (i=1;i<=n-lt+1;i++){
    f=1;
    for (j=1;j<=lt;j++)
      if (a[i+j-1]!=t[j]){
        f=false;
        break;
      }
     if (f){
       num++;
       c++;
     }
  }

  d=max(d,c);

  //printf("%s  ",a+1);
 // printf("%.0lf %.0lf\n",num,cnt);
  return ;



}



void Dfs(int x){

int i;

  if (x>n){
    cnt++;
    Check();
    return;
  }

  for (i=1;i<=ls;i++){
    a[x]=s[i];
    Dfs(x+1);
  }
  return;


}



int main(){

 // freopen("input.in","r",stdin);
  //freopen("output.txt","w",stdout);
  scanf("%d",&cas);
  for (ca=1;ca<=cas;ca++){
    memset(a,0,sizeof(a));
    num=0;
    cnt=0;
    d=0;
    scanf("%d%d%d",&ls,&lt,&n);
    scanf("%s",s+1);
    scanf("%s",t+1);
    Dfs(1);
  //  printf("%d %.0lf %.0lf",d,num,cnt);
    printf("Case #%d: %.7lf\n",ca,(double)((double)d-num/cnt));



  }

  return 0;





}
