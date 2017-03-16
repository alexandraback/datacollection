#include"iostream"
#include"cstdio"
using namespace std;
bool judge(int i,int a,int b)
{
    if(i>=a&&i<=b)
    return true;
    return false;
}
int A[6]={0,1,4,9,121,484};
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.output.txt","w",stdout);
   int t,o=0;
   scanf("%d",&t);
   while(t--)
   {
       int a,b;
       int ct=0;
       scanf("%d%d",&a,&b);
       for(int i=1;i<=5;i++)
       {
           if(judge(A[i],a,b)==true)
           ct++;
       }
       printf("Case #%d: %d\n",++o,ct);
   }
	return 0;
}
