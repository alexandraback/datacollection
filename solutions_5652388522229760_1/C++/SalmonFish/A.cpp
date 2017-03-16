#include<cstdio>

long long val[100000];
int temp = 0;

bool digit[10] = {0};

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        for(int j=0;j<10;j++) digit[j] = false;
        printf("Case #%d: ", i+1);
        long long a;
        scanf("%lld", &a);
        if(a == 0){
            printf("INSOMNIA\n");
            continue;
        }
        int cc = 1;
        while(1){
            long long b = a*cc;
            bool success = true;
            
            while(b != 0){
                digit[b%10] = true;;
                b/=10;
            }
            for(int j=0;j<10;j++){
                if(!digit[j]){
                    success = false;
                    break;
                }
            }
            if(success){
                printf("%lld\n", a*cc);
                break;
            }
            cc++;
        }
        /*while(a != 0){
            val[temp] = a%10;
            temp++;
            a/=10;
        }*/
        /*int cc = 1;
        while(1){
            int ll = 1;
            bool success = true;
            for(int j=0;j<temp;j++){
                int count = 0;
                
                val[j] *= cc;
                if(val[j] == 0) digit[0] = true;
                int keep[1000] = {0};
                int kk = 0;
                long long tt = val[j];
                val[j] = 0;
                while(val[j] != 0){
                    keep[kk] = tt%10;
                    kk++;
                    tt /= 10;
                }
            }
            for(int j=0;j<temp;j++){
                digit[val[j]] = true;
            }
            for(int j=0;j<10;j++){
                if(!digit[j]){
                    success = false;
                    break;
                }
            }
            if(success){
                for(int j=0;j<temp;j++){
                    printf("%lld", val[j]);
                }
                break;;
            }
            cc++;
        }*/
    }
}
