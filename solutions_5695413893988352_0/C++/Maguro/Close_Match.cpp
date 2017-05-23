#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char a[22],b[22];
char A[22],B[22];
long long len,Min;
pair<string,string> mn;
void dfs(long long idx,long long state)///0: inside, 1:first low, 2: second low
{
    if(idx>=len)
    {
        long long i,j;
        long long x=0,y=0;
        for(i=0;i<len;i++)
        {
            x*=10;x+=A[i]-'0';
            y*=10;y+=B[i]-'0';
        }
//        printf("%lld %lld\n",x,y);
        pair<string,string> p;
        for(i=0;i<len;i++)
        {
            p.X.push_back(A[i]);
            p.Y.push_back(B[i]);
        }
        if(Min==abs(x-y))
        {
            if(p<mn)
            {
                mn=p;
            }
        }
        else if(abs(x-y)<Min)
        {
            Min=abs(x-y);
            mn=p;
        }
        return;
    }
    if(state==0)
    {
        if(a[idx]=='?'&&b[idx]=='?')
        {
            A[idx]='0';B[idx]='0';
            dfs(idx+1,0);
            A[idx]='0';B[idx]='1';
            dfs(idx+1,2);
            A[idx]='1';B[idx]='0';
            dfs(idx+1,1);
        }
        else if(a[idx]=='?')
        {
            A[idx]=b[idx];B[idx]=b[idx];
            dfs(idx+1,0);
            if(b[idx]>'0')
            {
                A[idx]=b[idx]-1;
                dfs(idx+1,2);
            }
            if(b[idx]<'9')
            {
                A[idx]=b[idx]+1;
                dfs(idx+1,1);
            }
        }
        else if(b[idx]=='?')
        {
            A[idx]=a[idx];B[idx]=a[idx];
            dfs(idx+1,0);
            if(a[idx]>'0')
            {
                B[idx]=a[idx]-1;
                dfs(idx+1,1);
            }
            if(a[idx]<'9')
            {
                B[idx]=a[idx]+1;
                dfs(idx+1,2);
            }
        }
        else
        {
            A[idx]=a[idx];B[idx]=b[idx];
            if(a[idx]==b[idx])
            {
                dfs(idx+1,0);
            }
            else if(a[idx]>b[idx])
            {
                dfs(idx+1,1);
            }
            else
            {
                dfs(idx+1,2);
            }
        }
    }
    else if(state==1)
    {
        if(a[idx]=='?'&&b[idx]=='?')
        {
            A[idx]='0';B[idx]='9';
            dfs(idx+1,state);
        }
        else if(a[idx]=='?')
        {
            A[idx]='0';B[idx]=b[idx];
            dfs(idx+1,state);
        }
        else if(b[idx]=='?')
        {
            A[idx]=a[idx];B[idx]='9';
            dfs(idx+1,state);
        }
        else
        {
            A[idx]=a[idx];B[idx]=b[idx];
            dfs(idx+1,state);
        }
    }
    else
    {
        if(a[idx]=='?'&&b[idx]=='?')
        {
            A[idx]='9';B[idx]='0';
            dfs(idx+1,state);
        }
        else if(a[idx]=='?')
        {
            A[idx]='9';B[idx]=b[idx];
            dfs(idx+1,state);
        }
        else if(b[idx]=='?')
        {
            A[idx]=a[idx];B[idx]='0';
            dfs(idx+1,state);
        }
        else
        {
            A[idx]=a[idx];B[idx]=b[idx];
            dfs(idx+1,state);
        }
    }
}
int main()
{
    long long t,T,i,j,k;
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(A,0,sizeof A);
        memset(B,0,sizeof B);
        mn.X="1000000000000000000";
        mn.Y="1000000000000000000";
        Min=1000000000000000000;
        scanf("%s %s",a,b);
        len=strlen(a);
        dfs(0,0);
        cout << "Case #" << t << ": " << mn.X << " " << mn.Y << "\n";
    }
}

