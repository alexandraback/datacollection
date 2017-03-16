#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int i,j,k,l,m,n,o,p;
    
    scanf("%lld",&m);
    
    for(l=1;l<=m;l++){
        scanf("%d",&p);
        scanf("%d",&o);
        printf("Case #%d: ",l);
        if(o!=0){
            if(o>0){
                for(i=0;i<o;i++){
                    printf("SN");
                }
            }else{
                for(i=0;i<-o;i++){
                    printf("NS");
                }
            }
        }
        if(p!=0){
            if(p>0){
                for(i=0;i<p;i++){
                    printf("WE");
                }
            }else{
                for(i=0;i<-p;i++){
                    printf("EW");
                }
            }
        }
        putchar('\n');
    }
    
    return 0;
}
