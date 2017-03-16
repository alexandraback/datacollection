
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000010

char str[MAX] ;

char is_con[30] = "01110111011111011111011111" ;
//                 abcdefghijklmnopqrstuvwxyz

bool iscon(char c){
    return is_con[c-'a']-'0' ;
}

int main()
{
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        printf("Case #%d: ", time) ;
        int n ;
        scanf("%s %d", str, &n) ;
        int len = strlen(str) ;
        int csc = 0 ;
        int emp = 0 ;
        long long ans = 0 ;
        for(int i = 0 ; i != len ; i++){
            if(iscon(str[i])){
                csc++ ;
            }
            else{
                csc = 0 ;
            }
            if(csc >= n){
                ans += (long long)(i-(n-1)-emp+1)*(len-i) ;
                emp = i-(n-1)+1 ;
            }
        }
        printf("%lld\n", ans) ;
    }
    return 0 ;
}


