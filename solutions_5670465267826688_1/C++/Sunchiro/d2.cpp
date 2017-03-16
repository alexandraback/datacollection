#include<stdio.h>
#include<string.h>
// char *v[] = {"1ijk","i1"};
int ct=1; // 1:1 i:2 j:3 k:4 -1:1 -2:-i ...
char op(char a,char b){
  int mp[][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
  char sg = a*b>0 ?1:-1;
  a=a>0?a:-a;
  b=b>0?b:-b;
  return mp[a][b]*sg;
}
char getv(char tg){
  return tg=='1'?1:(tg-'g');
}
char eval(char *str){
  int l = strlen(str);
  int ret=1;
  for(int i =0;i<l;i++)
    ret = op(ret,(str[i]));
  return ret;
}
void trans(char *str){
  int l = strlen(str);
  for(int i=0;i<l;i++)str[i]=getv(str[i]);
}
char abs(char ta){
  return ta<0?-ta:ta;
}
char checkik(char *str,long long x){
  int l =strlen(str);
  char s=1;
  char s2=1;
  int i;
  int lf,rt;
  for(i=0;i<l*4;i++){
    if(i%l==0)x--;
    s=op(s,str[i%l]);
    if(s==2)break;
  }
  if(i==l*4)return false;
  lf=i%l;
  for(i=l*4-1;i>=0;i--){
    if(i%l==l-1)x--;
    s2=op(str[i%l],s2);
    // printf("s2:%d\n",s2);
    if(s2==4)break;
  }
  if(i==-1)return false;
  rt=i%l;
  if(x>=0)return true;
  if(x==-1)
  return lf<rt-1;
  return false;
}
void proc(){
  int n;
  long long x,tx;
  char v[111111];
  scanf("%d %I64d",&n,&x);
  tx=  x%4;
  scanf("%s",v);
  trans(v);
  // printf("%d %I64d\n",n,x);
  char s = eval(v);
  printf("Case #%d: ",ct++ );
  if(tx==2)s=op(s,s);
  else if(tx==3)s=op(s,op(s,s));
  if(tx==0)s=1;
  // printf("%d\n",s);
  if(s==-1){
    if(checkik(v,x))printf("YES\n");
    else printf("NO\n");
  }
  else{
    printf("NO\n");
  }
}
int main(){
  int qq;
  scanf("%d",&qq);
  while(qq--)proc();
  return 0;
}
