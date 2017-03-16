#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>
using namespace std;

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define PI acos(-1.0)
#define SQ(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define MAX_INT 2147483647
#define inf 1<<30
#define FOR(i,a,b) for(i=(a);i<=(b);i++)
#define FORV(i,a,b) for(i=(a);i>=(b);i--)
#define REP(i,n) for(i=0;i<(n);i++)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define nl printf("\n")
#define set(A,x) memset(A,x,sizeof(A))
#define in(x) scanf("%d",&x)
#define inll(x) scanf("%lld",&x)
#define LL long long
//#define LL __int64
#define MX 10000

template<class T>inline T _abs(T n){return n<0?-n:n;}
template<class T>inline T _gcd(T a, T b){return b==0?a:_gcd(b,a%b);}
template<class T>inline T _lcm(T a, T b){return a/_gcd(a,b)*b;}

int setb(int N,int pos){return N= N | (1<<pos);}
int resetb(int N,int pos){return N= N & ~(1<<pos);}
bool checkb(int N,int pos){return (bool)(N & (1<<pos));}

int indx(char ch)
{
    return ch-'A';
}


int main()
{
    freopen("A-large.in","r",stdin);
    freopen("a_large_output.txt","w",stdout);

    int test,cases=0;
    char s[2020];
    in(test);
    getchar();
    while(test--)
    {
        gets(s);
        int a[26]={0};
        int len= strlen(s);
        for(int i=0;i<len;i++)
            a[s[i]-'A']++;
        int b[10]={0};
        int temp;
        //zero
//        printf("zero\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('Z')]>0)
        {
            temp = a[indx('Z')];
            b[0]=temp;
            a[indx('Z')]-=temp;
            a[indx('E')]-=temp;
            a[indx('R')]-=temp;
            a[indx('O')]-=temp;


        }
//        printf("two\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        //two
        if(a[indx('W')]>0)
        {
            temp = a[indx('W')];
            b[2]=temp;
            a[indx('T')]-=temp;
            a[indx('W')]-=temp;
            a[indx('O')]-=temp;

        }
        //four
//        printf("four\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('U')]>0)
        {
            temp = a[indx('U')];
            b[4]=temp;
            a[indx('F')]-=temp;
            a[indx('O')]-=temp;
            a[indx('U')]-=temp;
            a[indx('R')]-=temp;

        }
        //six
//        printf("six\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('X')]>0)
        {
            temp = a[indx('X')];
            b[6]=temp;
            a[indx('S')]-=temp;
            a[indx('I')]-=temp;
            a[indx('X')]-=temp;

        }
        //eight
//        printf("eight\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('G')]>0)
        {
            temp = a[indx('G')];
            b[8]=temp;
            a[indx('E')]-=temp;
            a[indx('I')]-=temp;
            a[indx('G')]-=temp;
            a[indx('H')]-=temp;
            a[indx('T')]-=temp;

        }
        //one
//        printf("one\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('O')]>0)
        {
            temp = a[indx('O')];
            b[1]=temp;
            a[indx('O')]-=temp;
            a[indx('N')]-=temp;
            a[indx('E')]-=temp;

        }
        //three
//        printf("three\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('R')]>0)
        {
            temp = a[indx('R')];
            b[3]=temp;
            a[indx('T')]-=temp;
            a[indx('H')]-=temp;
            a[indx('R')]-=temp;
            a[indx('E')]-=temp;
            a[indx('E')]-=temp;

        }
        //seven
//        printf("seven");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('S')]>0)
        {
            temp = a[indx('S')];
            b[7]=temp;
            a[indx('S')]-=temp;
            a[indx('E')]-=temp;
            a[indx('V')]-=temp;
            a[indx('E')]-=temp;
            a[indx('N')]-=temp;

        }
        //five
//        printf("five\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('V')]>0)
        {
            temp = a[indx('V')];
            b[5]=temp;
            a[indx('F')]-=temp;
            a[indx('I')]-=temp;
            a[indx('V')]-=temp;
            a[indx('E')]-=temp;

        }
        //nine
//        printf("nine\n");
  //      for(int i=0;i<26;i++)
    //        printf("%c %d ",i+'A',a[i]);
      //      nl;
        if(a[indx('N')]>0)
        {
            temp = a[indx('N')]/2;
            b[9]=temp;
            a[indx('N')]-=temp;
            a[indx('I')]-=temp;
            a[indx('N')]-=temp;
            a[indx('E')]-=temp;

        }
        //for(int i=0;i<26;i++)
          //  printf("%d ",a[i]);
            //nl;
        printf("Case #%d: ",++cases);
        for(int i=0;i<10;i++)
            for(int j=0;j<b[i];j++)
            printf("%d",i);
            nl;


    }

    return 0;
}
