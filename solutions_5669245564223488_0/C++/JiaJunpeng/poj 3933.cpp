#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
int mod=1000000007;
bool sp;
struct block
{
       int len,num;
};
block bl[111],now;
int num_bl;
long long a[2],d;
char str[1101][1101];
int ans,gen,n,num[4][27],dp[111][27],pos[4][27];
bool vis[27];
long long gcd(long long a,long long b)
{
     long long temp;
     while(b!=0)
     {
        temp=a%b;
        a=b;
        b=temp;
     }
     return a;
}
int main()
{
    int cc,len,t,i,j,s,p,q,tst=0,id,ip;
     freopen("debug\\input.txt","r",stdin);
    freopen("debug\\output.txt","w",stdout);
    scanf("%d",&t);
   // getchar();
    while(t--)
    {
        tst++;
        scanf("%d",&n);
        for(i=0;i<n;i++)
           scanf("%s",str[i]);
        memset(num,0,sizeof(num));
        sp=false;
        for(i=0;i<n;i++)
        {
            len=strlen(str[i]);
            for(j=1;j<len;j++)
            {
                 if(str[i][j]!=str[i][0])
                     break;
            }
            if(j>=len)
                 num[2][str[i][0]-'a']++;
            else
            {
                num[0][str[i][0]-'a']++;
                pos[0][str[i][0]-'a']=i;
                num[1][str[i][len-1]-'a']++;
                pos[1][str[i][len-1]-'a']=i;
                for(s=len-2;s>=0;s--)
                {
                   if(str[i][s]!=str[i][len-1])
                       break;
                }
                for(p=j;p<=s;p++)
                {
                   if(p==j||str[i][p]!=str[i][p-1])
                    num[3][str[i][p]-'a']++;
                }
            }
        }
        printf("Case #%d: ",tst);
        if(sp)
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<26;i++)
        {
            if(num[3][i]>0&&num[0][i]+num[1][i]+num[2][i]>0)
                break;
            if(num[0][i]>1||num[1][i]>1||num[3][i]>1)
                break;
        }
        if(i<26)
           printf("0\n");
        else
        {
            num_bl=0;
            int st=0;
            bool no=false;
            memset(vis,false,sizeof(vis));
            ans=1;
            while(true)
            {
                int over=0,id=-1;
                for(i=0;i<26;i++)
                {
                    if((num[0][i]>0||num[2][i]>0)&&num[1][i]==0)
                    {
                       over|=1;
                       id=i;
                    }
                    if((num[1][i]>0||num[2][i]>0)&&num[0][i]==0)
                       over|=2;
                }
                if(over!=0&&over!=3)
                {
                    no=true;
                    break;
                }
                if(id<0) 
                   break;
              //  printf("id=%d\n",id);
              //  if(num[0][id]>0)
               // {
                 //  num[0][id]=0;
                  // id=pos[0][id];
                   now.len=0;
                   now.num=1;
                   while(true)
                   {
                      if(num[2][id]>0)
                      {
                         // printf("num[2][%d]=%d\n",id,num[2][id]);
                          for(j=1;j<=num[2][id];j++)
                              ans=(int)((long long)ans*(long long)j%mod);//now.num=(int)((long long)now.num*(long long)j%mod);
                          num[2][id]=0;
                      }
                    //  printf("id=%d\n",id);
                      if(num[0][id]>0)
                      {
                          num[0][id]=0;
                          ip=pos[0][id];
                          len=strlen(str[ip]);
                          id=str[ip][len-1]-'a';
                          num[1][id]=0;
                      }
                      else
                          break;
                   }
                   num_bl++;
            }
            if(no)
              printf("0\n");
            else
            {
                for(i=1;i<=num_bl;i++)
                   ans=(int)((long long)ans*(long long)i%mod);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
/*
9
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww 

aaaaaaaaaaaaaaaaaaaaooooooooooooooooooooooooooooooooogggggggggggggggggggggssssssss

ssssssssssssssss 

rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr

rr kkkkkkkfffzzzzzzzvvvvvvvv 

kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk

kkkkkkkkkkk 

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh

hh vvvvvmmmmmmmmmmdddddddqqqqqqqtttttttjjjjjjjjjyyyxxxxxxxxxxx 

lllllllllllllllllllllllllluuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuupppppppppppppppppppppppp

pp 

hhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiccccccccccccccccccceeeeeeeeeennnnnnnnnnnnbbbbbbbbb

llllllllllll

6
iiiiiiibbbbbbb nnnnnnjjjhhhhhddddd sssssssss ssssssmmmmmmiiiiiiii vvo 
uukkeeggffwwyycclllr

9
dddddddddddddddddddddddddddddddddddddddd dddddddddd ddddddddddddddddddddddddddddddddddddddddd dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd ggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq iiiiiirrrssssssxxyyyyyyzzzzuuuffffoooooovvvvcceeeppppppbbbbbbnnnaaakkkkkkkjjllllwwwwhhhmmmmm dddddddddddddddddddddddddddddddddddddddddddddddddddd

*/
