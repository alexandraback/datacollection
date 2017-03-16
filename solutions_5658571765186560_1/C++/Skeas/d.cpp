#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int T,cs;
int x,r,c;

const char ric[] = "RICHARD";
const char gab[] = "GABRIEL";

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

vector< vector< pair<int,int> > > vs,rvs;
bool ck[100][100]; int BASE = 50;
void build(int x, int y, int cnt, vector< pair<int,int> > &vv) {
	if(cnt == 0) {
		vector< pair<int,int> > v = vv;
		int mx = 1000, my = 1000;
		for(int i=0;i<v.size();++i)
			mx = min(mx, v[i].first),
			my = min(my, v[i].second);
		for(int i=0;i<v.size();++i)
			v[i].first -= mx,
			v[i].second -= my;
		sort(v.begin(),v.end());
		vs.push_back(v);
		return;
	}
	for(int i=0;i<4;++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(ck[nx+BASE][ny+BASE]) continue;
		ck[nx+BASE][ny+BASE] = 1;
		vv.push_back(make_pair(nx,ny));
		build(nx,ny,cnt-1,vv);
		vv.pop_back();
		ck[nx+BASE][ny+BASE] = 0;
	}
}

vector< pair<int,int> > rot90(vector< pair<int,int> > v) {
	int n = v.size();
	int mx = 1000, my = 1000;
	for(int i=0;i<n;++i) {
		swap(v[i].first, v[i].second);
		v[i].second *= -1;
		mx = min(mx, v[i].first);
		my = min(my, v[i].second);
	}
	for(int i=0;i<n;++i) {
		v[i].first -= mx;
		v[i].second -= my;
	}
	sort(v.begin(), v.end());
	return v;
}

vector< pair<int,int> > ref(vector< pair<int,int> > v) {
	int n = v.size();
	int mx = 1000, my = 1000;
	for(int i=0;i<n;++i) {
		v[i].first *= -1;
		mx = min(mx, v[i].first);
	}
	for(int i=0;i<n;++i) v[i].first -= mx;
	sort(v.begin(),v.end());
	return v;
}

bool same(vector< pair<int,int> > &a, vector< pair<int,int> > &b) {
	vector< pair<int,int> > tmp;

	tmp = a;
	if(tmp == b) return 1;
	tmp = rot90(tmp);
	if(tmp == b) return 1;
	tmp = rot90(tmp);
	if(tmp == b) return 1;
	tmp = rot90(tmp);
	if(tmp == b) return 1;

	tmp = ref(a);
	if(tmp == b) return 1;
	tmp = rot90(tmp);
	if(tmp == b) return 1;
	tmp = rot90(tmp);
	if(tmp == b) return 1;
	tmp = rot90(tmp);
	if(tmp == b) return 1;

	return 0;
}

bool vis[22][22];
int dfs_cnt(int x, int y) {
	int ret = 1;
	vis[x][y] = 1;
	for(int i=0;i<4;++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= r) continue;
		if(ny < 0 || ny >= c) continue;
		if(vis[nx][ny]) continue;
		ret += dfs_cnt(nx,ny);
	} return ret;
}

bool check(vector< pair<int,int> > v, int xx) {
	for(int i=0;i<r;++i) for(int j=0;j<c;++j) {
		memset(vis,0,sizeof(vis));
		bool ok = 1;
		for(int k=0;k<v.size();++k) {
			int x = v[k].first + i;
			int y = v[k].second + j;
			if(x >= r || y >= c) ok = 0;
			else vis[x][y] = 1;
		}
		if(!ok) continue;
		for(int x=0;x<r;++x) for(int y=0;y<c;++y) if(!vis[x][y])
			ok &= (dfs_cnt(x,y) % xx == 0);
		if(ok) return 1;
	} return 0;
}

int main() {
	scanf("%d",&T);
	for(cs=1;cs<=T;++cs) {
		printf("Case #%d: ",cs);
		scanf("%d%d%d",&x,&r,&c);
		if(x >= 7) printf("%s\n",ric);
		else {
			if(r * c % x != 0) printf("%s\n",ric);
			else if(min(r,c) >= x) printf("%s\n",gab);
			else {		
				vs.clear(),rvs.clear();
				vector< pair<int,int> > v; v.push_back(make_pair(0,0));
				ck[BASE][BASE] = 1;
				build(0,0,x-1,v);
				ck[BASE][BASE] = 0;


				for(int i=0;i<vs.size();++i) {
					bool no = 0;
					for(int j=0;j<rvs.size();++j) if(same(vs[i],rvs[j])) {
						no = 1; break;
					}
					if(!no) rvs.push_back(vs[i]);
				}
				
				bool ok = 1;
				for(int i=0;i<rvs.size();++i) {
					vector< pair<int,int> > t;
					bool ck = 0;
					t = rvs[i];
					ck |= check(t,x);
					t = rot90(t);
					ck |= check(t,x);
					t = rot90(t);
					ck |= check(t,x);
					t = rot90(t);
					ck |= check(t,x);
					
					t = ref(rvs[i]);
					ck |= check(t,x);
					t = rot90(t);
					ck |= check(t,x);
					t = rot90(t);
					ck |= check(t,x);
					t = rot90(t);
					ck |= check(t,x);
					
					ok &= ck;
				}
				if(ok) printf("%s\n",gab);
				else printf("%s\n",ric);
			}
		}
	}
}
