#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T,n,C=1,res,size;
char str[1000010];
int cons[1000010];

int con(char c){
  if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
    return 0;
  return 1;
}

int main(){

  scanf("%d",&T);
  while(T--){
    scanf("%s %d",str,&n);
    size = strlen(str);

    cons[0] = con(str[0]);
    for(int i=1;i<size;i++)
      if(con(str[i])==0) cons[i] = con(str[i]);
      else cons[i] = cons[i-1] + con(str[i]);
/*    for(int i=0;i<size;i++)
      printf("%d ",cons[i]);
    printf("\n");*/

    res = 0;
 /*   for(int i=0;i<size;i++)
      if(cons[i]>=n){
        //res += (i-n+1);
        res += (size-i);
      }*/

    if(n==1)
      for(int i=0;i<size;i++) if(con(str[i])) res++;

    for(int i=0;i<size;i++)
      for(int j=i+1;j<size;j++){
        bool ok=false;
        for(int k=i;k<=j;k++) if(cons[k]>=n){
          if(k-(n-1)>=i){
            ok=true;
            break;
          }
        }
        if(ok) res++;
      }
    printf("Case #%d: %d\n",C++,res);
  }

  return 0;
}
