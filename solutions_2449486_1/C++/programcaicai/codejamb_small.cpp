#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int T,n,m,casno=1;
int a[111][111];
int vis[111][111];


bool cut(int height){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		bool all=true;
		for(int j=0;j<m;j++) if(a[i][j]>height) all=false;
		if(all) for(int j=0;j<m;j++) vis[i][j]=1;
	}
	for(int j=0;j<m;j++){
		bool all=true;
		for(int i=0;i<n;i++) if(a[i][j]>height) all=false;
		if(all) for(int i=0;i<n;i++) vis[i][j]=1;
	}
	bool yes=true;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) if(a[i][j]<=height && vis[i][j]==false) yes=false;
	return yes;
}



int main() {
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) cin>>a[i][j];
		bool yes=true;
		for(int i=100;i>=1;i--) yes&=cut(i);
		printf("Case #%d: %s\n",casno++,yes?"YES":"NO");
	}
	return 0;
}
