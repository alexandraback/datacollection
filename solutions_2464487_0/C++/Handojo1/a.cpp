#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    int kasus;
    long long jari,volume;
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        cin>>jari>>volume;
        long long kiri = 0;
        long long kanan = volume;
        //cout<<kiri<<" "<<kanan<<endl;
        while (kanan-kiri > 1) {
            long long tengah = (kiri+kanan) / 2LL;
            if (2LL*jari + 2LL*tengah-1 <= volume / tengah) kiri = tengah;
            else kanan = tengah;
        }
             
        cout<<"Case #"<<l<<": "<<kiri<<endl;
    }
    return 0;
}
