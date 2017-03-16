#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define PB push_back
#define FORE(it,c) for(typeof(c.begin())it=c.begin();it!=c.end();it++)
typedef long long llint;
typedef pair<int,int> II;

const int maxN=1011;

vector<int> a[maxN];
int n,visit[maxN],qu[maxN],bot,top;
bool res;

void enter(){
	for (int i=0;i<maxN;++i) a[i].clear();
	scanf("%d",&n);
	int m,u;
	for (int i=1;i<=n;i++){
	    scanf("%d",&m);
	    while (m--){
	        scanf("%d",&u);
	        a[i].PB(u);
	    }
	}
}

void process(int s){
    memset(visit,0,sizeof visit);
    visit[s]=1;
    bot=top=1; qu[1]=s;
    while (bot<=top){
        int u=qu[bot++];
        FORE (it,a[u]) if (visit[*it]==0){
            visit[*it]=1;
            qu[++top]=*it;
        }
        else res=true;
    }
}

void solve(){
    res=false;
	for (int i=1;i<=n;++i) process(i);
	if (res) printf("Yes\n"); else printf("No\n");
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
	    printf("Case #%d: ",i);
	    enter();
        solve();
	}
	return 0;
}
