#pragma comment(linker, "/STACK:20000000")
#include <iostream>   
#include <sstream>   
#include <cstdio>   
#include <cstdlib>   
#include <cmath>   
#include <memory>   
#include <cctype>   
#include <string>   
#include <vector>   
#include <list>   
#include <queue>   
#include <deque>   
#include <stack>   
#include <map>   
#include <set>   
#include <algorithm>   
#include <memory.h>
using namespace std;  

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))  
#define INF 1000000000  
#define PB push_back  
#define ALL(c) (c).begin(), (c).end()  
#define pi 2*acos(0.0)  
#define SQR(a) (a)*(a)  
#define MP make_pair  
#define CONST 1000
#define MAX 2300
#define X                       first
#define Y                       second
#define SZ(a)                      ((int)((a)).size())

typedef long long LL; 
typedef long long i64; 
typedef pair<LL,LL>           PII;
typedef vector<LL>             VI;
const LL mod = 1000000007;
const double eps=1e-7;

bool used[4000];
bool us[4000];
vector<int> g[4000];
bool ans=0;

void dfs(int v){
	used[v]=1;
	us[v]=1;
	FOR(i,0,g[v].size()){
		if (!used[g[v][i]])
			dfs(g[v][i]);
		else
			ans=1;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	FOR(tt,1,t+1){
		FOR(i,0,2000)
			g[i].clear();
		ans=0;
		memset(used,0,sizeof(used));
		memset(us,0,sizeof(us));
		int n;
		cin>>n;
		FOR(i,0,n){
			int k;
			cin>>k;
			FOR(j,0,k){
				int x;
				cin>>x;
				x--;
				g[i].push_back(x);
			}
		}
		
		FOR(i,0,n)
			if (!us[i]){
				memset(used,0,sizeof(used));
				dfs(i);
			}
		cout<<"Case #"<<tt<<": ";
		if (ans)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

	}
	return 0;
}
