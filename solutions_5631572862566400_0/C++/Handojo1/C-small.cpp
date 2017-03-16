#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

bool pakai[15];
int jawab,N,T,arrow[15],urut[15];

void check(int s) {
    bool flag = true;
    for (int i=2;i<s && flag;++i) {
        if (arrow[urut[i]] != urut[i-1] && arrow[urut[i]] != urut[i+1]) flag = false;
    }
    if (arrow[urut[1]] != urut[s] && arrow[urut[1]] != urut[2]) flag = false;
    if (arrow[urut[s]] != urut[s-1] && arrow[urut[s]] != urut[1]) flag = false;
    if (flag) {
        //for (int i=1;i<=s;++i) printf("%d ",urut[i]);
        //printf("\n");
        jawab = max(jawab,s);
    }
}

void permut(int num) {
    if (num > 2) check(num-1);
    
    if (num <= N) {
        for (int i=1;i<=N;++i) {
            if (pakai[i]) continue;
            urut[num] = i;
            pakai[i] = true;
            permut(num+1);
            pakai[i] = false;
            urut[num] = 0;
        }
    }
}

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d",&N);
        jawab = 0;
        
        for (int i=1;i<=N;++i) {
            scanf("%d",&arrow[i]);
        }
        
        permut(1);
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
