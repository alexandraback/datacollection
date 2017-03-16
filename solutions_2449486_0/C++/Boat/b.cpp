#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<set>

using namespace std;
int t;
int n,m;
int a[105][105];
int maxan[105];
int maxam[105];

int f(){
          for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                    if(a[i][j]<maxan[i] && a[i][j]<maxam[j]) return 0;
               }
          }
          return 1;
}

int main(){
     freopen("b.txt","w",stdout);
     freopen("B-small-attempt0.in","r",stdin);

     scanf("%d",&t);
     for(int ii=1;ii<=t;ii++){
          scanf("%d %d",&n,&m);
          for(int i=0;i<n;i++) maxan[i]=0;
          for(int j=0;j<m;j++) maxam[j]=0;

          for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                    scanf("%d",&a[i][j]);
                    if(a[i][j]>maxan[i]) maxan[i]=a[i][j];
                    if(a[i][j]>maxam[j]) maxam[j]=a[i][j];
               }
          }

          if(f()==1) printf("Case #%d: YES\n",ii);
          else printf("Case #%d: NO\n",ii);
     }
     return 0;
}
