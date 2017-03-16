#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char str1[22];
char str2[22];
int n;
int getlen(long long x)
{
    if(x==0)
        return 1;
    int ans=0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
}
void check(long long &s1,long long &s2)
{
    s1=0;
    s2=0;
    int flag=0;
    for(int i=0; i<n; i++)
    {
        if(flag==0)
        {
            if(str1[i]=='?'&&str2[i]=='?')
            {
                s1*=10;
                s2*=10;
            }
            else if(str1[i]=='?')
            {
                s1=s1*10+str2[i]-'0';
                s2=s2*10+str2[i]-'0';
            }
            else if(str2[i]=='?')
            {
                s1=s1*10+str1[i]-'0';
                s2=s2*10+str1[i]-'0';
            }
            else
            {
                if(str2[i]>str1[i])
                    flag=-1;
                else if(str2[i]<str1[i])
                    flag=1;
                s1=s1*10+str1[i]-'0';
                s2=s2*10+str2[i]-'0';
            }
        }
        else if(flag==1)
        {
            if(str1[i]=='?')
            {
                s1=s1*10;
            }
            else
                s1=s1*10+str1[i]-'0';
            if(str2[i]=='?')
            {
                s2=s2*10+9;
            }
            else
                s2=s2*10+str2[i]-'0';
        }
        else if(flag==-1)
        {
            if(str1[i]=='?')
            {
                s1=s1*10+9;
            }
            else
                s1=s1*10+str1[i]-'0';
            if(str2[i]=='?')
            {
                s2=s2*10;
            }
            else
                s2=s2*10+str2[i]-'0';
        }
    }
}
int main()
{
//    freopen("B-small-attempt1.in","r",stdin);
//    freopen("B-small-attemptx.out","w",stdout);
    freopen("B-large.in","r",stdin);
    freopen("B-large1.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%s%s",str1,str2);
        printf("%s %s\n",str1,str2);
        n=strlen(str1);
        int pos=-1;
        int flag=0;
        for(int i=0; i<n; i++)
        {
            if(str1[i]!='?'&&str2[i]!='?'&&str1[i]!=str2[i])
            {
                pos=i;
                if(str1[i]>str2[i])
                    flag=1;
                else
                    flag=-1;
                if(flag!=0)
                    break;
            }
        }
//        printf("%d\n",flag);
        printf("Case #%d: ",cas);
        if(flag==0)
        {
            for(int i=0; i<n; i++)
            {
                if(str1[i]=='?'&&str2[i]=='?')
                {
                    str1[i]='0';
                    str2[i]='0';
                }
                else if(str1[i]=='?')
                    str1[i]=str2[i];
                else
                    str2[i]=str1[i];
            }
            printf("%s %s\n",str1,str2);
        }
        else if(flag==1)
        {
            long long v1,v2;
            check(v1,v2);
            for(int i=pos-1; i>=0; i--)
            {
                if(str1[i]!='?'&&str2[i]!='?')
                    continue;
                if(str1[i]=='?'&&str2[i]=='?')
                {
                    long long sum1,sum2;
                    str1[i]='0';
                    str2[i]='0';
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]='0';
                    str2[i]='1';
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]='?';
                    str2[i]='?';
//                    break;
                }
                if(str1[i]=='?'&&str2[i]!='0')
                {
                    char ch=str2[i];
                    str1[i]=str2[i];
                    long long sum1,sum2;
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]=str2[i]-1;
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]='?';
                    str2[i]=ch;
//                    break;
                }
                if(str1[i]!='9'&&str2[i]=='?')
                {
                    char ch=str1[i];
                    long long sum1,sum2;
                    str2[i]=str1[i];
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str2[i]=str1[i]+1;
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]=ch;
                    str2[i]='?';
//                    break;
                }
            }
//            printf("%I64d %I64d\n",v1,v2);
            int l1=getlen(v1);
            int l2=getlen(v2);
            for(int i=0; i<n-l1; i++)printf("0");
            printf("%I64d ",v1);
            for(int i=0; i<n-l2; i++)printf("0");
            printf("%I64d\n",v2);
        }
        else if(flag==-1)
        {
            long long v1,v2;
            check(v1,v2);
            for(int i=pos-1; i>=0; i--)
            {
                if(str1[i]!='?'&&str2[i]!='?')
                    continue;
                if(str1[i]=='?'&&str2[i]=='?')
                {
                    long long sum1,sum2;
                    str1[i]='0';
                    str2[i]='0';
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]='1';
                    str2[i]='0';
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]='?';
                    str2[i]='?';
//                    break;
                }
                if(str1[i]=='?'&&str2[i]!='9')
                {
                    char ch=str2[i];
                    str1[i]=str2[i];
                    long long sum1,sum2;
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]=str2[i]+1;
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]='?';
                    str2[i]=ch;
//                    break;
                }
                if(str1[i]!='0'&&str2[i]=='?')
                {
                    char ch=str1[i];
                    long long sum1,sum2;
                    str2[i]=str1[i];
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str2[i]=str1[i]-1;
                    check(sum1,sum2);
                    if(abs(sum1-sum2)<abs(v1-v2)||(abs(sum1-sum2)==abs(v1-v2)&&sum1<v1)||(abs(sum1-sum2)==abs(v1-v2)&&sum1==v1&&sum2<v2))
                    {
                        v1=sum1;
                        v2=sum2;
                    }
                    str1[i]=ch;
                    str2[i]='?';
//                    break;
                }
            }
//            printf("%I64d %I64d\n",v1,v2);
            int l1=getlen(v1);
            int l2=getlen(v2);
            for(int i=0; i<n-l1; i++)printf("0");
            printf("%I64d ",v1);
            for(int i=0; i<n-l2; i++)printf("0");
            printf("%I64d\n",v2);
        }
    }
    return 0;
}
