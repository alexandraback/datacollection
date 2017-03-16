#include<cstdio>
#include<bitset>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int cases=1; cases<=N; cases++)
    {
        int n, ans=0;
        scanf("%d", &n);
        
        if( n==0 )
        {
            printf("Case #%d: INSOMNIA\n", cases);
            continue;
        }
        
        for(bitset<10> u; !u.all(); ans+=n)
            for(int tmp=ans; tmp>0; tmp/=10)
                u[tmp%10]=true;
        
        printf("Case #%d: %d\n", cases, ans-n);
    }
}

/*

5
0
1
2
11
1692

*/