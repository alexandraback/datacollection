/*
ZERO
ONE
TWO
THREE
FOUR
FIVE
SIX
SEVEN
EIGHT
NINE


Z确定0

W确定2
G确定8
X确定6
3+8=H
4=U
5=F-4
7=V-5
1=O-0-2-4
9=I-5-6-8
*/
#include<cstdio>
#include<cstring>
int T,n,i,C,v[128],f[10];char s[2222];
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<128;i++)v[i]=0;
    for(i=0;i<n;i++)v[s[i]]++;
    f[0]=v['Z'];
    f[2]=v['W'];
    f[8]=v['G'];
    f[6]=v['X'];
    f[3]=v['H']-f[8];
    f[4]=v['U'];
    f[5]=v['F']-f[4];
    f[7]=v['V']-f[5];
    f[1]=v['O']-f[0]-f[2]-f[4];
    f[9]=v['I']-f[5]-f[6]-f[8];
    printf("Case #%d: ",++C);
    for(i=0;i<=9;i++)while(f[i]--)printf("%d",i);
    puts("");
  }
  return 0;
}