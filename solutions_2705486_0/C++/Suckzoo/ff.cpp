#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <malloc.h>
using namespace std;
int dy[4010];
int T,Ti;
char text[4010];
char words[521196][11];
int comp(int s,int e) {
	int i,j,lastindx=-5,cnt,ans=99999;
	char w[11];
	for(i=s;i<=e;i++) {
		w[i-s]=text[i];
	}
	for(i=0;i<521196;i++) {
		cnt=0;
		lastindx=-5;
		if(strlen(words[i])!=e-s+1) continue;
		for(j=0;j<e-s+1;j++) {
			if(w[j]!=words[i][j]) {
				if(j-lastindx<=4) break;
				lastindx=j;
				cnt++;
			}
		}
		if(j==e-s+1) {
			if(ans>cnt) ans=cnt;
		}
	}
	return ans;
}
int main() {
	FILE *fi=fopen("dict.txt","rt");
	int i,j;
	for(i=0;i<521196;i++) {
		fscanf(fi,"%s",words[i]);
	}
	fclose(fi);
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++) {
		strset(text,0);
		memset(dy,-1,sizeof(dy));
		scanf("%s",text+1);
		dy[0]=0;
		int n=strlen(text+1);
		for(i=1;i<=n;i++) {
			for(j=i;j>i-10;j--) {
				if(j==0) break;
				int dv=dy[j-1]+comp(j,i);
				if(dv<dy[i] || dy[i]==-1) {
					dy[i]=dv;
				}
			}
		}
		printf("Case #%d: %d\n",Ti,dy[n]);
	}
	return 0;
}

/*
struct trie {
	int accept;
	set<char,trie*> portal;
};
trie h;
	trie* q,w;
	h.accept=0;
	for(i=0;i<521196;i++) {
		q=h;
		fscanf(fi,"%s",words);
		int n=strlen(words)-1
		for(j=n;j>=0;j--) {
			if(h.portal[words[j]]==NULL) {
				w=(trie*)malloc(sizeof(trie));
				q->portal[words[j]]=w;
				q=w;
				q->accept=0;
			} else {
				q=q->portal[words[j]];
			}
			if(j==0) {
				q->accept=1;
			}
		}
	}
*/