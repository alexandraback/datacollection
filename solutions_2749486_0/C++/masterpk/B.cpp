#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<sstream>
#include<bitset>
#include<deque>
#include<utility>
#include<cstdlib>
#include<iomanip>
#include<cctype>
#include<climits>
#include<iostream>
using namespace std;
#define ll             long long
#define ull            unsigned long long
string tostr(long long x) { stringstream ss; ss << x; return ss.str(); }
long long toint(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

int main()
{
freopen("B-small-attempt1.in","r",stdin);
freopen("output.txt","w",stdout);
int test;
cin>>test;
for(int tt=1;tt<=test;tt++)
{
    int x,y,x1,y1;
    cin>>x>>y;
    string s;
    int q;
    if(x>=0&&y>=0)
    q=1;
    else if(x>=0&&y<=0)
    q=4;
    else if(x<=0&&y>=0)
    q=2;
    else if(x<=0&&y<=0)
    q=3;
    if(q==1)
    {
        int t=0,st=1;
        int f1=0,f2=0,cu=0;
        while(!f1)
        {
            if(cu==x)
            {
                f1=1;
                break;
            }
            if(st%2==0)
            {
                s.push_back('E');
                cu=cu+st;
            }
            else
            {
                s.push_back('W');
                cu=cu-st;
            }
            st++;
        }
        cu=0;
        while(!f2)
        {
            if(cu==y)
            {
                f1=1;
                break;
            }
            if(st%2==0)
            {
                s.push_back('N');
                cu=cu+st;
            }
            else
            {
                s.push_back('S');
                cu=cu-st;
            }
            st++;
        }

    }
    if(q==2)
    {
        int t=0,st=1;
        int f1=0,f2=0,cu=0;
        while(!f1)
        {
            if(cu==x)
            {
                f1=1;
                break;
            }
            if(st%2==1)
            {
                s.push_back('E');
                cu=cu+st;
            }
            else
            {
                s.push_back('W');
                cu=cu-st;
            }
            st++;
        }
        cu=0;
        while(!f2)
        {
            if(cu==y)
            {
                f1=1;
                break;
            }
            if(st%2==0)
            {
                s.push_back('N');
                cu=cu+st;
            }
            else
            {
                s.push_back('S');
                cu=cu-st;
            }
            st++;
        }

    }
    if(q==3)
    {
        int t=0,st=1;
        int f1=0,f2=0,cu=0;
        while(!f1)
        {
            if(cu==x)
            {
                f1=1;
                break;
            }
            if(st%2==1)
            {
                s.push_back('E');
                cu=cu+st;
            }
            else
            {
                s.push_back('W');
                cu=cu-st;
            }
            st++;
        }
        cu=0;
        while(!f2)
        {
            if(cu==y)
            {
                f1=1;
                break;
            }
            if(st%2==1)
            {
                s.push_back('N');
                cu=cu+st;
            }
            else
            {
                s.push_back('S');
                cu=cu-st;
            }
            st++;
        }

    }
    if(q==4)
    {
        int t=0,st=1;
        int f1=0,f2=0,cu=0;
        while(!f1)
        {
            if(cu==x)
            {
                f1=1;
                break;
            }
            if(st%2==0)
            {
                s.push_back('E');
                cu=cu+st;
            }
            else
            {
                s.push_back('W');
                cu=cu-st;
            }
            st++;
        }
        cu=0;
        while(!f2)
        {
            if(cu==y)
            {
                f1=1;
                break;
            }
            if(st%2==1)
            {
                s.push_back('N');
                cu=cu+st;
            }
            else
            {
                s.push_back('S');
                cu=cu-st;
            }
            st++;
        }

    }
cout<<"Case #"<<tt<<": "<<s<<endl;
s.clear();
}
return 0;
}
