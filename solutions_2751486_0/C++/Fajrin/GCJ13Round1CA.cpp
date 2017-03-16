#include "cstdio"
#include "cstring"

using namespace std;

char input[1000007];

bool check(char x)
{
    if(x=='a' || x=='i' || x=='u' || x=='e' || x=='o')return false;
    return true;
}

int main(void)
{
    int t;
    
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%s%d",input,&n);
        
        int len = strlen(input);
        
        long long ans=0LL;
        
        /*
        int cons=0;
        int noncons=1;
        long long now=0;
        long long lens=(long long)(len*1LL);
        */
        
        long long start=0;
        long long cons=0LL;
        long long now=0LL;
        long long en=(long long)(n*1LL);
        long long lens=(long long)(len*1LL);
        
        for(int i=0;i<len;i++)
        {
            if(check(input[i]))cons++;
            else cons=0;
            
            //printf("%d %lld %lld\n",i,cons,start);
            
            if(cons==n)
            {
                long long bef=(now-start-en+2LL);
                long long next=lens-now;
                
                ///printf("--> %lld %lld\n",bef,next);
                
                ans+=bef*next;
                
                cons--;
                start=now-en+2LL;
            }
            
            now++;
        }
        
        printf("Case #%d: %lld\n",test,ans);
    }
    return 0;
}
