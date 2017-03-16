#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool submit=true;

int T;
int n,m,s[101][101];
bool bh,bv;
int main(){
	if(submit){
		freopen("B-large.in.txt","r",stdin);
		freopen("B-large.txt","w",stdout);
	}
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d %d",&n,&m);
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++) scanf("%d",&s[j][k]);
		}
		printf("Case #%d: ",i);
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				bh=bv=false;
				for(int l=0;l<m;l++) if(s[j][l]>s[j][k]) bh=true;
				for(int l=0;l<n;l++) if(s[l][k]>s[j][k]) bv=true;
				if(bh&&bv){
					printf("NO\n");
					goto gg;
				}
			}
		}
		printf("YES\n");
		gg:;	
	}
	return 0;
}
