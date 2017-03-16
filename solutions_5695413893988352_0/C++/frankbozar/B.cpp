#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
typedef long long lld;
const lld INF=0x3FFFFFFFFFFFFFFFLL;
string as, at;

void solve(string s, string t, lld& ans, const int n, int c=0, int i=0)
{
    if( i==n )
    {
        lld l=atoll(s.c_str()), r=atoll(t.c_str()), dif=abs(l-r);
        
        if( dif<ans )
        {
            ans=dif;
            as=s, at=t;
        }
        else if( dif==ans )
        {
            if( l<atoll(as.c_str()) || (l==atoll(as.c_str()) && r<atoll(at.c_str())) )
                as=s, at=t;
        }
    }
    else if( c==1 )
    {
        if( s[i]=='?' )
            s[i]='0';
        
        if( t[i]=='?' )
            t[i]='9';
        
        solve(s, t, ans, n, c, i+1);
    }
    else if( c==-1 )
    {
        if( s[i]=='?' )
            s[i]='9';
        
        if( t[i]=='?' )
            t[i]='0';
        
        solve(s, t, ans, n, c, i+1);
    }
    else//c==0
    {
        string ts=s, tt=t;
        
        if( s[i]=='?' && t[i]=='?' )
        {
            ts[i]=tt[i]='0';
            solve(ts, tt, ans, n, 0, i+1);
            ts[i]='0', tt[i]='1';
            solve(ts, tt, ans, n, -1, i+1);
            ts[i]='1', tt[i]='0';
            solve(ts, tt, ans, n, 1, i+1);
        }
        else if( s[i]=='?' )
        {
            ts[i]=t[i];
            solve(ts, tt, ans, n, 0, i+1);
            
            if( t[i]<'9' )
            {
                ts[i]=t[i]+1;
                solve(ts, tt, ans, n, 1, i+1);
            }
            
            if( t[i]>'0' )
            {
                ts[i]=t[i]-1;
                solve(ts, tt, ans, n, -1, i+1);
            }
        }
        else if( t[i]=='?' )
        {
            tt[i]=s[i];
            solve(ts, tt, ans, n, 0, i+1);
            
            if( s[i]<'9' )
            {
                tt[i]=s[i]+1;
                solve(ts, tt, ans, n, -1, i+1);
            }
            
            if( s[i]>'0' )
            {
                tt[i]=s[i]-1;
                solve(ts, tt, ans, n, 1, i+1);
            }
        }
        else//if( s[i]!='?' && t[i]!='?' )
        {
            if( s[i]>t[i] )
                solve(s, t, ans, n, 1, i+1);
            else if( s[i]<t[i] )
                solve(s, t, ans, n, -1, i+1);
            else
                solve(s, t, ans, n, 0, i+1);
        }
    }
}

int main()
{
    int N;
    cin >> N ;
    
    for(int cases=1; cases<=N; cases++)
    {
        string s, t;
        cin >> s >> t ;
        int n=s.length();
        lld ans=INF;
        solve(s, t, ans, n);
        printf("Case #%d: %s %s\n", cases, as.c_str(), at.c_str());
    }
}