#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void open(){
 freopen("D-small-attempt0.in","r",stdin);
 freopen("Df.out","w",stdout);
}

void close(){
 fclose(stdin);
 fclose(stdout);
}
#define eps 1e-9
double arr[2][1005];
int tc,n,ans[2];

int main(){
 open();
 scanf("%d",&tc);
 for(int t=1;t<=tc;t++){
  scanf("%d",&n);
  for(int i=0;i<2;i++){
   ans[i]=0;
   for(int j=0;j<n;j++)
    scanf("%lf",&arr[i][j]);
   sort(arr[i],arr[i]+n);
  }
  //for(int i=0;i<n;i++)
   //printf("%.3lf %.3lf\n",arr[0][i],arr[1][i]);
  for(int i=0;i<2;i++){
   int it=0;
   for(int j=0;j<n;j++){
    while(it<n && arr[0][it]<arr[1][j]+eps)
     it++;
    if(it<n) it++,ans[i]++;
   }
   swap(arr[0],arr[1]);
  }
  printf("Case #%d: %d %d\n",t,ans[0],n-ans[1]);
 }
 close();
 return 0;
}
