#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int T,n,m,casno=1;
int a[11][11];
int vis[11][11];

int main() {
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) cin>>a[i][j];
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			bool all=true;
			for(int j=0;j<m;j++) if(a[i][j]==2) all=false;
			if(all) for(int j=0;j<m;j++) vis[i][j]=1;
		}
		for(int j=0;j<m;j++){
			bool all=true;
			for(int i=0;i<n;i++) if(a[i][j]==2) all=false;
			if(all) for(int i=0;i<n;i++) vis[i][j]=1;
		}
		bool yes=true;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) if(a[i][j]==1 && vis[i][j]==false) yes=false;
		printf("Case #%d: %s\n",casno++,yes?"YES":"NO");
	}
	return 0;
}
