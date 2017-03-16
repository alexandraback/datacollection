#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include <cstdlib>
#include<climits>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

#define IOR(x) freopen(x,"r",stdin);
#define IOW(x) freopen(x,"w",stdout);
#define DEBUG if(1)

#define i64 long long
#define u64 unsigned long long
#define eps 1e-10

#define REPI(i,a,b) for(i=a;i<=b;++i)
#define REPD(i,a,b) for(i=a;i>=b;--i)

#define pb(p) push_back(p)
#define ms(p,v) memset(p,v,sizeof(p))
#define pii pair< int, int >
#define mp(a,b) make_pair(a,b)
#define clr(a) a.clear();
#define ff first
#define sd second
int main()
{
    DEBUG IOR("i1.txt");
    DEBUG IOW("o.txt");
    int t,x,y,cases=0,a,c,b,m,i;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>x>>y;
            a=b=c=0;
            m=1;
            printf("Case #%d: ",++cases);
            if(x>0)
            {
                while(a!=x)
                {
                    if((a+m)<=x)
                    {
                        a+=m;
                        ++m;
                        cout<<'E';
                    }
                    else
                    {
                        a-=m;
                        ++m;
                        cout<<'W';
                    }
                }
            }
            else
            {
                while(a!=x)
                {
                    if((a-m)>=x)
                    {
                        a-=m;
                        ++m;
                        cout<<'W';
                    }
                    else
                    {
                        a+=m;
                        ++m;
                        cout<<'E';
                    }
                }
            }
            if(y>0)
            {
                while(b!=y)
                {
                    if((b+m)<=y)
                    {
                        b+=m;
                        ++m;
                        cout<<'N';
                    }
                    else
                    {
                        b-=m;
                        ++m;
                        cout<<'S';
                    }
                }
            }
            else
            {
                while(b!=y)
                {
                    if((b-m)>=y)
                    {
                        b-=m;
                        ++m;
                        cout<<'S';
                    }
                    else
                    {
                        b+=m;
                        ++m;
                        cout<<'N';
                    }
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
