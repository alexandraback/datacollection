#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int g[1001][1001];
bool can[1001];
bool vis[1001];
int n;

bool dfs(int i)
{
	if(vis[i]){
		return true;
	}
	vis[i]=true;
	for(int j=1;j<=n;j++){
		if(g[i][j]){
			if(dfs(j)) return true;
		}
	}
	return false;
}

int main()
{
	int x;
	cin>>x;
	for(int y=1;y<=x;y++){
		cin>>n;
		memset(g,0,sizeof g);
		memset(can,0,sizeof can);
		
		for(int i=1;i<=n;i++){
			int tmp;
			cin>>tmp;
			for(int j=0;j<tmp;j++){
				int orz;
				cin>>orz;
				g[i][orz]=1;
				can[orz]=1;
			}
		}
		bool orz=false;
		for(int i=1;i<=n;i++){
			if(!can[i]){
				memset(vis,0,sizeof vis);
				if(dfs(i)){
					orz=true;
					cout<<"Case #"<<y<<": Yes"<<endl;
					break;
				}
			}
		}
		if(!orz) cout<<"Case #"<<y<<": No"<<endl;
	}
}