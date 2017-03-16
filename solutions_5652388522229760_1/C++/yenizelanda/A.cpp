#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[10];

main() {
    int z,t;
    int i,j,k;
    FILE *in=fopen("A.in","r");
    FILE *out=fopen("A.out","w");
    fscanf(in,"%d\n",&t);
    for (z=1;z<=t;z++) {
        int n;
        fscanf(in,"%d",&n);
        for (i=0;i<10;i++)
            arr[i]=0;
        for (j=1;j<=100;j++) {
            k=n*j;
            while (k){
                arr[k%10]++;
                k/=10;
            }
            for (i=0;i<10;i++)
                if (!arr[i])
                    break;
            if (i==10)
                break;
        }
        fprintf(out,"Case #%d: ",z);
        if (j==101)
            fprintf(out,"INSOMNIA\n");
        else
            fprintf(out,"%d\n",j*n);

    }

}
