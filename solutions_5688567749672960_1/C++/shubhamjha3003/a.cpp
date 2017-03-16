#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1001000];
long long calc(long long n)
{
    long long counter=1;
    long long temp,rev;
    long long int arr[20];
    int k,len;
    while(n!=1)
    {
        //printf("%lld %lld\n",n,counter);
        if(n<1001000)
        {
            counter=counter+dp[n]-1;
            break;
        }
        if(n==91)
        {
            counter+=19;
            break;
        }
        temp=n;
        k=0;
        while(temp)
        {
            arr[k]=temp%10;
            k++;
            temp/=10;
        }
        len=k;
        if(arr[0]!=1)
        {
            while(n%10!=1)
            {
                n--;
                counter++;
            }
            //printf("%lld\n",n);
            /*if(n!=1)
            {
                temp=n;
                rev=0;
                while(temp)
                {
                    rev=10*rev+temp%10;
                    temp/=10;
                }
                if(rev!=n)
                    counter++;
                n=rev;
            }*/
        }
        else
        {
            bool test=true;
            for(k=1;k<len-1;k++)
            {
                if(arr[k]>0)
                    test=false;
            }
            if(test)
            {
                temp=1;
                for(k=0;k<len-1;k++)
                {
                    if(k!=0)
                        arr[k]=9;
                }
                temp=0;
                for(k=len-2;k>=0;k--)
                {
                    temp=10*temp+arr[k];
                }
                counter=counter+n-temp;
                n=temp;
            }
            else
            {
                k=0;
                while(k<len&&arr[k]==0)
                    k++;
                if(k>0)
                {
                    arr[k]=arr[k]-1;
                }
                k--;
                while(k>=0)
                {
                    arr[k]=9;
                    k--;
                }
                temp=0;
                for(k=len-1;k>=0;k--)
                {
                    temp=10*temp+arr[k];
                }
                n=temp;
                k=len-2;
                while(k>=0&&arr[k]==0)
                    k--;
                k=len-k-1;
                while(k>=0)
                {
                    arr[k]=0;
                    k--;
                }
                arr[0]=1;
                temp=0;
                for(k=len-1;k>=0;k--)
                {
                    temp=10*temp+arr[k];
                }
                counter=counter+n-temp;
                n=0;
                for(k=0;k<len;k++)
                {
                    n=10*n+arr[k];
                }
                if(n!=temp)
                    counter=counter+1;
            }
        }
    }
    return counter;
}
int main()
{
    int t,i,j,rev,temp;
    long long res,n;
    dp[1]=1;
    for(i=2;i<1001000;i++)
    {
        j=i;
        rev=0;
        while(j)
        {
            rev=10*rev+j%10;
            j/=10;
        }
        dp[i]=1+dp[i-1];
        if(rev<i&&i%10!=0)
        {
            dp[i]=min(dp[i],1+dp[rev]);
        }
    }
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        res=calc(n);
        printf("Case #%d: %lld\n",i,res);
    }
    return 0;
}
