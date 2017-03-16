#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,j;
int x[32];
int currcount;

// mods[base*modcount+mod] -> base: 2..10 (9), mod: 2..11 (10)
void find(int index, int* mods){
    if(index==n){
        bool all=true;
        for(int b=0;b<9;++b){
            all=all&&any_of(mods+b*10,mods+(b+1)*10,[](int mod){
                return mod==0;
            });
        }
        if(all){
            ++currcount;
            for_each(x,x+n,[](int digit){
                printf("%d",digit);
            });
            for(int b=0;b<9;++b){
                printf(" %d",find_if(mods+b*10,mods+(b+1)*10,[](int mod){
                    return mod==0;
                })-(mods+b*10)+2);
            }
            printf("\n");
        }
        return;
    }
    for(int i=0;i<2;++i){
        if((index==0||index==(n-1))&&i==0)continue;
        x[index]=i;
        int newmods[9*10];
        for(int b=0;b<9;++b){
            for(int m=0;m<10;++m){
                int base=b+2;
                int mod=m+2;
                newmods[b*10+m]=(mods[b*10+m]*base+i)%mod;
            }
        }
        find(index+1,newmods);
        if(currcount==j)break;
    }
}
int main(){
    scanf("%d",&t);
    for(int c=0;c<t;++c){
        scanf("%d%d",&n,&j);
        currcount=0;
        int mods[9*10];
        for(int i=0;i<9*10;++i){
            mods[i]=0;
        }
        printf("Case #%d:\n",c+1);
        find(0,mods);
    }
}
