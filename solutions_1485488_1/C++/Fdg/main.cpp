#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
//#include <cmath>
#include <set>

#define ll long long

using namespace std;

int ceil[101][101],floor[101][101];

int dp[101][101];

int get(int fh1,int ch1,int wh1,int fh2,int ch2) {
	if (fh2+50>ch1||fh1+50>ch2||fh2+50>ch2) return -1;
	return max(0,(wh1-(ch2-50)));
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int TT=1;TT<=T;++TT) {
		printf("Case #%d: ",TT);
		int h,n,m;
		scanf("%d%d%d",&h,&n,&m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&ceil[i][j]);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&floor[i][j]);
		memset(dp,-1,sizeof(dp));
		bool can[101][101]={0};
		can[0][0]=true;
		vector <pair<int,int> > q(1,make_pair(0,0));
		int dx[]={-1,0,0,1},
			dy[]={0,-1,1,0};
		for(int i=0;i<q.size();++i) {
			for(int t=0;t<4;++t) {
				if (q[i].first+dx[t]>=0&&q[i].first+dx[t]<n&&q[i].second+dy[t]>=0&&q[i].second+dy[t]<m&&
					!can[q[i].first+dx[t]][q[i].second+dy[t]]&&get(floor[q[i].first][q[i].second],ceil[q[i].first][q[i].second],h,floor[q[i].first+dx[t]][q[i].second+dy[t]],ceil[q[i].first+dx[t]][q[i].second+dy[t]])==0) {
					q.push_back(make_pair(q[i].first+dx[t],q[i].second+dy[t]));
					can[q[i].first+dx[t]][q[i].second+dy[t]]=true;
				}
			}
		}
		q.clear();
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if (can[i][j]) {
					dp[i][j]=0;
					q.push_back(make_pair(i,j));
				}
		for(int tt=0;tt<q.size();++tt)
			for(int t=0;t<4;++t) {
				if (q[tt].first+dx[t]>=0&&q[tt].first+dx[t]<n&&q[tt].second+dy[t]>=0&&q[tt].second+dy[t]<m) {
					int tm1=get(floor[q[tt].first][q[tt].second],ceil[q[tt].first][q[tt].second],h-dp[q[tt].first][q[tt].second],floor[q[tt].first+dx[t]][q[tt].second+dy[t]],ceil[q[tt].first+dx[t]][q[tt].second+dy[t]]);
					if (tm1!=-1&&(dp[q[tt].first+dx[t]][q[tt].second+dy[t]]==-1||dp[q[tt].first+dx[t]][q[tt].second+dy[t]]>(dp[q[tt].first][q[tt].second]+tm1+(h-tm1-dp[q[tt].first][q[tt].second]-floor[q[tt].first][q[tt].second]>=20 ? 10 : 100)))) {
						dp[q[tt].first+dx[t]][q[tt].second+dy[t]]=(dp[q[tt].first][q[tt].second]+tm1+(h-tm1-dp[q[tt].first][q[tt].second]-floor[q[tt].first][q[tt].second]>=20 ? 10 : 100));
						q.push_back(make_pair(q[tt].first+dx[t],q[tt].second+dy[t]));
					}
				}
			}
		int ans=dp[n-1][m-1];
		printf("%.8lf\n",ans/10.0);
	}
	return 0;
}
