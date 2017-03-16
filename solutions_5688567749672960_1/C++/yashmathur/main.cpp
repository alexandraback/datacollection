#include <cmath>
#include <iostream>
#include<stdio.h>
using namespace std;

int dig(long long int n){
    if (n == 0)
        return 0;

    int ans=0;
    while (n>0){
        n /= 10;
        ans += 1;
    }
    return ans;
}

long long ld(long long int N, int len, int MSB){
    long long int ans = N - MSB*(pow(10, len-1));
    return ans;
}

long long int ms(int N){
    if (N == 0)
        return 0;

    if (N == 1)
        return 0;

    if (N == 2)
        return 10;

    if (N >= 3){
        long long ans = 10;
        ans = ans + (N-2)*9;
        for (int i = 1; i <= N-2; i++)
            ans = ans + pow(10, i);

        return ans;
    }
}


int main(){

    freopen("input.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, i;
    cin>>t;
    for (i = 1; i <= t; i++){
        long long int aa;
        long long int N;
        cin>>N;
        int len = dig(N);
        long long int ns = ms(len);

        int mb = N/pow(10, len-1);
        long long int dem = ld(N, len, mb);

        if (N <= 10)
            aa = N;

        else if (mb == 1)
            aa = ns + dem;

        else if (mb != 1)
            aa = ns + mb + dem;

        cout<<"Case #"<<i<<": "<<aa<<endl;
    }
    return 0;

}
