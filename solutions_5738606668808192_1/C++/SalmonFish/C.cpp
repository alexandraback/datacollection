#include<cstdio>
#include<cmath>

bool bit[33] = {0};
int num = 0;

void solve(int n, int jj){
    long long score = pow(2, n);
    int ccc = 0;
    //printf("%lld", score);
    for(long long i=0;i<score;i++){
        long long temp_i = i;
        num = 0;
        bool not_success = false;
        while(temp_i != 0){
            bit[num] = temp_i%2;
            if(num == 0 && !bit[num]){
                not_success = true;
                break;
            }
            num++;
            temp_i /= 2;
        }
        if(not_success){
            continue;
        }
        for(int j=num;j<n;j++){
            bit[j] = 0;
        }
        if(!bit[0] || !bit[n-1]){
            continue;
        }
        /*for(int j=0;j<n;j++){
            printf("%d", bit[j]);
        }
        printf("\n");*/
        long long success[11] = {0};
        for(int j=2;j<=10;j++) success[j] = 0;
        for(int l=2;l<32769;l++){
            for(int j=2;j<=10;j++){
                int remainder = 1;
                if(success[j]) continue;
                for(int k=1;k<n;k++){
                    long long pp = 1;
                    if(bit[k]){
                        for(int p=0;p<k;p++){
                            pp *= j;
                            pp %= l;
                            /*remainder += (j%l);
                            remainder %= l;*/
                        }
                        remainder += (pp%l);
                        remainder %= l;
                    }
                }
                if(remainder%l == 0){
                    success[j] = l;
                }
            }
        }
        bool ss = true;
        for(int j=2;j<=10;j++){
            if(!success[j]){
                ss = false;
                break;
            }
        }
        if(ss){
            ccc++;
            for(int j=n-1;j>=0;j--){
                printf("%d", bit[j]);
            }
            printf(" ");
            for(int j=2;j<=10;j++){
                printf("%lld ", success[j]);
            }
            if(ccc >= jj) break;
            //printf("ccc = %d\n", ccc);
            printf("\n");
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        printf("Case #%d: \n", i+1);
        int n, j;
        scanf("%d %d", &n, &j);
        solve(n, j);
    }
}
