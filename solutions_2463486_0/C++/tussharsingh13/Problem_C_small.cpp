//Author: Tusshar Singh
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

#define mod 1000000007
#define inf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define ll long long
int palin(int num)
{
    if(num==0)
    return 0;
    if(num<4)
    return 1;
    if(num<9)
    return 2;
    if(num<121)
    return 3;
    if(num<484)
    return 4;
    return 5;
}
int main() 
{
    int i,j,k,t;
    scanf("%d",&t);
    FOR(k,1,t+1)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int ans;
        ans=palin(b)-palin(a-1);
        printf("Case #%d: %d\n",k,ans);
    }
    return 0;
}