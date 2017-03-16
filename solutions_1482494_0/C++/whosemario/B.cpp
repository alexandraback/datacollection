#include<iostream>
#include<algorithm>
using namespace std;

int col[1005][2];
struct data{
     int a,b;
}dp[1005];

bool cmp(data a,data b){
     if(a.b<b.b) return true;
     else if(a.b==b.b&&a.a>b.a) return true;
     return false;
}

int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("out.data","w",stdout);
    
 
    int t;
    cin>>t;
    int ca;
    for(ca=1;ca<=t;ca++){
        int n;
        cin>>n;
        int i;
        for(i=0;i<n;i++)
          cin>>dp[i].a>>dp[i].b;
        sort(dp,dp+n,cmp);
//        cout<<dp[0].b<<endl;
        memset(col,0,sizeof(col));
        int res=0;
        int star=0;
        int j;
        for(i=0;i<n;i++){
           if(dp[i].b<=star){
              col[i][1]=1;
              if(col[i][0]==1) star+=1;
              else star+=2;
              res+=1;
//              cout<<"a: "<<res<<endl;
           }
           else{
               for(j=n;j>=i;j--){
                  if(dp[j].a<=star){
                      star+=1;
                      col[j][0]=1;
                      res+=1;
                      if(star>=dp[i].b){
                           col[i][1]=1;
                           if(col[i][0]==1) star+=1;
                           else star+=2;
                           res+=1;
                           break;
                      }
                  }
               }
               if(j<i){res=-1;break;}
//               cout<<res<<endl;
           }
        }
        if(res==-1) printf("Case #%d: Too Bad\n",ca);
        else printf("Case #%d: %d\n",ca,res);
    }
}
