#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define foreach(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair

const int INF = ~0U >> 4;
const double eps = 1e-6;

const int MAXN = 4400;
const int MAXT = 2000000;

int T[MAXT][26],T2[MAXT],tot;

void tree_init(int t){
	memset(T[t],0,sizeof(int)*26);
}
void insert(char *s){
	int t=0;
	while (*s){
		int c=(*s)-'a';
		if (T[t][c]==0){
			tree_init(++tot);
			T[t][c]=tot;
		}
		t=T[t][c];
		s++;
	}
	T2[t]=1;
}

int dn,max_len;
void predo(){
	FILE *fin=fopen("dictionary.txt","r");
	char s[20];
	max_len=0;
	tree_init(tot=0);
	while (fscanf(fin,"%s",s)!=EOF){
		insert(s);
		//int len=strlen(s);
		//if (len>max_len) max_len=len;
		//dn++;
	}
	//printf("%d\n",dn); 521196
	//printf("max_len=%d\n",max_len); //10
	//printf("tot=%d\n",tot); 1125077
	fclose(fin);
}
string S;
int n,g[MAXN][10][11][11],sbegin,f[MAXN][10];
void dfs(int t,int dep,int first,int last,int now){
	if (dep && T2[t]){
		int first2=(first==-1)?(dep):(first);
		int second2=(last==-5)?(dep):(last);
		g[sbegin][dep-1][first2][second2]=min(g[sbegin][dep-1][first2][second2],now);
	}
	if (dep==10 || sbegin+dep>n) return;
	int c=S[sbegin+dep]-'a';
	if (T[t][c]){
		dfs(T[t][c],dep+1,first,last,now);
	}
	if (dep-last>=5){
		for (int i=0;i<26;i++) if (i!=c && T[t][i]){
			dfs(T[t][i],dep+1,(first==-1)?(dep):(first),dep,now+1);
		}
	}
}
void calc_g(){
	for (int i=0;i<n;i++) for (int j=0;j<10;j++) for (int f=0;f<=10;f++) for (int l=f;l<=10;l++) g[i][j][f][l]=INF;
	for (int i=0;i<n;i++){
		sbegin=i;
		dfs(0,0,-1,-5,0);
	}
}
int solve(){
	cin>>S;
	n=S.length();
	calc_g();
	for (int i=0;i<=n;i++) for (int j=0;j<=5;j++) f[i][j]=INF;
	f[0][0]=0;
	for (int i=0;i<n;i++){
		for (int l=0;l<=5;l++){
			if (f[i][l]==INF) continue;
			for (int j=0;j<10;j++)
				for (int first=0;first<=j+1;first++)
					for (int second=first;second<=j+1;second++){
						if (g[i][j][first][second]==INF) continue;
						if (l!=0 && first!=j+1 && l+first<5) continue;
						int l2;
						if (first==second && first==j+1){ //no change
							if (l==0){
								l2=0;
							}else{
								l2=l+(j+1);
								if (l2>5) l2=0;
							}
						}else{
							l2=(j+1)-second;
							if (l2>5) l2=0;
						}
						f[i+j+1][l2]=min(f[i+j+1][l2],f[i][l]+g[i][j][first][second]);
					}
		}
	}
	int res=INF;
	for (int i=0;i<=5;i++) res=min(res,f[n][i]);
	return res;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	predo();
	int Tc;
	cin>>Tc;
	for (int i=1;i<=Tc;i++) printf("Case #%d: %d\n",i,solve());
    return 0;
}
