#include <iostream>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

using namespace std;

bool is_palyndrom(int64_t n){
    char ch[20];
    int digits = 0;
    for(;n>0;digits+=1){
        ch[digits]=n%10;
        n/=10;
    }
    for(int i=0;i<digits/2; ++i){
        if(ch[i] != ch[digits-1-i])
            return false;
    }
    return true;
}

int main()
{
    int cases;

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    scanf("%d", &cases);

    for(int h=0; h<cases; ++h){
        printf("Case #%d: ", h+1);

        long long n,m;
        cin >> n >> m;

        int res = 0;
        if   (n<1)  res = 4;
        else if(n<2)  res = 3;
        else if(n<5)  res = 2;
        else if(n<10) res = 1;

        if(m < 4) res -= 2;
        else if(m < 9) res -= 1;

        int digits = 1;
        char c[20];
        int b = pow(m, 0.25);
        for(int i=1;i<b;++i){
            if(i%10 == 0)
                digits += 1;
            int lp = i, j=0;
            int64_t pal=0;
            for(;lp > 0;lp/=10, j+=1){
                c[j] = lp%10;
            }
            int ten = 1;
            for(int k=0; k<j; ++k){
                pal += c[j-1-k]*ten;
                ten *= 10;
            }
            pal += i*ten;
            int64_t number = pal*pal;
            if(number >= n && number <= m && is_palyndrom(number)){
                //printf("%d\t%ld\n", pal, number);
                res += 1;
            }

            for(int v=0;v<10;++v){
                pal = 0;
                int ten = 1;
                for(int k=0; k<j; ++k){
                    pal += c[j-1-k]*ten;
                    ten *= 10;
                }
                pal += v*ten;
                ten*=10;
                pal += i*ten;
                int64_t number = pal*pal;
                if(number >= n && number <= m && is_palyndrom(number)){
                    //printf("%d\t%ld\n", pal, number);
                    res += 1;
                }
            }
        }

        printf("%d\n", res);
    }
    return 0;
}

