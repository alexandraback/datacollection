#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define bit(k) (1<<(k))
using namespace std;

#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;

const double eps = 1e-8;
const double pi = acos(-1.0);

int sta, n;
int S[10];
string s[10];
int g[10][10];
bool vis[10];
string AIM, now;
int sel;
void go(int u){
	if(sel == n){
		if(now < AIM) AIM = now;
		//cout << AIM << endl;
		return ;
	}
	for(int i=1;i<=n;++i) if(g[u][i] && !vis[i]){
		string last = now;
		now += s[i];
		S[++sta] = i;
		vis[i] = 1;
		sel++;
		go(i);
		sel--;
		vis[i] = 0;
		now = last;
		--sta;
	}

	if(sta>1){
		int tmp = S[sta];
		--sta;
		go(S[sta]);
		++sta;
		S[sta] = tmp;
	}

}

int main(){
	freopen("C.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tt, m, i, j;
	scanf("%d",&tt);
	for(int cas = 1; cas <= tt; ++cas){
		printf("Case #%d: ", cas);
		AIM = "hi";
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i) cin>>s[i];
		for(i=1;i<=n;++i) for(j=1;j<=n;++j) g[i][j]=0;
		for(i=1;i<=m;++i){
			int l, r;
			scanf("%d%d",&l,&r);
			g[l][r] = g[r][l] = 1;
		}
		sta = 0;
		for(i=1;i<=n;++i) vis[i]=0;
		for(i=1;i<=n;++i){
			S[sta=1] = i;
			vis[i] = 1;
			now = s[i];
			sel=1;
			go(i);
			vis[i] = 0;
		}

		cout << AIM << endl;
	}
}
