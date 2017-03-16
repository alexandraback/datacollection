#include<stdio.h>
#include<math.h>

char A[10000];
long long data[10000099];

long long ToString(long long N)
{
    long long i=0;
    while(N)
    {
        A[i]=(N%10 + '0');
        N/=10;
        i++;
    }
    return i;
}

bool ispalin(long long N)
{
    long long i,j=ToString(N);
    bool ret=true;
    for(i=0,--j;i<j;i++,j--)
    {
        if(A[i]!=A[j]) { ret=false; break; }
    }
    return ret;
}

int main()
{
    long long T,c=0,A,B,i,j,k,a,b;
    k=sqrt(100000000000000);
    for(i=1;i<=k;i++)
    {
        if(ispalin(i))
        {
            if(ispalin(i*i))
            {
                data[i]=1;
            }
        }
    }

    for(i=1;i<=10000000;i++) data[i]+=data[i-1];

    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);

    scanf("%lld",&T);
    while(c++<T)
    {
        scanf("%lld%lld",&A,&B);

        a=sqrt(A);
        if((a*a)!=A) a++;
        b=sqrt(B);

        printf("Case #%lld: %lld\n",c,data[b]-data[a-1]);

    }
    return 0;
}
