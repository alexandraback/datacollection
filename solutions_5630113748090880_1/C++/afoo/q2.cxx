#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    int N; 
    scanf("%d", &T);
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d:", Ti);
        scanf("%d\n", &N);
        int line[100];
        int count[3000];
        for (int i=0;i<3000;i++) 
            count[i] = 0;
        for (int i=0;i<2*N-1;i++) {
            for (int j=0;j<N;j++) {
                int tmp;
                scanf("%d", &tmp);
                count[tmp]++;
            }
        }
        int len =0;
        for (int i=0;i<=2500;i++) {
            if (count[i]%2) {
                line[len++] = i;
            }
        }
        for (int i=0;i<N;i++) {
            for (int j=i+1;j<N;j++) 
                if (line[i]>line[j]) {
                    int tmp;
                    tmp = line[i];
                    line[i] = line[j];
                    line[j] = tmp;
                }
        }
        for (int i=0;i<N;i++) {
            printf(" %d", line[i]);
        }
        printf("\n");
    }
    return 0;
}


