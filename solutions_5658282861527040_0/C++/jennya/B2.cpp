#include <stdio.h>

int process()
{
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);

    int ans = 0;
    for(int i=0; i<A; i++)
        for(int j=0; j<B; j++)
            if((i&j)<K) ans++;
    return ans;
}
int main()
{
    int caseNum;
    scanf("%d", &caseNum);
    for(int i=1; i<=caseNum; i++){
        int ans = process();
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
