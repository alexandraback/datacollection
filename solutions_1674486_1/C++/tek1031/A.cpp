#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

int num=0;
bool visit[10001];
int n;
vector<vector<int>> connect(n,vector<int>());
int G;

void go(int now){
	if(visit[now]) return;
	if(now==G){num++;return;}
	if(num>=2) return;
	visit[now]=true;

	for(int i=0;i<connect[now].size();i++){
		go(connect[now][i]);
	}
}

void check(int start,int goal){
	G=goal;
	for(int i=0;i<connect[start].size();i++){
		go(connect[start][i]);
	}
}

int main()
{
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		connect.clear();
		connect.resize(n+1,vector<int>());
		for(int i=1;i<=n;i++){
			int m; cin>>m;
			for(int j=1;j<=m;j++){
				int c;cin>>c;
				connect[i].push_back(c);
			}
		}
		bool ans=false;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){				
				num=0;
				memset(visit,false,sizeof(visit));
				if(i==j) continue;
				check(i,j);
				if(num>=2){ans=true; break;}
			}
			if(ans) break;
		}
		cout<<"Case #"<<t<<": ";
		if(ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}