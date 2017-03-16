#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

long long m;
long long v[60];
int n,c,i,j;
int a[100][100];
int ca,cas;


int main(){

  freopen("b_s.in","r",stdin);
  freopen("b_s.out","w",stdout);

  v[0]=1;
  for (i=1;i<=51;i++) v[i]=v[i-1]<<(long long)1;
  scanf("%d",&cas);

  for (ca=1;ca<=cas;ca++){
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    cin>>m;
    for (i=2;i<=n-1;i++)
      for (j=1;j<i;j++) a[j][i]=1;

    printf("Case #%d: ",ca);
    if (m>v[n-2]){
      printf("IMPOSSIBLE\n");
      continue;
    }
    if (m==v[n-2]){
      m--;
      a[1][n]=1;
    }
    c=2;
    while (m){
      if (m & 1){
        a[c][n]=1;
      }
      c++;
      m>>=(long long)1;
    //  cout<<m<<endl;
    }
    printf("POSSIBLE\n");
    for (i=1;i<=n;i++){
      for (j=1;j<=n;j++) printf("%d",a[i][j]);
      printf("\n");
    }







  }

  return 0;


}
