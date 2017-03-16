#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int T,in[1010][1010],out[1010],loop[1010],n,tmp,len,ans,size;
bool flag[1010];

/*void dfs_loop(int st,int now, int size){
	if(flag[out[now]]) {
		flag[out[now]]=false;
		dfs_loop(st,out[now],size+1);
	}
	else if(out[now][i]==st) loop[st]=size;
}*/

void dfs_in(int i,int size){
	if (in[i][0]!=0){
		for(int j=1;j<=in[i][0];j++) {
			if(in[i][j]!=out[i]) dfs_in(in[i][j],size+1);
		}
	}
	else {
		if (size>len) len=size;
	}	
}

int main(){
	freopen("bff.in","r",stdin);
	freopen("bff.out","w",stdout);
	
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++) in[j][0]=0; 
		for(int j=1;j<=n;j++){
			scanf("%d",&tmp);
			out[j]=tmp;
			in[tmp][0]++; in[tmp][in[tmp][0]]=j;
		}
		for(int j=1;j<=n;j++){
			loop[j]=0;
			memset(flag,true,sizeof(bool)*1010);
			flag[j]=false;
			//dfs_loop(j,j,1);
			tmp=j; size=1;
			while (flag[out[tmp]]){
				flag[out[tmp]]=false; tmp=out[tmp]; size++;
			}
			if (out[tmp]==j)loop[j]=size;
		}
	//	for(int j=1;j<=n;j++) printf("%d ",loop[j]); printf("\n");
		ans=loop[1];
		for (int j=2;j<=n;j++){
			if (loop[j]>ans) ans=loop[j];
		}
		tmp=0;
		
/*		for(int j=1;j<=n;j++){
			for (int k=0;k<=in[j][0];k++) printf("%d ",in[j][k]); printf("\n");
		}*/
		
		for(int j=1;j<=n;j++){
			if (loop[j]==2){
				memset(flag,true,sizeof(bool)*1010);
				flag[j]=false;
				len=0; dfs_in(j,0);
				tmp++; tmp+=len;
			}
		}
		if (tmp>ans) ans=tmp;
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
