#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int g[150][150];
bool note[150][150];
int main(){
	int t,n,m,cas=1;
	freopen("E://B-small-attempt0.in","r",stdin);
		freopen("E://B-small-attempt0.out","w+",stdout);
	scanf("%d",&t);
	while(t--){
		
		scanf("%d%d",&n,&m);
		int s=n*m;
		memset(note,0,sizeof(note));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)
				scanf("%d",&g[i][j]);
		}
		for(int i=0;i<n;++i){
			int mm=0;
			for(int j=0;j<m;++j)
				if(mm<g[i][j])
					mm=g[i][j];
			for(int j=0;j<m;++j)
				if(mm==g[i][j]){
					note[i][j]=1;
					--s;
				}
		}
		for(int i=0;i<m;++i){
			int mm=0;
			for(int j=0;j<n;++j)
				if(mm<g[j][i])
					mm=g[j][i];
			for(int j=0;j<n;++j)
				if(mm==g[j][i] && note[j][i]==0){
					note[j][i]=1;
					--s;
				}
		}
		printf("Case #%d: ",cas++);
		if(s==0)
			printf("YES\n");
		else
			printf("NO\n");
	}return 0;
}