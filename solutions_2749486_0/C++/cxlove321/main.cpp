#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int t,cas=0;
int main(){
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",++cas);
        for(int i=0;i<abs(x);i++){
            printf("%s",x>0?"WE":"EW");
        }
        for(int i=0;i<abs(y);i++){
            printf("%s",y>0?"SN":"NS");
        }
        printf("\n");
    }
    return 0;
}