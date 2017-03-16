
//Michał Glapa
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdlib>
#include<time.h>
#include<stack>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
#define ret return
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
#define pii  pair<int, int>
#define vi vector<int >
#define pb push_back
#define mp make_pair
#define make(n) int n; scanf("%d",&n)
#define st first
#define nd second
#define INF 2000000001
#define VAR(i,n) __typeof(n) i = (n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define FORDEACH(i,c) for( VAR(i,(c).rbegin(),i!=(c).rend();i++)
#define REP(i,n) FOR(i,0,n)
#define ld long double
const long long INFLL = (ll)INF * (ll)INF;
const ld EPS = 10e-9;

#define MAXN
#define WTF -1234

int main()
{
    make(t);
    FOR(w,1,t+1)
    {
        make(n);
        vector<pii > p;
        int res=0;
        int stars=0;
        int warn=0;
        int size=n;
        FOR(i,0,n)
        {
            make(a);
            make(b);
            p.pb(mp(a,b));
        }
        while(!warn && size>0)
        {
            vector< pii > q;
            int num=0;
            FOR(i,0,(int)p.size())
            {
                if(p[i].st!=WTF && stars >=p[i].nd)
                {
                    num+=2;
                    res++;
                    size--;
                }
                else
                {
                    if(p[i].st==WTF && stars >=p[i].nd)
                    {
                        num++; res++;
                        size--;
                    }
                    else
                        q.pb(p[i]);
                }
            }
            if(num>0)
            {
                stars+=num;
            }
            else
            {
                int best = -1,bestwsk=-1;
                FOR(i,0,(int)q.size())
                {
                    if(q[i].st!=WTF && stars >= q[i].st && best < q[i].nd)
                    {
                        best = q[i].nd;
                        bestwsk=i;
                    }
                }
                if(best!=-1)
                {
                    swap(q[bestwsk],q.back());
                    pii x = q.back();
                    q.pop_back();
                    q.pb(mp(WTF,x.nd));
                    stars++;
                    res++;
                }
                else
                    warn=1;
            }
            
            swap(p,q);

        }
        if(warn)
            printf("Case #%d: Too Bad\n",w);
        else
            printf("Case #%d: %d\n",w,res);

    }
}

