#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  for(int C=1;C<=t;C++){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[100][100];
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	scanf("%d",a[i]+j);
      }
    }
    int M1[100],M2[100];
    for(int i=0;i<n;i++){
      M1[i]=a[i][0];
      for(int j=1;j<m;j++){
	M1[i]=max(M1[i],a[i][j]);
      }
    }
    for(int j=0;j<m;j++){
      M2[j]=a[0][j];
      for(int i=1;i<n;i++){
	M2[j]=max(M2[j],a[i][j]);
      }
    }
    bool b=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	if(a[i][j]<M1[i]&&a[i][j]<M2[j]){
	  b=1;
	}
      }
    }
    if(b){
      printf("Case #%d: NO\n",C);
    }
    else{
      printf("Case #%d: YES\n",C);
    }
  }
  return 0;
}
