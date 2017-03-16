#include<stdio.h>
#include<iostream>

using namespace std;

int t,k,l,s;
double ans,maxim;
char st[105],fi[105];
char temp[105];
char co[26];

int fun(int pos)
{
    if(pos == s)
    {
        //printf("Hello");
        int no = 0;
        double val = 0;
        for(int i=0;i<s-l+1;i++)
        {
            int fl=1;
            for(int j=i;j<i+l;j++)
            {
                //printf("%d %d\n",j,j-i);
                //printf("%c %c\n",temp[j],fi[j-i]);
                if(temp[j] != fi[j-i])
                {
                    fl=0;
                    break;
                }
            }
            if(fl)
            {
                //printf("Hi");
                no++;
            }

        }
        val = no;
        if(maxim < no)
            maxim = no;
        for(int i=0;i<s;i++)
        {
            val *= co[temp[i]-'A'];
            val /= k;
        }
        ans += val;
        return 0;
    }

    for(int i=0;i<26;i++)
    {
        char te;
        if(co[i]>0)
        {
            te = (char)(i+'A');
            temp[pos] = te;
            //printf("%c\n",temp[pos]);
            fun(pos+1);
        }
    }
    return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for(int ci=1;ci<=t;ci++)
    {
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s",&st);
        scanf("%s",&fi);
        ans=0;
        maxim=0;
        for(int i=0;i<26;i++)
        {
            co[i]=0;
        }
        for(int i=0;i<k;i++)
        {
            co[st[i]-'A']++;
        }
        fun(0);
        ans = maxim - ans;
        printf("Case #%d: %.7f\n",ci,ans);
    }
    return 0;
}
