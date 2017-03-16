#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include<algorithm>
#include <fstream>
#include <string>
using namespace std;

typedef pair<int,int> PII;
#define fp(i,a,b,c)  for(i=a;i<b;i+=c)
#define fn(i,a,b,c)  for(i=a;i>b;i-=c)
#define fs(i,a)      for(i=0;i<a;i++)
#define sci(a)       fscanf(in,"%d\n",&a)
#define sci2(a,b)       fscanf(in,"%d%d",&a,&b)
#define pf(a)         printf("%d ",a)
#define pf2(a,b)         fprintf(wr,"Case #%d: %d\n",a,b)


int arr[1111];

int main()
{
     int m,o=1,i,t,l,s,p,n,ans;
    FILE *in;
    in=fopen("s2.in","r");

    FILE *wr;
    wr=fopen("s2o.txt","w");
    sci(t);

    while(t--)
    {

        sci2(n,s);
        sci(p);
         ans=0;
        fs(i,n)
        sci(arr[i]);
        fs(i,n)
        {
            if(p<=1)
            {
                if(p==0)
                ans++;
                else
                {
                    if(arr[i]>=3*p-2)
                       ans++;
                }
            }
            else
            if(arr[i]>=3*p-2)
            ans++;
            else
            {
                if(s>0&&3*p-4<=arr[i])
            {
                s--;
                ans++;
            }
            }


        }

        pf2(o,ans);

        o++;

    }


   return 0;

}
