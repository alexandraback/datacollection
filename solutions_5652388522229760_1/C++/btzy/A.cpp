#include <cstdio>
using namespace std;
int t,n;
int x;
int main(){
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d",&n);
        if(n==0){
            printf("Case #%d: INSOMNIA\n",i+1);
            continue;
        }
        x=(1<<10)-1;
        int k=0;
        while(x>0){
            k+=n;
            int e=k;
            while(e>0){
                int d=e%10;
                x&=~(1<<d);
                e/=10;
            }
        }
        printf("Case #%d: %d\n",i+1,k);
    }
}
