// created by Marchecnko Vadim [midav7]
// I did it just for fun =)
// v 0.7

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <cmath>
#include <map>
#include <set>
#include <climits>

#define foread freopen("input.txt","r",stdin)
#define fowrite freopen("output.txt","w",stdout)
#define pi 3.141592

using namespace std;

int shab[250],now[250],range[250],need[250];
int f[3000000][22],give[22][403];
int eps=100,n;

void init(){
for (int i=1; i<=210; ++i) shab[i]=0;
for (int j=0; j<=(1 << 21); ++j)
  for (int k=0; k<=21; ++k)
      f[j][k]=eps;   
for (int i=0; i<=21; ++i) range[i]=0;
}

int lower(int maska,int next , int maskb){
  for (int i=0; i<=n; ++i)
  {						
    if (f[maska][i] < f[maskb][i])  return 1;
      else if (f[maska][i] > f[maskb][i]) {
       if (f[maska][i]!=eps) return 0;
       else if (next < f[maskb][i]) return 1;
       else return 0;
       }
   }
   return 0;
}

void modify(int maskb,int maska ,int next) {
  for (int i=0; i<=n; ++i) 
    if (f[maska][i]!=eps) f[maskb][i]=f[maska][i];
    else {
      f[maskb][i]=next;
      break;
    }
}

bool bit(int pl, int mask){
  if ( (( 1 << (pl-1) ) & mask) == 0 ) return 0;
  return 1;
}

void write(){
  for (int i=1; i<n; ++i) printf("%d ",f[(1 << n)-1][i]);
  printf("%d\n",f[(1 << n)-1][n]);
}

void showmask(int mask){
  for (int i=1; i<=n; ++i)
    if (bit(i,mask)==1) cout<<1;
    else cout<<0;
}
void findkeys(int mask){
  for (int i=1; i<=210; ++i)
    now[i]=shab[i];
  for (int i=1; i<=n; ++i)
    if (bit(i,mask)==1) {
      --now[need[i]];
      for (int j=1; j<=range[i]; ++j) ++now[give[i][j]];
    }
}

void findways(int mask){
  for (int i=1; i<=n; ++i) {
    if (bit(i,mask)==0  && now[need[i]]>0 && lower(mask,i,mask|(1 << (i-1)))) {
      modify(mask|(1<<(i-1)),mask,i);
      }
      }
}

int main(){
foread;
fowrite;
int t,keys;
scanf("%d",&t);
int a;
for (int kk=1; kk<=t; ++kk) {
  init();
  scanf("%d%d",&keys,&n);
  for (int i=1; i<=keys; ++i) {
    scanf("%d",&a); ++shab[a];
  }
  for (int i=1; i<=n; ++i) {
    scanf("%d%d",&need[i],&range[i]);
    for (int j=1; j<=range[i]; ++j) scanf("%d",&give[i][j]);
  }
  f[0][0]=0;
  for (int i=0; i<n; ++i)
    for (int j=0; j<=(1 << n)-1; ++j) 
      if (f[j][0]!=eps) {
        findkeys(j);
        findways(j);
      } 
  printf("Case #%d: ",kk);
  if (f[(1 << n)-1][0]==eps)  printf("IMPOSSIBLE\n");
  else write();
}
return 0;
}