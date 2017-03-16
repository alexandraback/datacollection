#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<set>

using namespace std;

int solve(){
     int ans=1000;
     int a,n;
     int aa[105];
     scanf("%d %d",&a,&n);
     for(int i=0;i<n;i++){
          scanf("%d",&aa[i]);
     }
     sort(aa,aa+n);

     for(int rn=0;rn<=n;rn++){
          int r=rn;
          int tmpa=a;
          int j;
          for(j=0;j<n;j++){
               if(tmpa>aa[j])
                    tmpa+=aa[j];
               else if(r<=0)
                    break;
               else{
                    while(tmpa<=aa[j] && r>0){
                         tmpa=tmpa*2-1;
                         r--;
                    }
                    if(tmpa>aa[j])
                         tmpa+=aa[j];
                    else
                         break;
               }
          }
          if(ans>rn+n-j) ans=rn+n-j;
     }

     return ans;
}

int main(){
     //freopen ("myfile.txt","w",stdout);
     freopen ("aa.txt","w",stdout);
     freopen ("A-large (1).in","r",stdin);

     int t;
     int ans;
     scanf("%d",&t);
     for(int ii=1;ii<=t;ii++){
          ans=solve();
          printf("Case #%d: %d\n",ii,ans);
     }
     return 0;
}
