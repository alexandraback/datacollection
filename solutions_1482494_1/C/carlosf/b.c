#include <stdio.h>
#include <stdlib.h>

int v[1000][3];

int compare(const void *a, const void *b){
  if (((int*)a)[0]>((int*)b)[0])
    return 1;
  if (((int*)a)[0]<((int*)b)[0])
    return -1;
  if (((int*)a)[1]>((int*)b)[1])
    return -1;
  if (((int*)a)[1]<((int*)b)[1])
    return 1;
  return 0;
}

int proximaEstrela(int n, int s){
  int i=0;
  for(i=0;i<n;++i)
    if (v[i][1]<=s && v[i][2]==0){
      v[i][2]=2;
      return s+2;
    }
  for(i=0;i<n;++i){
    if (v[i][1]<=s && v[i][2]==1){
      v[i][2]=2;
      return s+1;
    }
    if (v[i][0]<=s && v[i][2]==0){
      v[i][2]++;
      return s+1;
    }
  }
  return -1;
}

int main(){
  int T=0,n=0,k=0,s=0,i=0,m=0;
  scanf("%d",&T);
  for(k=1;k<=T;++k){
    scanf("%d",&n);
    s=0;
    m=0;
    for(i=0;i<n;++i){
      scanf("%d %d",&v[i][0],&v[i][1]);
      v[i][2]=0;
    }
    qsort(v,n,sizeof(v[0]),compare);
    while(s<n*2 && s!=-1){
      s=proximaEstrela(n,s);
      if (s!=-1)
	m++;
    }
    if (s==-1)
      printf("Case #%d: Too Bad\n",k);
    else
      printf("Case #%d: %d\n",k,m);
  }
  return 0;
}
