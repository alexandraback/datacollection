#include<bits/stdc++.h>
using namespace std;
char s[20],t[20],s2[20],t2[20];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int tt,i,len,more,nub=1,f,k;
    long long sm1=0,sm2=0,ans1,ans2,mn;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%s%s",s,t);
        len=strlen(s);
        for(i=0;i<len;i++)
            s2[i]=s[i];
        for(i=0;i<len;i++)
            t2[i]=t[i];
        mn=-1;
        for(k=0;k<=len;k++)
        {
            for(i=0;i<len;i++)
                s[i]=s2[i];
            for(i=0;i<len;i++)
                t[i]=t2[i];
            more=-1;
            sm1=0;
            sm2=0;
            for(i=0;i<len;i++)
            {
                if(i==k)
                {
                    if(s[i]=='?'&&t[i]=='?')
                    {
                        s[i]='1';
                        t[i]='0';
                    }
                    else if(s[i]=='?'&&t[i]!='9')
                    {
                        s[i]=t[i]+1;
                    }
                    else if(t[i]=='?'&&s[i]!='0')
                    {
                        t[i]=s[i]-1;
                    }

                }
                if(sm1==sm2)
                {
                    if(s[i]=='?'&&t[i]=='?')
                    {
                        s[i]='0';
                        t[i]='0';
                    }
                    else if(s[i]=='?')
                        s[i]=t[i];
                    else if(t[i]=='?')
                        t[i]=s[i];
                }
                else if(sm1>sm2)
                {
                    if(s[i]=='?')
                        s[i]='0';
                    if(t[i]=='?')
                        t[i]='9';
                }
                else
                {
                    if(s[i]=='?')
                        s[i]='9';
                    if(t[i]=='?')
                        t[i]='0';
                }
                sm1=(sm1*10)+s[i]-'0';
                sm2=(sm2*10)+t[i]-'0';
            }
            if(mn==-1)
            {
                mn=abs(sm1-sm2);
                ans1=sm1;
                ans2=sm2;
            }
            else if(mn==abs(sm1-sm2))
            {
                if(ans1==sm1)
                    ans2=min(ans2,sm2);
                else if(ans1>sm1)
                {
                    ans1=sm1;
                    ans2=sm2;
                }
            }
            else if(mn>abs(sm1-sm2))
            {
                mn=abs(sm1-sm2);
                ans1=sm1;
                ans2=sm2;
            }
        }


        for(k=0;k<len;k++)
        {
            more=-1;
            sm1=0;
            sm2=0;
            for(i=0;i<len;i++)
                s[i]=s2[i];
            for(i=0;i<len;i++)
                t[i]=t2[i];
            for(i=0;i<len;i++)
            {
                if(i==k)
                {
                    if(s[i]=='?'&&t[i]=='?')
                    {
                        s[i]='0';
                        t[i]='1';
                    }
                    else if(t[i]=='?'&&s[i]!='9')
                    {
                        t[i]=s[i]+1;
                    }
                    else if(s[i]=='?'&&t[i]!='0')
                    {
                        s[i]=t[i]-1;
                    }

                }
                if(sm1==sm2)
                {
                    if(s[i]=='?'&&t[i]=='?')
                    {
                        s[i]='0';
                        t[i]='0';
                    }
                    else if(s[i]=='?')
                        s[i]=t[i];
                    else if(t[i]=='?')
                        t[i]=s[i];
                }
                else if(sm1>sm2)
                {
                    if(s[i]=='?')
                        s[i]='0';
                    if(t[i]=='?')
                        t[i]='9';
                }
                else
                {
                    if(s[i]=='?')
                        s[i]='9';
                    if(t[i]=='?')
                        t[i]='0';
                }
                sm1=(sm1*10)+s[i]-'0';
                sm2=(sm2*10)+t[i]-'0';
            }
            if(mn==-1)
            {
                mn=abs(sm1-sm2);
                ans1=sm1;
                ans2=sm2;
            }
            else if(mn==abs(sm1-sm2))
            {
                if(ans1==sm1)
                    ans2=min(ans2,sm2);
                else if(ans1>sm1)
                {
                    ans1=sm1;
                    ans2=sm2;
                }
            }
            else if(mn>abs(sm1-sm2))
            {
                mn=abs(sm1-sm2);
                ans1=sm1;
                ans2=sm2;
            }
        }
        for(i=0;i<len;i++)
        {
            s[i]='0';
            t[i]='0';
        }
        i=len-1;
        while(ans1!=0)
        {
            s[i]=(ans1%10)+'0';
            ans1/=10;
            i--;
        }
        i=len-1;
        while(ans2!=0)
        {
            t[i]=(ans2%10)+'0';
            ans2/=10;
            i--;
        }
        printf("Case #%d: %s %s\n",nub++,s,t);
    }
}
