#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

#define mx 10000000
#define ip freopen("a.txt","r",stdin)
#define op freopen("out.txt","w",stdout)

#define sint1(a) scanf("%d",&a)
#define sint2(a,b) scanf("%d %d",&a,&b)
#define sint3(a,b,c) scanf("%d %d %d",&a,&b,&c)


#define sch1(a) scanf("%c",&a)
#define sch2(a,b) scanf("%c %c",&a,&b)
#define sch3(a,b,c) scanf("%c %c %c",&a,&b,&c)


#define sll1(a) scanf("%lld",&a)
#define sll2(a,b) scanf("%lld %lld",&a,&b)
#define sll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define ll long long int

#define lpi0(a,b) for(int a=0;a<b;a++)
#define lpd0(a,b) for(int a=b-1;a>=0;a--)

#define lpi1(a,b) for(int a=1;a<=b;a++)
#define lpd1(a,b) for(int a=b;a>0;a--)

#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair

#define pi acos(-1)

#define mm(a,b) memset(a,b,sizeof(a))

char a[1200];

void fun(int x,char ch)
{
    for(int i=x;i>=1;i--)
        a[i]=a[i-1];

    a[0]=ch;
}
int main()
{
//    ip;
//    op;
    int t;
    int cs=1;

    sint1(t);
    getchar();
    while(t--)
    {
        char s[1200];


        gets(s);

        int l=strlen(s);

        a[0]=s[0];

        for(int i=1;i<l;i++)
        {
            if(s[i]<a[0])
                a[i]=s[i];
            else
                fun(i,s[i]);
        }

        a[l]=s[l];

        printf("Case #%d: %s\n",cs++,a);
    }


}
