#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <limits.h>
#define ll unsigned long long int
#define mod 1000000009
using namespace std;
char a[100];


int main()
{

  //freopen("C:\\Users\\jack\\Desktop\\in.txt","r",stdin);
 //freopen("C:\\Users\\jack\\Desktop\\out.txt","w",stdout);

    int test=1,tt;
    scanf("%d",&tt);
    while(test<=tt)
    {
          scanf("%s",a);
          int l=strlen(a);
          
          ll num=0;
          
          int i=0;
          while(a[i]!='/')
          {
            num=num*10+(a[i]-48);
            i++;                
           }
           ll den=0;
           i++;
           while(i<l)
          {
            den=den*10+(a[i]-48);
            i++;                
           }
           
           ll div=__gcd(num,den);
           num=num/div;
           den=den/div;
           
           bool flag=false;
           if(den && (!(den & den-1)))
           {
             if( (num & 1) && (num<=(den-1)) )
              flag=true;       
                  
           }
           
           if(flag)
           {
             ll idx=1;
             ll gg=1;
             while(gg<den)
             {gg<<=1;idx++;}
             
             
             int nx=0;
             
             while(num!=0)
             {
              num>>=1;
              
              nx++;
                       
              }
              
              int ans=idx-nx;
              
              if(ans>40)
                printf("Case #%d: impossible\n",test);
              
              
             else
             printf("Case #%d: %d\n",test,idx-nx);
                   
             }
             
             else
              printf("Case #%d: impossible\n",test);
           
            
            test++;


                 }

    }
