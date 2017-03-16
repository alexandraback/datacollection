#include <iostream>
#include <cstdio>
using namespace std;
int a[15]={1,2,3,11,22,111,121,212,1111,11111,11211,111111,1111111,11111111,111111111};
int A,B;
bool check(int x)
{
    if(x>=A&&x<=B) return true;
    else return false;
}
int process()
{
    int cnt=0;
    for(int i=0;i<5;++i)
    {
        if(check(a[i]*a[i])) cnt++;
    }
    return cnt;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,T;
    scanf("%d",&t);
    T=t;
    while(t--)
    {
        scanf("%d%d",&A,&B);
        printf("Case #%d: %d\n",T-t,process());
    }
    return 0;
}
