#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

long long m;
long long n;

int total = 0;
long long res[1000000];

bool palindromes(long long x){
    int a[100];
    int len = 0;
    while (x > 0){
            a[len++]= x%10;
            x = x/10;
    }
    int i = 0;
    int j = len;
    while (i < j){
        if (a[i]!=a[j-1])
            return false;
        i++;
        j--;
    }
    return true;
}

void preProcess(){
    for (long long x = 1; x < 10000101; x++){
        if(palindromes(x)){
            long long temp = x*x;
            if (palindromes(temp)){
                res[total++] = temp;
               //rintf("%lld %lld\n",temp, (long long)(sqrt(temp)));
            }
        }
    }
}

int countInterval(long long x, long long y){
    int count = 0;
    int i = 0;
    while (i <= total){
        if (res[i] > y) return count;
        if (res[i] >= x) count++;
        i++;
    }
    return count;
}


int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    int t;
    scanf("%d",&t);
    preProcess();
    for (int i = 0; i < t; i++){
        scanf("%lld %lld",&m,&n);
        printf("Case #%d: %d\n",i+1,countInterval(m,n));
    }
//    cout << "Hello world!" << endl;
    return 0;
}
