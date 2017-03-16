#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;

char str[4002];

struct item {
	item() : leaf(false) {
		memset(next,-1,sizeof(next));
	}
	int next[26];
	bool leaf;
};

item bor[1200002];
int bsize=1;

void add(char * s) {
	int n=strlen(s);
	int cur=0;
	for(int i=0;i<n;++i) {
		int ch=s[i]-'a';
		if (bor[cur].next[ch]==-1) bor[cur].next[ch]=bsize++;
		cur=bor[cur].next[ch];
	}
	bor[cur].leaf=true;
}

int dp[4005][6],len;

void update(int & res,int val) {
	res=res==-1 ? val : min(res,val);
}

void go(int pos,int last,int ch,int cur = 0) {
	if (last>5) last=5;
	if (bor[cur].leaf) {
		update(dp[pos][last],ch);
	}
	if (pos==len) return;
	if (bor[cur].next[str[pos]-'a']!=-1) {
		go(pos+1,last+1,ch,bor[cur].next[str[pos]-'a']);
	}
	if (last==5)
		for(int j=0;j<26;++j) {
			if (j!=(str[pos]-'a')&&bor[cur].next[j]!=-1) {
				go(pos+1,1,ch+1,bor[cur].next[j]);
			}
		}
}

int main() {
	freopen("dict.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(gets(str)) {
		add(str);
//		puts(str);
	}
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d\n",&T);
	for(int test=1;test<=T;++test) {
		printf("Case #%d: ",test);
		memset(dp,-1,sizeof(dp));
		gets(str); int n=strlen(str); len=n;
		dp[0][5]=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<=5;++j)
				if (dp[i][j]!=-1) go(i,j,dp[i][j]);
		int ans=-1;
		for(int j=0;j<=5;++j)
			if (dp[n][j]!=-1) update(ans,dp[n][j]);
		printf("%d",ans);
		printf("\n");
	}
	return 0;
}