#include <cstdio>
#include <iostream>

using namespace std;

int casos, hay=0, mide, emp, son;
long long R[100005], B[20], a, b, izq, der, m1, m2, en, x, y, fair;

bool checa(long long num){
    if(num==0){
        return true;
    }
    en=100000000000000LL;
    emp=0;
    for(int i=1; i<=15; i++){
        if(num>=en and emp==0){
            emp=i;
        }
        B[i]=num/en;
        num%=en;
        en/=10;
    }
    x=emp;
    y=15;
    while(x<y){
        if(B[x]!=B[y]){
            return false;
        }
        ++x;
        --y;
    }
    return true;
}

void recu(int dnde, long long lleva){
    if(mide%2==1 and dnde==mide/2+1){
        for(int i=0; i<10; i++){
            recu(dnde+1, lleva+izq*i);
        }
    }
    else if(dnde==1){
        for(int i=1; i<10; i++){
            m1=izq;
            m2=der;
            izq/=10;
            der*=10;
            recu(dnde+1, lleva+m1*i+m2*i);
            izq*=10;
            der/=10;
        }
    }
    else if(dnde<=mide/2){
        for(int i=0; i<10; i++){
            m1=izq;
            m2=der;
            izq/=10;
            der*=10;
            recu(dnde+1, lleva+m1*i+m2*i);
            izq*=10;
            der/=10;
        }
    }
    else {
        fair=lleva*lleva;
        if(checa(fair)){
            ++hay;
            R[hay]=fair;
        }
    }
}

void aslo(){
    izq=1;
    for(int i=1; i<mide; i++){
        izq*=10;
    }
    der=1;
    recu(1, 0);
}

int main()
{
    freopen("fairin.txt","r",stdin);
	freopen("fair.txt","w",stdout);
    for(mide=1; mide<=7; mide++){
        aslo();
    }
    scanf("%d",&casos);
    for(int va=1; va<=casos; va++){
        son=0;
        scanf("%lld%lld",&a,&b);
        for(int i=1; i<=hay; i++){
            if(R[i]>=a and R[i]<=b){
                ++son;
            }
        }
        printf("Case #%d: %d\n",va,son);
    }
    return 0;
}
