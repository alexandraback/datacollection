#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define y1 y1_
#define ran() (rand()<<15|rand())

const int mo=(int)1e9+7,inf=(int)1e9;
const ll linf=(ll)1e18;

int k,L,s;
int cnt[26];
char str[105];
int next[105];
int go[105][26];
db f[105][105];
int g[105][105];

db Main(){
	scanf("%d%d%d",&k,&L,&s);
	scanf("%s",str);
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<k;i++) cnt[str[i]-='A']++;
	scanf("%s",str+1);
	for(int i=1;i<=L;i++) str[i]-='A';
	str[L+1]=26;
	next[1]=0;
	for(int i=2;i<=L;i++){
		int j;
		for(j=next[i-1];j&&str[j+1]!=str[i];j=next[j]);
		if(str[j+1]==str[i]) j++;
		next[i]=j;
	}
	for(int i=0;i<=L;i++)
		for(int c=0;c<26;c++){
			int j=i;
			while(j&&str[j+1]!=c) j=next[j];
			if(str[j+1]==c) j++;
			go[i][c]=j;
		}
	for(int j=0;j<L;j++){
		f[s][j]=0;
		g[s][j]=0;
	}
	for(int i=s-1;i>=0;i--)
		for(int j=0;j<L;j++){
			f[i][j]=0;
			g[i][j]=0;
			for(int c=0;c<26;c++) if(cnt[c]){
				int jj=go[j][c];
				if(jj==L){
					f[i][j]+=(1+f[i+1][next[L]])*cnt[c]/k;
					g[i][j]=max(g[i][j],1+g[i+1][next[L]]);
				}
				else{
					f[i][j]+=f[i+1][jj]*cnt[c]/k;
					g[i][j]=max(g[i][j],g[i+1][jj]);
				}
			}
		}
//	printf("f=%lf g=%d\n",f[0][0],g[0][0]);
	return g[0][0]-f[0][0];
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++)
		printf("Case #%d: %.12lf\n",Case,Main());
	scanf("\n");
}
