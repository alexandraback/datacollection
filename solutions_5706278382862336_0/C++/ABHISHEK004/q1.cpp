#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<cstdlib>

using namespace std;

int gcd(int a,int b)
{
 int r, i;
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
        int t,i,m,n,k,k1,k2,p,q,a1,a2,ans;
        int j;
        char r;
        scanf("%d",&t);
        k=t;
        while(t--)
        {
                scanf("%d",&p);
                scanf("%c",&r);
                scanf("%d",&q);
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
                                printf("Case #%d: %d\n",k-t,j);
                        else
                                printf("Case #%d: impossible\n",k-t);
                }
                else
                {
                        j=log2(q);
                        if(pow(2,j)==q)
                        {
                                if(p>(q/2))
                                        printf("Case #%d: 1\n",k-t);
                                else
                                {
                                        a1=q;
                                        int cc=0;
                                        while(p<a1)
                                        {
                                                a1=a1/2;
                                                cc++;
                                        }
                                        printf("Case #%d: %d\n",k-t,cc);
                                }
                        }
                        else
                        {
                                printf("Case #%d: impossible\n",k-t);
                        }
                }
                //printf("Case #%d: %d\n",k-t,ans);
        }
       return 0;
}
