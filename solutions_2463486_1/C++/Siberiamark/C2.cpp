#include"iostream"
#include"cstdio"
using namespace std;
long long A[10000000];
int ct=1;
long long Judge(long long x)
{
    int a[20];
    int l=1;
    while(x!=0)
    {
        a[l++]=x%10;
        x=x/10;
    }
    l--;
    int j=l,i;
    for(i=1;i<=(l+1)/2;i++)
    {
        if(a[i]!=a[j--])
        return false;
    }
    return true;
}
void build()
{
    long long i;
    for(i=1;i<=10000000;i++)
    {
        if(Judge(i)==true&&Judge(i*i)==true)
        {
            A[ct++]=i*i;
        }
    }
    ct--;
    return;
}
bool judge(long long i,long long a,long long b)
{
    if(i>=a&&i<=b)
    return true;
    return false;
}
int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C.output.txt","w",stdout);
    build();
   int t,o=0;
   scanf("%d",&t);
   while(t--)
   {
       long long a,b;
       int Ct=0;
       scanf("%I64d%I64d",&a,&b);
       for(int i=1;i<=ct;i++)
       {
           if(judge(A[i],a,b)==true)
           Ct++;
       }
       printf("Case #%d: %d\n",++o,Ct);
   }
	return 0;
}
