
#include <cstdio>
#include <cstring>

void swap(char& c1, char& c2){
    char t = c1 ;
    c1 = c2 ;
    c2 = t ;
}

bool isp(long long num){
    char s[22], r[22] ;
    sprintf(s, "%lld", num) ;
    sprintf(r, "%lld", num) ;
    int len = strlen(r) ;
    for(int i = 0 ; i != len/2 ; i++)
        swap(r[i], r[len-i-1]) ;
    return strcmp(s, r)==0 ;
}

long long dat[50] ;

int main()
{
    int cnt = 0 ;
    for(long long i = 1 ; ; i++){
        if(!isp(i)) continue ;
        if(!isp(i*i))   continue ;
        if(i*i > 100000000000000)   break ;
        dat[cnt++] = i*i ;
        //printf("%lld^2 = %lld", i, i*i) ;
        //puts("") ;
    }
    //return 0 ;
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        printf("Case #%d: ", time) ;
        long long A, B ;
        scanf("%lld%lld", &A, &B) ;
        int ans = 0 ;
        for(int i = 0 ; i != cnt ; i++){
            if(A <= dat[i] && dat[i] <= B)  ans++ ;
        }
        printf("%d\n", ans) ;
    }
    return 0 ;
}
