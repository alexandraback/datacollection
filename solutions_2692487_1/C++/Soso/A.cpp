#include<cstdio>
#include<algorithm>
using namespace std;
int T,ac,a[10005],n,cur,cnt,tmp,t,tt;
int main(){
    scanf("%d",&T); t=0;
    while (T--){
          ++t;
          scanf("%d%d",&cur,&n); ac=n;
          for (int i=1; i<=n; i++) scanf("%d",&a[i]);
          sort(a+1,a+n+1);
          cnt=0;
          if (cur!=1){
          for (int i=1; i<=n; i++){
              if (cur>a[i]) cur+=a[i];
              else{
                   while (cur<=a[i]) ++cnt, cur+=cur-1;
                   cur+=a[i];
              }
              if (cnt+n-i <ac) ac=cnt+n-i;
          }
          }
          printf("Case #%d: %d\n",t,ac);
    }
    return 0;    
}
