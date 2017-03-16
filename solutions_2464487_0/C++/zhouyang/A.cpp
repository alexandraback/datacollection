#include <iostream>
#include <cstdio>
using namespace std;
long long s[10000];
int main ()
{
    int T;
    long long r,t,ans;
    //freopen("A-small-attempt0.in","r",stdin);
   // freopen("outa.txt","w",stdout);
    scanf("%d",&T);
    for(int Case=1;Case<=T;Case++)
    {
        scanf("%I64d%I64d",&r,&t);
        int ans=1;
        int pos=1;
        for(int i=1;i<10000;i++)
        {
            s[i]=2*i*i-i+2*i*r;
            if(t<s[i])
            {
                ans=i-1;
                break;
            }
        }
        printf("Case #%d: %d\n",Case,ans);
    }
}
