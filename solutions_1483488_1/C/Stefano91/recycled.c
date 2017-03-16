#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 10
#define VERBOSE 0

long long solve(long long A, long long B) {
    long long n,result=0,numero;
    int exit,cif,i,j,k,num[MAX];

    n=A;
    cif = 0;
    while (n>0) {
        cif++;
        n /= 10;
    }

    for (n=A;n<B;n++) {
        numero = n;
        i = cif-1;
        while (numero>0) {
            num[i--] = numero%10;
            numero /= 10;
        }

        for (i=cif-1;i>=0;i--) {
            j = i;
            k = 0;
            exit = 0;
            while (num[k] == num[j] && !exit) {
                j = (j+1)%cif;
                if (j==i) {
                    exit = 1;
                }

                k++;
            }

            if (exit)
                break;

            if (num[k]<num[j]) {
                numero = 0;

                k=i;
                numero += num[k];
                k=(k+1)%cif;
                for (;k!=i;k=(k+1)%cif) {
                    numero *= 10;
                    numero += num[k];
                }

                if (numero > n && numero <= B) {
                    result++;
                }
            }
        }

    }

    return result;

}

int main() {
    FILE *finput,*foutput,*fexinput,*fexoutput;
    int T,i,j;
    long long A,B,R;

    finput = fopen("input.txt","r");
    foutput = fopen("output.txt","w");



    fscanf(finput, "%d\n", &T);

    for (i=1;i<=T;i++) {
        fscanf(finput, "\n%lld %lld",&A,&B);

        R = solve(A,B);

        if (VERBOSE)
            printf("\n => Case #%d: %lld", i, R);

        fprintf(foutput, "Case #%d: %lld", i, R);

        if (i<T)
            fprintf(foutput, "\n");
    }


    fclose(finput);
    fclose(foutput);

    return 0;
}
