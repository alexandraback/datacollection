#include <bits/stdc++.h>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    long long N,A(0);
    int T;
    scanf("%d",&T);
    for(int CASE=1;CASE<=T;CASE++)
    {
        scanf("%lld",&N);
        if(N==0)
        {
            printf("Case #%d: INSOMNIA\n",CASE);
            continue;
        }
        int mask=0,brj=0;
        do
        {
            brj++;
            A=brj*N;
            while(A)
            {
                mask|=(1<<(A%10));
                A/=10;
            }
        }while(mask!=1023);
        printf("Case #%d: %lld\n",CASE,N*brj);
    }
    return 0;
}
