#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cctype>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<map>
#include<set>
#define pi (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("Bout.txt","w",stdout);
	int t,T,i,j,val,n,m,row,col,a[105][105];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    set<Pii > mp[105];
	    set<int> r[105],c[105];
	    set<int>::iterator it;
	    scanf("%d%d",&n,&m);
	    rep(i,n)
            rep(j,m)
            {
                scanf("%d",&val);
                mp[val].insert(Pii(i,j));
                r[i].insert(j);
                c[j].insert(i);
                a[i][j]=val;
            }
        rep(i,105)
        {
            while(Size(mp[i]))
            {
                row=mp[i].begin()->first;
                col=mp[i].begin()->second;
                for(it=r[row].begin();it!=r[row].end();it++)
                    if(a[row][*it]!=i)
                        break;
                if(it==r[row].end())
                {
                    for(it=r[row].begin();it!=r[row].end();it++)
                    {
                        c[*it].erase(row);
                        mp[i].erase(Pii(row,*it));
                    }
                    r[row].clear();
                    continue;
                }
                for(it=c[col].begin();it!=c[col].end();it++)
                    if(a[*it][col]!=i)
                        break;
                if(it==c[col].end())
                {
                    for(it=c[col].begin();it!=c[col].end();it++)
                    {
                        r[*it].erase(col);
                        mp[i].erase(Pii(*it,col));
                    }
                    c[col].clear();
                    continue;
                }
                break;
            }
            if(Size(mp[i]))
                break;
        }
        if(i==105)
            printf("Case #%d: YES\n",t);
        else
            printf("Case #%d: NO\n",t);
	}
	return 0;
}

