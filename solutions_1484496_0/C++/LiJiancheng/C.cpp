#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=21;
int a[maxn];
int v[maxn];
int n,t,s;
bool flag;

void dfs2(int t){
  int i;
  if (flag) return ;
  if (s==t){
    for (i=0;i<n;i++)
      if (v[i]==1) printf("%d ",a[i]);
    printf("\n");
    for (i=0;i<n;i++)
      if (v[i]==2) printf("%d ",a[i]);
    printf("\n");
    flag=1;
    return ;
  }
  for (i=0;i<n;i++)
    if (v[i]==0){
      v[i]=2;
      if (t+a[i]<=s) dfs2(t+a[i]);
      v[i]=0;
    }
}

void dfs(int k){
  int i;
  if (flag) return ;
  for (i=k;i<n;i++){
    v[i]=1;
    s+=a[i];
    dfs2(0);
    dfs(i+1);
    v[i]=0;
    s-=a[i];
  }
}

int main(){
  int i,k;
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  scanf("%d",&t);
  for (k=1;k<=t;k++){
    scanf("%d",&n);
    for (i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    sort(a,a+n);
    printf("Case #%d:\n",k);
    memset(v,0,sizeof(v));
    flag=0;
    dfs(0);
    if (!flag) printf("Impossible\n");
  }
  return 0;
}
