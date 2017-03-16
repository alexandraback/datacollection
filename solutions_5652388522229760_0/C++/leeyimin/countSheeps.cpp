#include <cstdio>
using namespace std;

int main(){

    int t,x,no=0;
    long long unsigned n, nn, in;
    bool found[10];
    scanf("%d ",&t);
    for(int i=0;i<t;i++){
        scanf("%d ",&x);
        n=x;
        no=0;
        for(int j=0;j<10;j++) found[j]=false;
        if(x==0){
            printf("Case #%d: INSOMNIA\n",i+1);
            continue;
        }
        nn=0;
        while(no<10){
            nn+=n;
            in=nn;
            while(in>0){
                x=in%10;
                in/=10;
                if(!found[x]){
                    no++;
                    found[x]=true;
                }
            }
        }
        printf("Case #%d: %llu\n",i+1,nn);
    }

}
