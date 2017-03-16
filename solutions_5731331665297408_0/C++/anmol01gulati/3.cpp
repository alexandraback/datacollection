#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdlib>
#include<sstream>
#include<string.h>
#include<set>
#include<map>
#include<assert.h>
#include<fstream>
#include<ctime>
#include<queue>
#include<vector>
#include<stack>
#include<list>
#include<math.h>

using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long int lli;
typedef unsigned long long ull;

#define MAXN 55
#define INF 2147483647
#define MOD 1000000007
#define pb push_back 
#define sz(a) int((a).size())
#define var(a,b)  __typeof(b) a = b
#define FOR(x,a,b) for(int (x) = (a);(x)<=(b);(x)++)
#define rep(x,n)   for(int (x)=0;(x)<(n);(x)++)
#define tr(c,it)  for(var(it,(c).begin());it!=(c).end();++it)
#define all(c) c.begin(),c.end()
#define mset(a,b) memset(a,b,sizeof(a)) 
#define MAX(a, b) (a) > (b) ? (a) : (b)

string postal[MAXN];
bool G[MAXN][MAXN];
vi per;
bool chk()
{
	int n = per.size();
	
	
	int v;
	int u = per[0];
	 stack<int> st;
	 st.push(u);

	FOR(i,1,n-1)
	{
		v = per[i];
		while(G[st.top()][v]!=true )
		{
			st.pop();
			if(st.size()==0)
				break;
		}
		if(st.size()==0)
			return false;
		else
			st.push(v);
	}
	return true;
}
string find_sum(int n)
{
	string ans = "";
	rep(i,n)
	ans+=postal[per[i]];
	return ans;
}
int main()
{
	int n,t,x,y,m;
	string temp;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
	scanf("%d",&t);
	rep(q,t)
	{
		per.clear();
		scanf("%d%d",&n,&m);
		rep(i,n)
		rep(j,n)
		G[i][j] = false;
		rep(i,n)
		cin>>postal[i];
		
		rep(i,m)
		{
			scanf("%d%d",&x,&y);
			x--;y--;
			G[x][y] = true;
			G[y][x] = true;
		}
		rep(i,n)
		per.pb(i);
		sort(all(per));
		string ans = "";
		do
		{
			if(chk())
				{
					temp = find_sum(n);
					if(ans=="")
						ans = temp;
					else if( ans > temp)
						ans = temp;
				}
		}while(next_permutation(all(per)));

		// rep(i,n)
		// adl[i].clear();

		cout<<"Case #"<<q+1<<": "<<ans<<"\n";
	}



	return 0;
}
