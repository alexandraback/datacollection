#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<sstream>
#include <stack>
#include <list>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647 //2^31-1
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define assign(x,n) x=(int*)calloc(n,4)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define SWAP(a,b) a= a^b, b=a^b, a=a^b
typedef  long long int ull;
using namespace std;

int main()
{
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

int t,tc=1;read(t);
while(t--){ printf("Case #%d: ",tc++); 
           int x,y,a,b,f=0,g=0,p,q;read(x);read(y);
           int s=1;
           a=0;b=0;
           p=x;q=y;
           if(x<0)x=-x;if(y<0)y=-y;
           while(a+s<=x){
                         a=a+s;if(p>0)printf("E");else printf("W");
                         s++;
                         if(a==x){f=1;break;}
                         }
           if(!f){
                  while(a!=x){a++;if(p>0)printf("WE");else printf("EW");
                              s+=2;
                              }
                  }
           while(b+s<=y){
                         b=b+s;if(q>0)printf("N");else printf("S");
                         s++;
                         if(b==y){g=1;break;}
                         }
           if(!g){
                  while(b!=y){b++;
                              s+=2;if(q>0)printf("SN");else printf("NS");
                              }
                  }       
            printf("\n")  ;//if(s>=500)cout<<"yoyo"<<endl;    
           }

//system("pause");
return 0;
}

