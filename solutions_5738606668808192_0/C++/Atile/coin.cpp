#include <cstdio>
#include <cmath>

bool isPrime(long long int v, long long int *d){
    if( v <= 1 ){
        *d = 1;
        return false;
    }
    if( v == 2 ){
        *d = 1;
        return true;
    }

    for(*d=2; (*d)*(*d) <= v ;(*d)++)
        if( v%(*d) == 0 )
            return false;

    *d = 1;
    return true;
}

isPrime(bool *n, int b, int bits, long long int *d){
    long long int limSup = pow(b, bits/2);
    long long int div;
    long long int resAcum;
    long long int resActual;
    long long int resTotal;

    for(div=2; div < limSup ;div++){
        resAcum = b-1;
        resTotal = 1;
        for(int i=30;i>=32-bits;i--){
            resActual = (resAcum + 1) % div;
            if( n[i] )
                resTotal = (resTotal + resActual) % div;
            resAcum = (resAcum + resActual * (b-1)) % div;
        }

        if( resTotal == 0 ){
            *d = div;
            return false;
        }
    }

    *d = 1;
    return true;
}

void toBin(long long int v, bool *b){
    for(int i=31;i>=0;i--){
        b[i] = (v%2 == 1);
        v /= 2;
    }
}

int main(){
    int T, N, J, f;
    long long int num, div[9];
    bool bin[32], prime;

    scanf("%d", &T);
    for(int caso=1;caso<=T;caso++){
        printf("Case #%d:\n", caso);
        scanf("%d %d", &N, &J);

        for(num=(1LL<<(N-1))+1, f=0; f < J ;num+=2){
            if( isPrime(num, &div[0]) )
                continue;

            toBin(num, bin);
            prime = false;
            for(int i=3;i<=10;i++)
                if( isPrime(bin, i, N, &div[i-2]) ){
                    prime = true;
                    break;
                }

            if( !prime ){
                for(int i=32-N;i<32;i++)
                    printf("%d", bin[i]);
                for(int i=0;i<9;i++)
                    printf(" %lld", div[i]);
                printf("\n");
                f++;
            }
        }
    }


    return 0;
}
