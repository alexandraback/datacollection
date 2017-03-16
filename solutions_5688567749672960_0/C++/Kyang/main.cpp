#include <iostream>
#include <stack>
#include <fstream>
#define DEBUG
#define maxn 1000000
using namespace std;
int n;
int a[maxn+4];
int b[100];
int res(int i)
{
    int e=i,r=1,p=0;
    int len=0;
    while(e>0)
    {
        b[++len]=e%10;
        e/=10;
    }
    while(len>0)
    {
        p+=b[len--]*r;
        r*=10;
    }
    return p;
}
bool pd(int i)
{
    if (i%10==0 || i<10)
        return false;
    return true;
}
int main()
{
    int t,iCase=0;
    #ifdef DEBUG
        fstream in("1.in");
        in>>t;
        #else
        cin>>t;
    #endif // DEBUG
    FILE *out=fopen("2.txt","w");
    while(t--)
    {
        #ifdef DEBUG
            in>>n;
            #else
            cin>>n;
        #endif // DEBUG
        int i=1,ans=1;
        a[1]=1;
        for (int i=2;i<=n;i++)
        if (pd(i) && res(i)<i)
            a[i]=min(a[i-1],a[res(i)])+1;
        else
            a[i]=a[i-1]+1;
        fprintf(out,"Case #%d: %d\n",++iCase,a[n]);
        //printf("Case #%d: %d\n",++iCase,a[n]);
    }
    return 0;
}
