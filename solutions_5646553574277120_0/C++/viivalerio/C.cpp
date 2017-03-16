#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<limits.h>
#include<iomanip>
#include<cmath>
#include<cassert>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<vector>
#include<sstream>
#include<bitset>

using namespace std;

#define INF 0x7fffffff

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef priority_queue<ii> pqii;
typedef priority_queue<iii> pqiii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef queue<ii> qii;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ull, ull> pull;
typedef pair<ll,ll> pll;

si rds;

si Solve(si d, int v, int number, int sum)
{


    for(si::iterator i = d.begin(); i!=d.end(); i++ )
    {
       if(*i>number)
       {
           if(sum+*i<=v)
           {
               //printf("%d\n",sum+*i);
               rds = Solve(d, v, *i, sum+*i);
               rds.insert(sum+*i);
           }

       }
    }

    return rds;
}

int main()
{
    int cases = 1;
    int T;
    int c,d,v;
    int di;

    while(scanf("%d", &T)!= EOF)
    {
        while(T--)
        {
            scanf("%d %d %d", &c, &d, &v);

            si sd;
            for(int i=0; i<d; i++)
            {
                scanf("%d", &di);
                sd.insert(di);
            }

            int cnt = 0;
            bool ok = false;
            while(!ok)
            {
                rds.clear();
                Solve(sd, v, 0, 0);

                /*for(si::iterator it = rds.begin(); it!=rds.end(); it++)
                {
                    printf("%d ", *it);
                }*/

                //system("Pause");

                ok = true;
                for(int i=1; i<=v; i++)
                {
                    if(rds.find(i)==rds.end())
                    {
                        cnt++;
                        sd.insert(i);
                        ok = false;
                        break;
                    }
                }


            }

            printf("Case #%d: ", cases++);
            printf("%d\n", cnt);
        }

    }

    return 0;
}


