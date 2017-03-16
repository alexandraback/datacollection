#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>
#define s(n) scanf("%d",&n)
using namespace std;
#define lint long long int
#define max 10000001
int arr[max];
int numrev(int num)
{

    int rev_num = 0;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
 freopen("op1.txt","w",stdout);
    int t,i,j,k,ans,num=1,temp;
    for(i=1;i<=max;i++)
    {
        arr[i]=max;
    }
    arr[1]=1;
    for(i=2;i<=max;i++)
    {
        arr[i]=min(arr[i],arr[i-1]+1);
        temp=numrev(i);
        arr[temp]=min(arr[temp],arr[i]+1);
    }
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        int n;
        s(n);
        printf("Case #%d: %d\n",k,arr[n]);
    }
    return 0;
}
