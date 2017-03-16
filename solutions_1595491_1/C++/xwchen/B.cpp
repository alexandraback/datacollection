#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cstring>
#include <string>
#include <numeric>
#include <functional>
#include <iomanip>
#include <ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;



int not_suprise_get_best(int x)
{
    return (x+2)/3;
}
int suprise_get_best(int x)
{
    return (x+1)/3+1;
}
bool can_be_suprise(int x)
{
    return x%3!=1&&x>=2&&x<=27;
}
struct NODE
{
    int best;
    int tot;
    bool can;
    NODE(int b,int t,bool c):best(b),tot(t),can(c){}
};
vector<NODE> nd;
bool cmp(NODE a,NODE b)
{
    if(a.best!=b.best)return a.best<b.best;
    return a.can>b.can;
}
int main()
{
    int T;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&T);
    for(int _t=1;_t<=T;_t++)
    {
        int N,S,p,a;
        nd.clear();
        scanf("%d%d%d",&N,&S,&p);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a);
            bool c=can_be_suprise(a);
            int b=not_suprise_get_best(a);
            nd.push_back(NODE(b,a,c));
        }
        for(int i=0;i<(int)nd.size();i++)
        {
            if(nd[i].best<p-1)
            {
                nd.erase(nd.begin()+i);
                i--;
            }
            else if(nd[i].best==p-1&&!nd[i].can)
            {
                nd.erase(nd.begin()+i);
                i--;
            }
        }
        //sort(nd.begin(),nd.end(),cmp);
        int tt=0;
        for(int i=0;i<(int)nd.size();i++)
        {
            if(nd[i].best==p-1)tt++;
        }
        int n=nd.size();
        int res=n+min(S-tt,0);

        printf("Case #%d: %d\n",_t,res);
    }
	return 0;
}
