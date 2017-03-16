#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int _ = 1; _<=T; _++)
    {
        printf("Case #%d: ",_);
        int A,B,K;
        scanf("%d%d%d",&A,&B,&K);
        int cnt = 0;
        for(int i = 0;i<A;i++)
        for(int j = 0;j<B;j++){
            if((i&j) <K) cnt++;
        }
        printf("%d\n",cnt);
    }
}
