#include <stdio.h>

bool sude[10];

void add(int n){
    while(n > 0){
        sude[n % 10] = true;
        n /= 10;
    }
}

bool ok(){
    bool ret = true;
    for(int i = 0; i < 10; i++){
        ret &= sude[i];
    }
    return ret;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tw = 1; tw <= t; tw++){
        int n;
        scanf("%d",&n);
        if(n == 0){
            printf("Case #%d: INSOMNIA\n", tw);
        }
        else{
            for(int i = 0; i < 10; i++){
                sude[i] = false;
            }
            for(int i = 1; ; i++){
                add(n * i);
                if(ok()){
                    printf("Case #%d: %d\n", tw, n * i);
                    break;
                }
            }
        }
    }
}

