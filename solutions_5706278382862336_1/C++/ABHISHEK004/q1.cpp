#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<cstdlib>

using namespace std;

long long int gcd(long long int a,long long int b)
{
 long long int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}


int min(int a,int b)
{
        return a<b?a:b;
}
int max(int a,int b)
{
        return a>b?a:b;
}

int main()
{
        freopen("C:\\Users\\ABHISHEK KUMAR\\Desktop\\a.in","r",stdin);
       freopen("C:\\Users\\ABHISHEK KUMAR\\Desktop\\b.out","w",stdout);
        long long int t,i,m,n,k,k1,k2,p,q,a1,a2,ans;
        long long int j;
        char r;
        scanf("%lld",&t);
        k=t;
        while(t--)
        {
                scanf("%lld",&p);
                scanf("%c",&r);
                scanf("%lld",&q);
                //printf("p->%d\n",p);
                // printf("q->%d\n",q);
                n=gcd(p,q);
                p=p/n;
                q=q/n;
                //printf("p->%d\n",p);
                 //printf("q->%d\n",q);
                if(p==1)
                {
                        j=log2(q);
                        if(pow(2,j)==q)
                                printf("Case #%lld: %lld\n",k-t,j);
                        else
                                printf("Case #%lld: impossible\n",k-t);
                }
                else
                {
                        j=log2(q);
                        if(pow(2,j)==q)
                        {
                                if(p>(q/2))
                                        printf("Case #%lld: 1\n",k-t);
                                else
                                {
                                        a1=q;
                                        int cc=0;
                                        while(p<a1)
                                        {
                                                a1=a1/2;
                                                cc++;
                                        }
                                        printf("Case #%lld: %lld\n",k-t,cc);
                                }
                        }
                        else
                        {
                                printf("Case #%lld: impossible\n",k-t);
                        }
                }
                //printf("Case #%d: %d\n",k-t,ans);
        }
       return 0;
}
