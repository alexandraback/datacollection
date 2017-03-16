#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power(int b,int n)
{
    int ret = 1;
    for(int i = 0;i < n;i++) ret *= b;
    return ret;
}

int totalDigit(int num)
{
    int ret = 0;
    while(power(10,ret) <= num) ret++;
    return ret-1;
}

bool isPalin(int num)
{
    int totDigit = totalDigit(num);
    for(int j = 0;power(10,j) <= num;j++)
    {
        int dig = num / power(10,j) % 10;
        int dig2 = num / power(10,totDigit-j) % 10;
        if(dig != dig2) return false;
    }
    return true;
}

int main()
{
    int t,tt;
    scanf("%d",&tt);
    for(t=0;t < tt;t++)
    {
        int a,b;
        int cnt=0;
        scanf("%d %d",&a,&b);
        for(int i = int(sqrt(a));i <= int(sqrt(b));i++)
        {
            if(i*i < a) continue;
            if(isPalin(i)) // if this is palin
                if(isPalin(i*i)) // square and check palin
                    cnt++;
        }
        printf("Case #%d: %d\n",t+1,cnt);
    }
}
