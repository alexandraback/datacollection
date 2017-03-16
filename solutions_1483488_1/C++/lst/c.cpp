#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;
bool b[2000010];
long long ten[100]={1};
char c[10];
int int_to_char(int a)
{
    int j,i=0;
    while(a>0)
    {
        c[i++]=a%10+'0';
        a/=10;
    }
    c[i]=0;
    for(j=0;j<i/2;j++)
    {
        char t=c[j];
        c[j]=c[i-1-j];
        c[i-1-j]=t;
    }
    return i;
}
long long fun(int A,int B)
{
    long long res=0;
    for(int num=A+1;num<B;num++)
    {
        if(b[num]==1)
            continue;
        int n=int_to_char(num);
        b[num]=1;
        long long count=1;
        for(int i=1;ten[i]<=num;i++)
        {
            int back,front,new_num;
            back=num%ten[i];
            front=num/ten[i];
            new_num=back*ten[n-i]+front;
            if(new_num<B && new_num>A && b[new_num]==0)
            {
                b[new_num]=1;
                count++;
            }
        }
        res+=((count-1)*count/2);
    }
    return res;
}
        
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<20;i++)
        ten[i]=ten[i-1]*10;
    int A,B;
    for(int _=1;_<=T;_++)
    {
        memset(b,0,sizeof(b));
        scanf("%d%d",&A,&B);
        printf("Case #%d: %lld\n",_,fun(A,B));
    }
    return 0;
}
