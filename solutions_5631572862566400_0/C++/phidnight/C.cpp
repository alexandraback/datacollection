#include <cstdio>

int eto[9999];
int revsiz[9999];
int rev[1999][1999];
int checked[9999];
int T,N;
int sol;
int solx;
int dfs(int nw) {
	int ret=0;
	for(int i=0;i<revsiz[nw];i++) {
		int temp=dfs(rev[nw][i]);
		if(ret<temp) ret=temp;
	}
	return ret+1;
}
void calc(int nw) {
	//def circle
	int csiz=1;
	int cur=eto[nw];
	while(cur!=nw) {
		csiz++;
		cur=eto[cur];
	}
	cur=nw;
	if(sol<csiz) sol=csiz;
	int k1=0;
	int k2=0;
	if(csiz==2) {
		for(int i=0;i<revsiz[nw];i++) {
			if(rev[nw][i]!=eto[nw]) {
				int temp=dfs(rev[nw][i]);
				if(k1<temp) k1=temp;
			}
		}
		for(int i=0;i<revsiz[eto[nw]];i++) {
			if(rev[eto[nw]][i]!=nw) {
				int temp=dfs(rev[eto[nw]][i]);
				if(k2<temp) k2=temp;
			}
		}
		solx+=k1+k2+2;
	}
}
void search(int nw) {
	checked[nw]=1;
	if(checked[eto[nw]]==1) {
		//circle found
		calc(nw);
	} else if(checked[eto[nw]]==0) {
		search(eto[nw]);
	}
	checked[nw]=2;
}
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%d",&N);
		sol=0;
		solx=0;
		for(int i=1;i<=N;i++) {
			scanf("%d",&eto[i]);
			checked[i]=0;
			revsiz[i]=0;
		}
		for(int i=1;i<=N;i++) rev[eto[i]][revsiz[eto[i]]++]=i;
		for(int i=1;i<=N;i++) {
			if(checked[i]==0) search(i);
		}
		if(sol<solx) sol=solx;
		printf("Case #%d: %d\n",ts,sol);
	}
	return 0;
}
