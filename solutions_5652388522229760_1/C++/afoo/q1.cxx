#include <stdio.h>
#include <string.h>

bool all_visited(int digit[10]) {
    for (int i=0;i<10;i++) {
        if (!digit[i])
            return false;
    }
    return true;
}
int main()
{
    int T;
    int N; 
    scanf("%d", &T);
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d: ", Ti);
        scanf("%d\n",&N);
        if (N==0) {
            printf("INSOMNI\n");
            continue;
        }
        int i;
        int digit[10];
        for (i=0;i<10;i++) {
            digit[i]=0;
        }
        unsigned int sum = 0;
        for (i=1;;i++) {
            sum+=N;
            int tmp = sum;
            while(tmp) {
                digit[tmp%10]=1;
                tmp/=10;
            }
            if (all_visited(digit)) {
                printf("%d\n", sum);
                break;
            }

        }
    }
    return 0;
}


