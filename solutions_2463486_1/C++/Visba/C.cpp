
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <string.h>

using namespace std;

long long f, t, sf, st;


int isPalindromes(long long n) {
    char str[50];
    int len;
    int result = 1;
    sprintf(str , "%lld", n);
    len = strlen(str);
    for (int i = 0; i < len; i++) {
//        printf("%c %c   ", str[i], str[len - i - 1]);
        if (str[i] != str[len - i - 1]) {
            result = 0;
//            printf("%lld failed\n", n);
            break;
        }
    }
    return result;
}


int main(int argc, const char * argv[])
{
    int cn;
    int fs = 0;
    
    long long pary [50];

    for (long long i = 1; i < 10000000 ; i++) {
        if (isPalindromes(i)) {
            long long  n = i * i;
            if (isPalindromes(n)) {
//                printf("%lld %lld\n", i, n);
                pary[fs] = n;
                fs++;
            }
        }
    }

	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

    scanf("%d\n", &cn);
    for (int ci = 1; ci <= cn; ci++) {
        scanf("%lld %lld", &f, &t);
        int k = 0;
        for(int i = 0; i < fs; i++) {
            if (pary[i] >= f && pary[i] <= t) {
//                printf("%lld\n", pary[i]);
                k++;
            }
        }
        printf("Case #%d: %d\n", ci, k);
    }
    return 0;
}

