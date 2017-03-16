#include<bits/stdc++.h>
using namespace std;
char bord[105][105];

int main(){
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		int h,w;cin>>h>>w;
		for(int i=0;i<h;i++)scanf("%s",bord[i]);
		int answer=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(bord[i][j]=='.')continue;
				bool l=false,r=false,top=false,bot=false;
				for(int i2=i-1;i2>=0;i2--)if(bord[i2][j]!='.')top=true;
				for(int i2=i+1;i2< h;i2++)if(bord[i2][j]!='.')bot=true;
				for(int j2=j-1;j2>=0;j2--)if(bord[i][j2]!='.')l=true;
				for(int j2=j+1;j2< w;j2++)if(bord[i][j2]!='.')r=true;
				if(!top&&!bot&&!l&&!r){goto impossible;}
				if(!top&&bord[i][j]=='^')answer++;
				if(!bot&&bord[i][j]=='v')answer++;
				if(!l&&bord[i][j]=='<')answer++;
				if(!r&&bord[i][j]=='>')answer++;
			}
		}
		printf("Case #%d: %d\n",tc,answer);
		continue;
		impossible:;
		printf("Case #%d: IMPOSSIBLE\n",tc);
	}
}
