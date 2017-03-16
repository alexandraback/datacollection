#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
#define co complex<double>

#define MAX 100005
#define AMAX 1500
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int t,n,i,y[1005][2],ans,xx[MAX];
char x[25];
bool q[MAX];
vector<int> z[MAX];
vector<char> v;
map<vector<char>,int> ma,mb;

bool dfs(int a){
	F1(b,0,z[a].size())if(!q[z[a][b]]){
		q[z[a][b]]=1;
		if(xx[z[a][b]]==-1||dfs(xx[z[a][b]])){
			xx[z[a][b]]=a;
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d",&t);
	F2(a,1,t){
		scanf("%d",&n);
		ma.clear(),mb.clear();
		ans=0;
		F1(b,0,n){
			i=0;
			v.clear();
			scanf("%s",x);
			while(x[i]){
				v.pb(x[i]);
				x[i++]=0;
			}
			y[b][0]=ma.insert(make_pair(v,ma.size())).first->second;
			i=0;
			v.clear();
			scanf("%s",x);
			while(x[i]){
				v.pb(x[i]);
				x[i++]=0;
			}
			y[b][1]=mb.insert(make_pair(v,mb.size())).first->second;
		}
		F1(b,0,mb.size())z[b].clear();
		F1(b,0,n)z[y[b][1]].pb(y[b][0]);
		F1(b,0,ma.size())xx[b]=-1;
		F1(b,0,mb.size()){
			F1(c,0,ma.size())q[c]=0;
			if(dfs(b))ans++;
		}
		printf("Case #%d: %d\n",a,n-ma.size()-mb.size()+ans);
	}
	//system("pause");
	return 0;
}
