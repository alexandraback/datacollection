
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <string.h>

using namespace std;

int f, t;

int isPalindromes(int n) {
    char str[50];
    int len;
    int result = 1;
    sprintf(str , "%d", n);
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            result = 0;
            break;
        }
    }
    return result;
}

int main(int argc, const char * argv[])
{
    int cn;
    int fs;
    
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    
    scanf("%d\n", &cn);
    for (int ci = 1; ci <= cn; ci++) {
        scanf("%d %d", &f, &t);
        fs = 0;
        for (int i = 1; i < 32 ; i++) {
            int n = i * i;
            if (n >= f && n <= t) {
                if (isPalindromes(i) && isPalindromes(n)) {
                    fs++;
                }
            }
        }
        printf("Case #%d: %d\n", ci, fs);
    }
    return 0;
}
