#include<iostream>
#include<stdio.h>
using namespace std;
char key[10];
int t,k,l,s;
char p[10],match[10];
int expect,maxx;
long long total;
void select(int start)
{
    int i,j;
    if(start==s)
    {
        int count=0;
        //for(i=0;i<s;i++) cout<<p[i];cout<<endl;
        for(i=0;i<=s-l;i++)
        {
            bool eq=1;
            for(j=i;j<i+l;j++)
            {
                if(p[j]!=match[j-i]) {eq=0;break;}
            }
            if(eq) count++;
        }
        //cout<<count<<endl;
        if(count>maxx) maxx=count;
        expect+=count;
        total++;
    }
    else
    {
        for(i=0;i<k;i++)
        {
            p[start]=key[i];
            select(start+1);
        }
    }
}

int main()
{
    int i,j;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>k>>l>>s;
        for(j=0;j<k;j++) cin>>key[j];
        for(j=0;j<l;j++) cin>>match[j];
        //for(j=0;j<l;j++) cout<<match[j];cout<<endl;
        expect=0;
        maxx=0;
        total=0;
        select(0);
        double ans;
        if(maxx==0) ans=0.0;
        else ans=(double)maxx-((double)expect/(double)total);
        //cout<<total<<' '<<maxx<<' '<<expect<<endl;
        printf("Case #%d: %0.8f\n",i,ans);
    }
}