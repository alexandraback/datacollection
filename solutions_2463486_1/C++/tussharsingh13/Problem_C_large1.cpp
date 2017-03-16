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
long long arr[100];
int fair(long long n)
{
    int i;
    if(n>=4004009004004LL)
    return 40;
    for(i=0;arr[i]<=n&&i<41;i++);
    return i;
}
int main()
{

    FILE *fp,*fw,*fr;
    fp=fopen("C-large-1.in","r");
    fr=fopen("Fair_and_Square.txt","r");
    fw=fopen("Output_Problem_C_Large.txt","w");

    int i,j,k,t;
    i=0;
    while(fscanf(fr,"%lld",&arr[i++])!=EOF);
    fscanf(fp,"%d",&t);
    FOR(k,1,t+1)
    {
        long long a,b;
        fscanf(fp,"%lld %lld",&a,&b);
        int ans=fair(b)-fair(a-1);
        fprintf(fw,"Case #%d: %d\n",k,ans);
    }
    return 0;
}
