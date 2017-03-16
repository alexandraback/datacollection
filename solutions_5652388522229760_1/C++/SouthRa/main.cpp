#include<cstdio>

bool used[15];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t, n, cases, i, r, cur, tmp;
    scanf("%d", &t);
    for(cases=1;cases<=t;cases++){
        scanf("%d", &n);
        if(n==0){
            printf("Case #%d: INSOMNIA\n", cases);
            continue;
        }
        for(i=0;i<13;i++) used[i]=0;
        r=10;
        cur=0;
        while(r){
            cur+=n;
            tmp=cur;
            while(tmp){
                if(used[tmp%10]==0){
                    used[tmp%10]=1;
                    r--;
                }
                tmp/=10;
            }
        }
        printf("Case #%d: %d\n", cases, cur);
    }
}
