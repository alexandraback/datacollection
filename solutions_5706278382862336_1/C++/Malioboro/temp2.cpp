#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;
#define ot(x) cout<<x<<endl
#define cen cout<<endl
#define EPS 1e-10
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> AdjList;
priority_queue< pair<int, ii> > Edgelist;
ll n,m,t,i,j,k;
bool flag=false;



int main()
{
    int tc,cc=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld/%lld",&n,&m);
        t=0;int res=0;
        while(n<m){
            n*=2;
            t++;
        }
        res=t;n-=m;
        while(t<40 && n){
            while(n<m){
                n*=2;
                t++;
            }
            n-=m;
        }
        if(n)
            printf("Case #%d: impossible\n",cc,res);
        else
            printf("Case #%d: %d\n",cc,res);
        cc++;
    }
}

/*
1000 2 3 3
1 2 7
2
1 3
500 400
*/
