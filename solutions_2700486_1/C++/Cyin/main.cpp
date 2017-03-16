#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,x,y,m;
int sum[1000],he[1000];
double ans;
double s1,s2;
void dfs(int l,int r,int lim,int left,double p){
     if (left==0){
        if (r>abs(y)) ans+=p;
        return;
     }
     if (l<lim&&r<lim){
        dfs(l+1,r,lim,left-1,p*0.5);
        dfs(l,r+1,lim,left-1,p*0.5);
     }else if (l<lim){
           dfs(l+1,r,lim,left-1,p);
     }else if (r<lim){
           dfs(l,r+1,lim,left-1,p);
     }
}
int main(){
    freopen("b.in","r",stdin);
    freopen("bb.out","w",stdout);
    int ca,cc=0;
    int add;
    int i,w,left;
    double a;
    scanf("%d",&ca);
    while (ca--){
          printf("Case #%d: ",++cc);
        //  ++cc;

          scanf("%d%d%d",&n,&x,&y);
        //  if (cc==83) printf("%d %d %d\n",n,x,y);
          sum[0]=1;he[0]=0;
          for (i=1;;i++){
              sum[i]=sum[i-1]+(i*2+1)*2-1;
              he[i]=he[i-1]+2;
              if (sum[i]>1000000) {m=i;break;}
          }
          w=0;
          while (sum[w]<=n) w++;
          w--;
          left=n-sum[w];
          //printf("left %d\n",left);
          if (abs(x)+abs(y)<=he[w]) {printf("1.0\n");continue;}
          if (left==0&&abs(x)+abs(y)>he[w]) {printf("0.0\n");continue;}
          if (left>0&&abs(x)+abs(y)>he[w]+2) {printf("0.0\n");continue;}
          if (left<abs(y)+1) {printf("0.0\n");continue;}
          if (x==0) {printf("0.0\n");continue;}
          ans=0;
          w++;
          a=1.0;
          s1=s2=0;
          for (i=0;i<=left;i++){
              s1=s1+a;
              if (left-i>w*2) add=left-i-w*2;
              else add=0;
              if (i+add>abs(y)) s2=s2+a;
              a=a*(double)(left-i)/(double)(i+1);
          }
          //printf("%lf %lf\n",s1,s2);
          ans=s2/s1;
          //dfs(0,0,w*2,left,1.0);
          printf("%.10lf\n",ans);
    }
    //while (1);
    return 0;
}

