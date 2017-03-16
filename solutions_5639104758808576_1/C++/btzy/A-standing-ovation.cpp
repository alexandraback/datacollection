#include<cstdio>
using namespace std;
int tc,s,standing,p,friends;
char cp;
int main(){
    scanf("%d",&tc);
    for(int ct=1;ct<=tc;++ct){
        scanf("%d",&s);
        standing=0;
        friends=0;
        for(int i=0;i<=s;++i){
            scanf(" %c",&cp);
            p=cp-'0';
            while(p>0){
                while(p>0&&standing>=i){
                    --p;
                    ++standing;
                }
                if(p>0){
                    ++friends;
                    ++standing;
                }
            }
        }
        printf("Case #%d: %d\n",ct,friends);
    }
}
