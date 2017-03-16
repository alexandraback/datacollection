#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int pecah(int x) {
    int hasil = 0;
    while (x) {
        hasil = (1<<(x % 10)) | hasil;
        //cout<<x%10<<" ";
        x /= 10;
    }
    return hasil;
}

int main() {
    int T,N,ada,haha;
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d",&N);
        if (N == 0) {
            printf("Case #%d: INSOMNIA\n",l);
            continue;
        }
        
        ada = 0;
        haha = 0;
        while (ada != 1023) {
            haha += N;
            ada = pecah(haha) | ada;
            //cout<<ada<<endl;
        }
        
        printf("Case #%d: %d\n",l,haha);
    }
    return 0;
}
