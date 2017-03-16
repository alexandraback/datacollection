#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int t,n,s,p,a[101],ans,tmp[2][30],u,v;
bool cmp(int i,int j){return i<j;}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("test.txt","w",stdout);
    scanf("%d",&t);
    for(int r=0;r<t;r++){
       scanf("%d%d%d",&n,&s,&p);       
       ans = 0;
       for(int i=0;i<n;i++) scanf("%d",&a[i]);
       sort(a,a+n,cmp);
       for(int i=0;i<n;i++){ u =0;v = 0;
          for(int j=p;j<=10;j++)
              for(int k=j;k>=0 && k >= j-2;k--)
                 for(int l=k;l>=0 && l>= j-2;l--){
                     if((s!=0||l!=j-2) && j+k+l==a[i] && u == 0){ans++;u = 1;}
                     if(s >0 && l==j-2 && j+k+l == a[i]){s--;goto ou;}
                 }   
          ou:;
       }
       printf("Case #%d: %d\n",r+1,ans);
    }
    //system("pause");
    return 0;
}
