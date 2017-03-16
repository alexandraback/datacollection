#include <cstdio>
#include <iostream>
using namespace std;
const int LIMIT = 10000;
int law[4][4] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
char str[LIMIT];
int c2i[256];
int dp[5*LIMIT];
int main(){
    freopen("1C1.in","r",stdin);
    freopen("out","w",stdout);
    int t;
    c2i['1'] = 1;
    c2i['i'] = 2;
    c2i['j'] = 3;
    c2i['k'] = 4;
    int t2 = 0;
    scanf("%d",&t);
    while(t--){
               ++t2;
               int l,x,xx;
               scanf("%d%d",&l,&x);
               scanf("%s",str);
               dp[0] = c2i[str[0]];
               xx = min(5,x);
               for(int i = 1; i < xx*l; ++i){
                       if(dp[i-1] < 0){
                                  dp[i] = -law[-dp[i-1]-1][c2i[str[i%l]]-1];
                                  //cout<<dp[i]<<endl;
                                  }
                       else{
                           dp[i] = law[dp[i-1]-1][c2i[str[i%l]]-1];
                           //cout<<dp[i]<<endl;
                           }
                       }
               if(dp[(x%4)*l-1] != -1){
                            printf("Case #%d: NO\n",t2);
                            continue;
                            }
               int id = -1;
               for(int i = 0; i < xx*l; ++i){
                       if(dp[i] == c2i['i']){
                                id = i; break;
                                }
                       }

               if(id == -1){
                     printf("Case #%d: NO\n",t2);
                     continue;
                     }
               int id2 = -1;
               for(int i = id+1; i < xx*l; ++i){
                       if(dp[i] == c2i['k']){
                                id2 = i; break;
                                }
                       }
               if(id2 == -1){
                     printf("Case #%d: NO\n", t2);
                     continue;
                     }
               
               printf("Case #%d: YES\n", t2);
               //
               
               
               }
    }