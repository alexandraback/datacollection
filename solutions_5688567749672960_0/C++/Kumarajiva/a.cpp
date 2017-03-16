#include<cstdio>
#include<algorithm>

using namespace std;

int f[1000100];
int i,j,k,cas,ca,n,x;

int Rev(int x){

int c;

  c=0;
  while (x){
    c=c*10+x % 10;
    x/=10;
  }

  return c;


}



void Prepare(){

int i,n;

  n=1000000;
  for (i=1;i<=n;i++) f[i]=99999999;
  f[0]=0;
  for (i=0;i<n;i++){
    f[i+1]=min(f[i+1],f[i]+1);
    f[Rev(i)]=min(f[Rev(i)],f[i]+1);
  }
}




int main(){

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&cas);
  Prepare();
  for (ca=1;ca<=cas;ca++){
    scanf("%d",&x);
    printf("Case #%d: %d\n",ca,f[x]);

  }
  return 0;


}
