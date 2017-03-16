#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int dp[10005];
int func(int x,int y)
{
    int vec[4][4]={
        {1,2,3,4},
        {2,-1,4,-3},
        {3,-4,-1,2},
        {4,3,-2,-1}
    };
    if(x*y>0)
    {
        return vec[x-1][y-1];
    }
    else
    {
        return -vec[abs(x)-1][abs(y)-1];
    }
}
int convert(char ch)
{
    if(ch=='i')
    {
        return 2;
    }
    else if(ch=='j')
    {
        return 3;
    }
    else if(ch=='k')
    {
        return 4;
    }
}
int cal(string str,int start,int end)
{
    int num=convert(str[start]);
    for(int i=start+1;i<end;i++)
    {
        int temp=convert(str[i]);
        num=func(num,temp);
    }
    return num;
}
int divide(int x,int y)
{
    if(x==1)
    {
        if(y==1)
        {
            return 1;
        }
        if(y==-1)
        {
            return -1;
        }
    }
    if(x==2)
    {
        if(y==1)
        {
            return 2;
        }
        if(y==2)
        {
            return 1;
        }
        if(y==3)
        {
            return 4;
        }
        if(y==-1)
        {
            return -2;
        }
        if(y==-2)
        {
            return -1;
        }
        if(y==-3)
        {
            return -4;
        }

    }
    if(x==3)
    {
        if(y==1)
        {
            return 3;
        }
        if(y==3)
        {
            return 1;
        }
        if(y==4)
        {
            return 2;
        }
        if(y==-1)
        {
            return -3;
        }
        if(y==-3)
        {
            return -1;
        }
        if(y==-4)
        {
            return -2;
        }
    }
    if(x==4)
    {
        if(y==1)
        {
            return 4;
        }
        if(y==2)
        {
            return 3;
        }
        if(y==4)
        {
            return 1;
        }
        if(y==-1)
        {
            return -4;
        }
        if(y==-2)
        {
            return -3;
        }
        if(y==-4)
        {
            return -1;
        }
    }
    if(x==-1)
    {
        if(y==2)
        {
            return 2;
        }
        if(y==3)
        {
            return 3;
        }
        if(y==4)
        {
            return 4;
        }
        if(y==-2)
        {
            return -2;
        }
        if(y==-3)
        {
            return -3;
        }
        if(y==-4)
        {
            return -4;
        }
    }
    if(x==-3)
    {
        if(y==2)
        {
            return 4;
        }
        if(y==-2)
        {
            return -4;
        }
    }
    if(x==-4)
    {
        if(y==3)
        {
            return 2;
        }
        if(y==-3)
        {
            return -2;
        }
    }
    if(x==-2)
    {
        if(y==4)
        {
            return 3;
        }
        if(y==-4)
        {
            return -3;
        }
    }
    return 0;
}
void init(string str)
{
    dp[0]=convert(str[0]);
    for(int i=1;i<str.length();i++)
    {
        int temp=convert(str[i]);
        dp[i]=func(dp[i-1],temp);
    }
}
int main()
{
    freopen("C-small-attempt4.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int l;
        int x;
        cin>>l>>x;
        string tempstr;
        cin>>tempstr;
        string str="";
        for(int i=0;i<x;i++)
        {
            str+=tempstr;
        }
        memset(dp,0,sizeof(dp));
        init(str);
        int n=str.length();
        if(n<3)
        {
            cout<<"Case #"<<tt<<": NO"<<endl;
            continue;
        }
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(flag)
            {
                break;
            }
            if(dp[i]!=2)
            {
                continue;
            }
            for(int j=i+1;j<n;j++)
            {
                if(divide(dp[j],dp[i])!=3)
                {
                    continue;
                }
                if(divide(dp[n-1],dp[j])!=4)
                {
                    continue;
                }
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<"Case #"<<tt<<": YES"<<endl;
        }
        else
        {
            cout<<"Case #"<<tt<<": NO"<<endl;
        }
    }
    return 0;
}
