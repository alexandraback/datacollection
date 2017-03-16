#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back
#define mp make_pair
#define ST first
#define ND second
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<int,iii> iiii;

string coord="NSEW";

map<iii,iiii> path;

void printPath(iii u) {
	if(path[u].ST==-1) return;
	printPath(path[u].ND);
	printf("%c",coord[path[u].ST]);
}

int main() {
	int t; cin>>t;++t;
	iii start = mp(1,mp(0,0));
	fr(_,1,t) {
		int x,y;
		cin>>x>>y;
		map<iii,int> dist; dist[start]=0;
		path.clear();
		path[start]=mp(-1,start);
		queue<iii> q;
		q.push(start);
		bool fim=0;
		while(!q.empty()) {
			iii u = q.front(); q.pop();
			int xx = u.ND.ST,yy=u.ND.ND,mv=u.ST;
			fr(k,0,4) {
				int tx=xx+dx[k]*mv;
				int ty=yy+dy[k]*mv;
				iii temp = mp(mv+1,mp(tx,ty));
				if(dist.count(temp)) continue;
				dist[temp]=dist[u]+1;
				path[temp]=mp(k,u);
				if(tx==x&&ty==y) {
					printf("Case #%d: ",_);
					printPath(temp);
					puts("");
					fim=1;
				}
				q.push(temp);
			}
			if(fim) break;
		}
	}
	return 0;
}
