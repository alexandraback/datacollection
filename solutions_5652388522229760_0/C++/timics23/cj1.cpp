#include<stdio.h>
#include<iostream>
#include<vector>
#define pb push_back
using namespace std;

int T,N,viz[15];


int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%d",&N);
        if(N==0) {
            printf("INSOMNIA\n");
            continue;
        }
        for(int i=0;i<10;++i) {
            viz[i] = 0;
        }
        int cnt = 10;
        int M = N;
        while(cnt) {
            int x = M;
            while(x) {
                if(!viz[x%10]) {
                    viz[x%10] = 1;
                    --cnt;
                }
                x/=10;
            }
            M += N;
        }
        printf("%d\n",M-N);
    }
}
