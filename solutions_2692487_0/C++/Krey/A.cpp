#include<cstdio>
#include<algorithm>
#define N  101
using namespace std;

int t,n,tab[N],wyn,l;
long long a;

int main(){
    scanf("%d",&t);
    for(int test=1;test<=t;test++){
        wyn=N; l=0;
        scanf("%lld%d",&a,&n);
        for(int i=0;i<n;i++) scanf("%d",&tab[i]);
        sort(tab,tab+n);
        for(int i=0;i<n;i++){
            wyn=min(wyn,l+n-i);
            if(a>tab[i]) a+=tab[i];
            else{
                if(a==1) continue;
                else{
                    while(a<=tab[i]){
                        a+=a-1;
                        l++;
                    }
                    a+=tab[i];
                }
            }
        }
        wyn=min(wyn,l);
        if(a==1) wyn=n;
        printf("Case #%d: %d\n",test,wyn);
    }
    return 0;
}
