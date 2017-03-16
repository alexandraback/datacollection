#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<vector>
#include<functional>
#include<string>
#define INF 1000000007
#define ll long long
#define rep(i,k) for(int i=G.start[k];i!=INF;i=G.next[i])

using namespace std;

bool t3[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,1,0},{0,0,1,1,1},{0,0,0,1,0}};
bool t4[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,1},{0,0,0,1,1}};

int main()
{
freopen("t.in","r",stdin);
freopen("t.out","w",stdout);
	ios::sync_with_stdio(false);
	
    int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		bool fg=0;
		int x,r,c;
		cin>>x>>r>>c;
		if(x==1)
			fg=1;
		if(x==2)
			if(r%2==0||c%2==0)fg=1;
		if(x==3)
			fg=t3[r][c];
		if(x==4)
			fg=t4[r][c];
		cout<<"Case #"<<cas<<": ";
		if(fg)cout<<"GABRIEL"<<endl;
		else cout<<"RICHARD"<<endl;
	}
	
	return 0;
}
