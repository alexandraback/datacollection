#include<stdio.h>
#include<stdlib.h>
using namespace std;
int a[1000][1000],n;
int done[1000];

int dfs(int start){
  int i,j,k,x,y,z;
  for(i=0;i<n;++i){
    if(a[start][i]==1){
      if(done[i]==1)
	return 1;
      else{
	done[i]=1;
	if(dfs(i))
	  return 1;
      }
    }
  }
  return 0;

}

int main(){
  int T,nin;
  scanf("%d",&T);
  for(nin=0;nin<T;nin++){
    int i,j,m,x,y,z;
    scanf("%d",&n);
    for(i=0;i<n;++i){
      for(j=0;j<n;++j){
	a[i][j]=0;
      }
    }
    for(i=0;i<n;++i){
      scanf("%d",&m);
      for(j=0;j<m;++j){
	scanf("%d",&x);
	a[x-1][i]=1;
      }
    }

    int ans=0;
    for(i=0;i<n;++i){
      for(j=0;j<n;++j)
	done[j]=0;
      done[i]=1;
      ans+=dfs(i);
    }
    if(ans>0)
      printf("Case #%d: Yes\n",nin+1);
    else
       printf("Case #%d: No\n",nin+1);
  }
  return 0;
}
