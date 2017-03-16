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
#define sci2(a,b)       fscanf(in,"%d%d ",&a,&b)
#define pf(a)         printf("%d ",a)
#define pf2(a,b)         fprintf(wr,"Case #%d: %s\n",a,b)


char str[1000];
char ans[1000];
char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};


int main()
{

    map[25]='q';
    map['q'-97]='z';

     int m,o=1,i,t,l;
    FILE *in;
    in=fopen("s1.in","r");

    //FILE *in2;
    //in2=fopen("s12.txt","r");

    FILE *wr;
    wr=fopen("s1o.txt","w");
    sci(t);

    while(t--)
    {
                  fgets ( str, 1001, in );
                             fscanf(in,"\n");
                              //fgets ( ans, 1001, in2 );
                             //fscanf(in,"\n");


        l=strlen(str);
        fs(i,l)
        {
            if(str[i]==' ')
             ans[i]=' ';
             else
            ans[i]=map[str[i]-97];
           // map[str[i]-97]=ans[i];
           //map[ans[i]-97]=str[i];

        }
        ans[i]='\0';
        pf2(o,ans);

        o++;

    }
   // fs(i,26)
    //fprintf(wr,"%c,",map[i]);

   return 0;

}
