#include <cstdio>
using namespace std;

int main(){
    freopen("1A1.in","r",stdin);
    freopen("out","w",stdout);
    int t, t2 = 1;
    scanf("%d",&t);
    while(t--){
               int n;
               char aud[1001];
               scanf("%d%s",&n,aud);
               int ans = 0, cnt = 0;
               for(int i = 0; i <= n; ++i){
                       if(cnt >= i){
                              cnt += aud[i] - '0';
                              }
                       else{
                            ans += i - cnt;
                            cnt += aud[i] - '0' + i - cnt;
                            }
                       }
               
               printf("Case #%d: %d\n", t2++, ans);
               }
               
    }