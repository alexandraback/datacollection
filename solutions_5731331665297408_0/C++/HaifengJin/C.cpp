#include <functional>
#include <algorithm>
#include <iostream>
//#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

#define MEM(a) (memset((a),0,sizeof(a)))
#define LEN(a) (int)strlen((a))
#define fr(a) for(int i=0;i<(a);i++)
#define sf(a) scanf("%d",&(a))
#define sf64(a) scanf("%I64d",&(a))
#define sff(a) scanf("%lf",&(a))
#define sfs(a) scanf("%s",(a))
#define sf2(a,b) scanf("%d%d",&(a),&(b))
#define sf2s(a,b) scanf("%s%s",(a),(b));
#define sf2f(a,b) scanf("%lf%lf",&(a),&(b))
#define sf264(a,b) scanf("%I64d%I64d",&(a),&(b))
#define pf(a) printf("%d\n",(a))
#define pfc(a) printf("%c",(a));
#define pf64(a) printf("%I64d\n",(a))
#define pff(a) printf("%lf\n",(a))
#define pfs(a) printf("%s\n",(a))
#define pf2(a,b) printf("%d %d\n",(a),(b))
#define pf2s(a,b) printf("%s%s\n",(a),(b));
#define pf2f(a,b) printf("%lf %lf\n",(a),(b))
#define pf264(a,b) printf("%I64d %I64d\n",(a),(b))
#define pfn printf("\n")
#define LL unsigned long long

const int N=100010;
const int M=1000010;
const int MOD=1000000007;
const int INF=0x7fffffff;
const int dir4[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int dir8[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};
const double eps=1e-16;
const double PI=acos(-1.0);

inline int sign(double x){return (x>eps)-(x<-eps);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
/*************************/


#define vE 4010
#define vN 25
int adj[vN][vN];
string weight[vN];
int enu[vN];
int t, n, m;
int dfs(int cur, int target)
{
	if(target>=n)return -1;
	int rs=target;
	while(rs>=0&&adj[cur][enu[rs]]==1)
		rs=dfs(enu[rs],rs+1);
	return rs;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt", "r", stdin);
//    freopen("testout.txt", "w", stdout);
#endif
	scanf("%d", &t);
	int cas=0;
	while (t--)
	{
		scanf("%d%d", &n,&m);
		for (int i = 1; i <= n; i++)
		{
			cin>>weight[i];
			enu[i-1]=i;
		}
		memset(adj,0,sizeof(adj));
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			adj[x][y] = 1;
			adj[y][x]=1;
		}
		string s;
		do
		{
			int temp=dfs(enu[0],1);
			if(temp==-1)
			{
				string tems="";
				for(int i=0;i<n;i++)
					tems.append(weight[enu[i]]);
				if(s==""||s>tems)
					s=tems;
			}
		}while (next_permutation(enu,enu+n));
		printf("Case #%d: ", ++cas);
		cout<<s<<endl;
	}
    return 0;
}
