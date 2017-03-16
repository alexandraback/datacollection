#include <cstdio>
#include <deque>
using namespace std;

int solve1(int N,int M,int K)
{
	int res = 1000000000;
	for (int msk=0;msk<(1<<(N*M));++msk) {
		char mp[20][20]={};
		int cnt = 0;
		for (int i=0;i<N;++i)
			for (int j=0;j<M;++j)
				if (msk&(1<<(i*M+j))) {
					mp[i][j] = 1;
					cnt++;
				}
		if (cnt>res)
			continue;
		deque<pair<int,int> >d;
		for (int i=0;i<N;++i) {
			d.push_back(make_pair(i,-1));
			d.push_back(make_pair(i,M));
		}
		for (int j=0;j<M;++j) {
			d.push_back(make_pair(-1,j));
			d.push_back(make_pair(N,j));
		}
		int u = N*M;
		while (!d.empty()) {
			pair<int,int> pp = d.front();
			d.pop_front();
			const int sx[4] = {1, -1, 0,  0};
			const int sy[4] = {0,  0, 1, -1};
			for (int i=0;i<4;++i) {
				int nx = pp.first + sx[i];
				int ny = pp.second + sy[i];
				if (nx<0 || ny<0 || nx>=N || ny>=M || mp[nx][ny]!=0)
					continue;
				mp[nx][ny] = 1;
				u --;
				d.push_back(make_pair(nx,ny));
			}
		}
		if (u==K)
			res = min(res,cnt);
	}
	return res;
}

int solve2()
{
	return 0;
}

int solve()
{
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	int val1 = solve1(N,M,K);
	/*int val2 = solve2(N,M,K);
	if (val1!=val2) {
		printf("Bad %d %d %d, %d!=%d\n",N,M,K,val1,val2);
		exit();
	}*/
	return val1;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;++t)
		printf("Case #%d: %d\n",t,solve());
	return 0;
}
