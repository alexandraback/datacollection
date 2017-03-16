#include <stdio.h>
int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int i = 0; i < t; i++){
        int n, k, q;
        int s = 10;
        bool v[10];
        for(int i = 0; i < 10; i++)
            v[i] = false;
        fscanf(fp1, "%d", &n);
        if(n == 0){
           fprintf(fp2, "Case #%d: INSOMNIA\n", i + 1);
           puts("INSOMNIA");
           continue; 
        }
        for(q = n; s > 0; q += n){
            k = q;
            do{
                int j = k % 10;
                if(!v[j])
                    v[j] = true, s--;
                k /= 10;
            }while(k != 0);
        }
        printf("%d\n", q - n);
        fprintf(fp2, "Case #%d: %d\n", i + 1, q - n);
    }
    return 0;
}
