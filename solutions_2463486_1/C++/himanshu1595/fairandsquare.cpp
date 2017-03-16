#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<climits>
using namespace std;

int t, flag, len, c=1;
char str[100];
vector <long long> arr;
long long j, a, b;

long long fun(long long n)
{
    long long temp=0;
    while(n!=0)
    {
        temp*=10;
        temp+=n%10;
        n/=10;
    }
    return temp;
}

int main()
{
    for(int i=1; i<=10000000; i++)
    {
        itoa(i, str, 10);
        len=strlen(str);
        flag=0;
        for(int k=0; k<=len/2; k++)
            if(str[k]!=str[len-1-k])
            {
                flag=1;
                break;
            }
        if(!flag)
        {
            j=(long long)(i);
            j*=j;
            long long temp=fun(j);
            if(temp==j)
                arr.push_back(j);
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        int counter=0;
        scanf("%lld%lld",&a,&b);
        for(int i=0; (i<arr.size())&&(arr[i]<=b); i++)
            if(arr[i]>=a)
                counter++;
        printf("Case #%d: %lld\n",c++, counter);
    }
    return 0;
}
