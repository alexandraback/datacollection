/* Created by Anmol Varshney */

#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define INF 2000000000
#define INF_LL 9223372036854775807LL
#define PI acos(-1.0)
#define llu long long unsigned
#define ll long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define mod 1000000007
#define getchar_unlocked getchar
#define pb(f) push_back(f)
#define pob(f) pop_back(f)
#define pf(f) push_front(f)
#define pof(f) pop_front(f)
#define mkp(a,b) make_pair(a,b)
#define fst first
#define snd second
#define pii pair<int,int>
#define ins(a) insert(a)

int gcd(int a,int b)
{
    if(b>a) return gcd(b,a);
    else if(b!=0) return (b,a%b);
    else return a;
}

vector<int> ans;
int vis[2501];

int main() {
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    for(int l=1;l<=t;l++)
    {
        ans.clear();
        memset(vis,0,sizeof(vis));
        cin>>n;
        REP(i,1,2*n)
        {
            REP(j,0,n)
            {
                cin>>x;
                vis[x]++;
            }
        }
        REP(i,1,2501)
        {
            if(vis[i]&1)
                ans.pb(i);
        }
        cout<<"Case #"<<l<<": ";
        REP(i,0,ans.size())
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
