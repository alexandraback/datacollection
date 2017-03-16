/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
int A[105];
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    int kas = 0;
    while(t--)
    {
    	kas++;
    	int c,d,v;
        cin >> c >> d >> v;
        FOR(i,d)
        scanf("%d",&A[i]);
        set<int> S;
        S.insert(0);
        for(int i=0;i<d;i++)
        {
            std::vector<int> G;
            for(set<int>::iterator it = S.begin(); it != S.end();it++)
            {
                G.pb(*it + A[i]);
            }
            FOR(k,G.size())
            {
                S.insert(G[k]);
            }
        }
        //for(set<int>::iterator it = S.begin(); it != S.end();it++)
            //cout << *it << " ";
       // cout << endl;
        int ans = 0;
        for(int i=1;i<=v;i++)
        {
            if(S.find(i) == S.end())
            {
                ans++;
                std::vector<int> G;
                for(set<int>::iterator it = S.begin(); it != S.end();it++)
                {
                    G.pb(*it + i);
                }
                FOR(k,G.size())
                {
                    S.insert(G[k]);
                }
            }
        }
        printf("Case #%d: %d\n",kas,ans);
    }
return 0;
}
