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
#define sci(a)       fscanf(in,"%d",&a)
#define sci2(a,b)       fscanf(in,"%d%d",&a,&b)
#define pf(a)         printf("%d ",a)
#define pf2(a,b)         fprintf(wr,"Case #%d: %d\n",a,b)
int ans[2000001];

int dig(int n,int m)
{
    int cn=0,cm=0;
    while(cn>0&&cm>0)
    {
        cn/=10;
        cm/=10;

    }
    if(cn==0&&cm==0)
    return 1;
    return 0;
}


int fun(int n,int a,int b)
{
    int l=n,r=1,mn,co=0,n1=n;
    while(l>=10)
    {r*=10;
    l/=10;
    }
    l=n;
    while(l>=10)
    {
        mn=r*(n%10)+(n/10);
        l/=10;
        if(n1<mn&&n1>=a&&mn<=b)
        {
            if(ans[mn]!=n1)
            {ans[mn]=n1;
            //printf("%d %d\n",n1,mn);
             co++;
            }
        }
        n=mn;
    }

    return co;
}



int main()
{


     int m,o=1,i,t=0,l,j,a,b;
      int an=0;

    FILE *in;
    in=fopen("s3.in","r");

    FILE *wr;
    wr=fopen("s3o.txt","w");
    sci(t);

     //fs(j,50)
    //fp(i,1,2000001,1)
    //an+=fun(i,111,918);

//printf("%d",an);


    while(t--)
    {
                 an=0;
                sci2(a,b);

                fs(i,2000001)
      ans[i]=0;

               // cout<<a<<" "<<b<<"  ";
                 fp(i,a,b+1,1)
                 an+=fun(i,a,b);
                   // cout<<an<<endl;

        pf2(o,an);

        o++;

    }

   return 0;

}
/*
Case #1: 666
Case #2: 248
Case #3: 388
Case #4: 445
Case #5: 370
Case #6: 485
Case #7: 332
Case #8: 274
Case #9: 398
Case #10: 276
Case #11: 36
Case #12: 268
Case #13: 392
Case #14: 326
Case #15: 0
Case #16: 260
Case #17: 310
Case #18: 286
Case #19: 406
Case #20: 412
Case #21: 398
Case #22: 376
Case #23: 344
Case #24: 374
Case #25: 364
Case #26: 310
Case #27: 242
Case #28: 0
Case #29: 0
Case #30: 264
Case #31: 0
Case #32: 0
Case #33: 266
Case #34: 364
Case #35: 392
Case #36: 480
Case #37: 344
Case #38: 0
Case #39: 384
Case #40: 220
Case #41: 0
Case #42: 354
Case #43: 408
Case #44: 310
Case #45: 0
Case #46: 246
Case #47: 452
Case #48: 0
Case #49: 480
Case #50: 352

*/
