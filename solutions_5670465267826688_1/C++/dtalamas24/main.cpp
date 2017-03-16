#include <iostream>
#include <cstdio>

using namespace std;

char Z[100005];
long long B[100005];
long long casos, mide, veces, hasta, usado=1, Y[100005][15];
long long A[10][10], va, vueltas, pos;

inline long long ab(long long num){
    return num > 0 ? num : -num;
}

long long mul(long long x, long long y){
    return A[ab(x)][ab(y)]*x/ab(x)*y/ab(y);
}



int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);

    A[1][1]=1;
    A[1][2]=2;
    A[1][3]=3;
    A[1][4]=4;
    A[2][1]=2;
    A[2][2]=-1;
    A[2][3]=4;
    A[2][4]=-3;
    A[3][1]=3;
    A[3][2]=-4;
    A[3][3]=-1;
    A[3][4]=2;
    A[4][1]=4;
    A[4][2]=3;
    A[4][3]=-2;
    A[4][4]=-1;

    scanf("%lld",&casos);
    for(long long v=1; v<=casos; v++){
        scanf("%lld%lld%s",&mide,&veces,Z);
        printf("Case #%lld: ",v);
        for(long long i=0; i<mide; i++){
            B[i]=Z[i]-'i'+2;
        }
        va=1;
        for(long long i=0; i<mide; i++){
            va = mul(va, B[i]);
        }
        if(ab(va)>1){
            if(veces%4!=2){
                printf("NO\n");
                continue;
            }
        }
        if(va==1){
            printf("NO\n");
            continue;
        }
        if(va==-1){
            if(veces%2!=1){
                printf("NO\n");
                continue;
            }
        }

        ++usado;
        va=1;
        hasta=2;
        vueltas=0;
        pos=0;
        while(Y[pos][va+4]!=usado){
            Y[pos][va+4]=usado;
            va=mul(va, B[pos]);
            ++pos;
            if(pos==mide){
                ++vueltas;
                pos=0;
            }
            if(va==hasta){
                break;
            }
        }
        if(va!=hasta){
            printf("NO\n");
            continue;
        }

        ++usado;
        va=1;
        hasta=3;
        while(Y[pos][va+4]!=usado){
            Y[pos][va+4]=usado;
            va=mul(va, B[pos]);
            ++pos;
            if(pos==mide){
                ++vueltas;
                pos=0;
            }
            if(va==hasta){
                break;
            }
        }
        if(va!=hasta or vueltas>=veces){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}
