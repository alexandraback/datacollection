#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAXN 1000010
#define ff first
#define ss second
#define get getchar//_unlocked
inline int inp()
{
    int n=0,s=1;
    char p=get();
    if(p=='-')
    s=-1;
    while((p<'0'||p>'9')&&p!=EOF)
    p=get();
    while(p>='0'&&p<='9')
    {
    n = (n<< 3) + (n<< 1) + (p - '0');
    p=get();
    };
    return n*s;
}
char s[100005];
int main()
{
    int i,n,j,k,l,m,t,c=0,ans,f;
    t=inp();
    for(int p=1;p<=t;p++)
    {
     n=inp();m=inp();f=0,i=0,j=0;
     k=0;
     if(n>0)
     {
         k=0;i=0;j=0;
         while(1)
         {
           if(i%2==0)
           {s[k++]='E';j++;}
           else s[k++]='W';
           if(j==n)
           {
               break;
           }
           i++;
         }
         f=1;
     }

     else if(n<0)
     {
         if(n<0)
         n=-n;
         k=0;i=0;j=0;
         while(1)
         {
           if(i%2==0)
           {s[k++]='W';j++;}
           else s[k++]='E';
           if(j==n)
           {
               break;
           }
           i++;
         }
         f=1;
     }
     //printf("%d\n",i);
     if(m>0)
     {
         int u=0;
         if(f==1){j=i+1;if(n==1&&m==1)j=i;}
         if(f==0)k=0;
          if(m<i+2)
         {
             u=1;j=0;
         }
         while(1)
         {
           if(u%2==0)
           {s[k++]='N';j++;}
           else s[k++]='S';
           u++;
           if(j==m)
           {
               break;
           }
         }
     }
     else if(m<0)
     {
         if(m<0)
         m=-m;
         if(f==0)k=0;
         int u=0;
         if(f==1){j=i+1;if(n==1&&m==1)j=i;}
         if(m<i+2)
         {
             u=1;j=0;
         }
         while(1)
         {
           if(u%2==0)
           {s[k++]='S';j++;}
           else s[k++]='N';
           u++;
           if(j==m)
           {
               break;
           }
         }
     }
     s[k++]='\0';
    // printf("%d\n",strlen(s));
     printf("Case #%d: %s\n",p,s);
    }
    return 0;
}

