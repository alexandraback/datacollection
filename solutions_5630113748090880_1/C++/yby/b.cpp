/* ***********************************************
Author        :yby
Created Time  :2016年04月16日 星期六 09时16分16秒
File Name     :b.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <utility>
using namespace std;
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a) for(int i=0;i<a;i++)
#define REP(i,a) for(int i=1;i<=a;i++)
#define per(i,a,b) for(int i=a-1;i>=b;i--)
#define foreach(i,a) for(int i=head[a];i>=0;i=ee[i].next)
#define Foreach(i,a) for(__typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define m0(x) memset(x,0,sizeof(x))
#define mff(x) memset(x,0xff,sizeof(x))
#define fi first
#define se second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define SZ(x) ((int)(x).size())
#define abs(x) ((x)>0?(x):-(x))
#define sqr(x) ((x)*(x))
#define C1(x) cout<<(x)<<endl
#define C2(x,y) cout<<(x)<<" "<<(y)<<endl
#define C3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< pair<int,int> > VPII;
const ll mod=1e9+7;
const ll maxn=1e5+7;
const ll maxe=1e6+7;
const ll INF=1e9+7;
const double PI=acos(-1);
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int T;
int cou[2505];
VI ans;
int main()
{
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    REP(ca,T)
    {
    	ans.clear();
    	m0(cou);
		int num;
		cin>>num;
		rep(i,num*2-1)
		{
			rep(j,num)
			{
				int a;
				cin>>a;
				cou[a]++;
			}
		}
		REP(i,2500)
		if(cou[i]%2==1)ans.pb(i);
		sort(all(ans));
		printf("Case #%d:",ca);
		rep(i,SZ(ans))printf(" %d",ans[i]);
		printf("\n");

	}
    return 0;
}
