#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <set>
using namespace std;
string c,j;
long long mn=2000000000000000000LL;
long long bb=10;
long long aa=10;
void ty(int x,long long a,long long b)
{
    //printf("VS: %d %lld %lld\n",x,a,b);
    if(a>b)
    {
        for(int i=x;i<c.length();i++)
        {
            a*=10;
            if(c[i]=='?')
                a+=0;
            else
                a+=c[i]-'0';
        }
        for(int i=x;i<j.length();i++)
        {
            b*=10;
            if(j[i]=='?')
                b+=9;
            else
                b+=j[i]-'0';
        }
        if(a-b<mn||(a-b==mn&&a<aa)||(a-b==mn&&a==aa&&b<bb))
        {
            mn=a-b;
            bb=b;
            aa=a;
        }
        return;
    }
    if(b>a)
    {
        for(int i=x;i<c.length();i++)
        {
            a*=10;
            if(c[i]=='?')
                a+=9;
            else
                a+=c[i]-'0';
        }
        for(int i=x;i<j.length();i++)
        {
            b*=10;
            if(j[i]=='?')
                b+=0;
            else
                b+=j[i]-'0';
        }
        if(b-a<mn||(b-a==mn&&a<aa)||(b-a==mn&&a==aa&&b<bb))
        {
            mn=b-a;;
            bb=b;
            aa=a;
            //printf("HI %lld %lld %lld\n",mn,a,b);
        }
        return;
    }
    if(x==c.length())
    {
        if(max(a-b,b-a)<mn||(max(a-b,b-a)==mn&&a<aa)||(max(b-a,a-b)==mn&&a==aa&&b<bb))
        {
            mn=max(a-b,b-a);
            bb=b;
            aa=a;
            //printf("HI %lld %lld %lld\n",mn,a,b);
        }
        return;
    }
    if(c[x]=='?'&&j[x]=='?')
    {
        ty(x+1,a*10,b*10);
        ty(x+1,a*10+1,b*10);
        ty(x+1,a*10,b*10+1);
        return;
    }
    if(c[x]=='?')
    {
        int aj=j[x]-'0';
        ty(x+1,a*10+aj,b*10+aj);
        if(aj+1<=9)
            ty(x+1,a*10+aj+1,b*10+aj);
        if(aj-1>=0)
            ty(x+1,a*10+aj-1,b*10+aj);
        return;
    }
    if(j[x]=='?')
    {
        int ac=c[x]-'0';
        ty(x+1,a*10+ac,b*10+ac);
        if(ac+1<=9)
            ty(x+1,a*10+ac,b*10+ac+1);
        if(ac-1>=0)
            ty(x+1,a*10+ac,b*10+ac-1);
        return;
    }
    ty(x+1,a*10+c[x]-'0',b*10+j[x]-'0');
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        cin>>c>>j;
        mn=2000000000000000000LL;
        bb=0;
        ty(0,0,0);
        vector<int> oa,ob;
        while(aa!=0)
        {
            oa.push_back(aa%10);
            aa/=10;
        }
        while(oa.size()<c.length())
            oa.push_back(0);
        while(bb!=0)
        {
            ob.push_back(bb%10);
            bb/=10;
        }
        while(ob.size()<c.length())
            ob.push_back(0);
        printf("Case #%d: ",tt);
        for(int i=ob.size()-1;i>=0;i--)
            printf("%d",oa[i]);
        printf(" ");
        for(int i=ob.size()-1;i>=0;i--)
            printf("%d",ob[i]);
        printf("\n");
    }
}
