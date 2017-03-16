#include<stdio.h>
#include<iostream>
#include<fstream>
#include <string.h>
#include<math.h>
#define R return
#define FR(i,a,b) for(int i=a;i<b;i++)
#define RFR(i,a,b) for(int i=a;i>=b;i--)
#define SC(x) scanf("%d",&x)
#define SSC(x) scanf("%s",x)
#define LSC(x) scanf("%lld",&x)
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define IN(i,j) a[i][j]
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define FUN(x) x==true)?1:0
#define SWAP(x,y,z) {z=x;x=y;y=z;}
#define mod 1000000003
using namespace std;
typedef long long int L;
int main()
{
    int t;
    FILE *ifile  = fopen("input.txt", "r");
    FILE *ofile = fopen("output.txt", "w");
    fscanf(ifile,"%d",&t); 
    //SC(t);
    FR(h,1,t+1)
    {
              L a,b,k;
              fscanf(ifile, "%lld",&a); 
              fscanf(ifile, "%lld",&b);
              fscanf(ifile, "%lld",&k);
              L sum=0;
              if(k>=a || k>=b)
              {
               sum = a*b;
               fprintf(ofile, "Case #%d: %lld\n",h,sum);
              }
              else
              {
               sum = k*k;
               sum+=(a-k)*(k);
               sum+=(b-k)*(k);
               FR(i,k,a)
               {
                FR(j,k,b)
                {
                 L tmp= (i & j);
                 if(tmp<k)
                 sum++;
                }
               }
               fprintf(ofile, "Case #%d: %lld\n",h,sum);
              }
    }
    fclose(ifile);
    fclose(ofile); 
    //system("pause");
     R 0;
}
