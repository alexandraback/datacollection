#include<iostream>

using namespace std;

int T;
long A,B;
int ans;
int len;
long pow;
bool ff;
int index;
long q[20];
int tmp,k;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%ld %ld",&A,&B);
        ans=0;len=0;
        tmp=A;
        while(tmp!=0)
        {
            tmp/=10;
            len++;
        }
        pow=1;
        for(long j=1;j<len;j++) pow*=10;
        for(long j=A;j<=B;j++)
        {
            tmp=j;index=0;
            for(k=1;k<len;k++)
            {
                tmp=(tmp%10)*pow+tmp/10;
                if(tmp<=j || tmp>B) continue;
                ff=0;
                for(int l=1;l<=index;l++)
                if(q[l]==tmp)
                {
                    ff=1;
                    break;
                }
                if(ff) continue;
                index++;
                q[index]=tmp;
            }
            ans+=index;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
