#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;
int sums[2000005];
int pow2[25];
int a,b,x,y,t;
int sum=0,nums[25],n;
bool first,done;
int main(){
    pow2[0]=1;
    for(x=1;x<=20;x++) pow2[x]=2*pow2[x-1];
    scanf("%d",&t);
    for(a=1;a<=t;a++){
    memset(sums,0,sizeof(sums));
        scanf("%d",&n);
        done=0;
        for(b=0;b<n;b++){
            scanf("%d",&nums[b]);
        }
        for(x=1;x<pow2[20];x++){
                bitset <20> bs(x);
                sum=0;
                for(y=0;y<20;y++){
                    if(bs[y]==1)sum+=nums[y];
                }
                if(sums[sum]>0){
                    printf("Case #%d:\n",a);
                    first=1;
                    for(y=0;y<20;y++){
                        if(bs[y]==1){
                            if(first){
                                printf("%d",nums[y]);    
                                first=0;
                            }
                            else printf(" %d",nums[y]);
                        }
                    }
                    printf("\n");
                    bitset <20> bs(sums[sum]);
                    first=1;
                    for(y=0;y<20;y++){
                        if(bs[y]==1){
                            if(first){
                                printf("%d",nums[y]);    
                                first=0;
                            }
                            else printf(" %d",nums[y]);
                        }
                    }
                    printf("\n");
                    done=1;
                    break;
                }
                sums[sum]=x;
        }
        if(!done) printf("Case #%d:\nImpossible\n");
    }
    return 0;
}
