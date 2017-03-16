// This works!!
//Data-structures includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define pb		push_back
#define mp	 	make_pair
#define fill(a,v) 	memset(a, v, sizeof(a))
#define sz		size()
#define all(x)		x.begin(), x.end()
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())
#define FF		first
#define SS		second
#define T(t)            int t;scanf ("%d",&t);while (t--)
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long int LL;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
typedef pair<double,double> pdd;

vector< vector<int> > a(1002);
bool kn[1002];

int flag=0;

void dfs(int s)
{
    kn[s]=true;
    for (int i=0;i<a[s].size();i++)
    {
        if (kn[a[s][i]]==false)
            dfs(a[s][i]);
        else
            flag=1;
    }
    return;
}
int main()
{
    int g=1;
    T(t){
    int n;scanf ("%d",&n);
    int i,j,temp,m;
    for (i=1;i<=n;i++)
    {
        scanf ("%d",&m);
        for (j=0;j<m;j++)
        {
            scanf ("%d",&temp);
            a[i].pb(temp);
        }
    }
    int p=0;
    printf ("Case #%d: ",g++);
    for (i=1;i<=n;i++)
    {
        fill(kn,false);
        flag=0;
        dfs(i);
        if (flag==1)
        {
            printf ("Yes\n");
            p=1;
            break;
        }
    }
    if (p==0) printf ("No\n");
    for (i=1;i<=n;i++) a[i].clear();
    }
    return 0;
}
