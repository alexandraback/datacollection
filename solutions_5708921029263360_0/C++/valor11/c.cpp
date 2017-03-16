#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 11;
const int M = N*N*N;
//#define LOACL
struct match
{
	int a,b,c;
	match(){}
	match(int _a,int _b,int _c){
		a=_a; b=_b; c=_c;
	}
	void print(){
		printf("%d %d %d\n",a,b,c);
	}
}matches[M];

int ab[N][N],bc[N][N],ac[N][N];
int n1,n2,n3,kk;
int pick[M];
int ans_pick[M];
int ans;
int m;

int check(){
	memset(ab,0,sizeof(ab));
	memset(ac,0,sizeof(ac));
	memset(bc,0,sizeof(bc));
	for(int i=0;i<m;i++)
		if (pick[i]){
			match t=matches[i];
			ab[t.a][t.b]++;
			ac[t.a][t.c]++;
			bc[t.b][t.c]++;
			if (ab[t.a][t.b]>kk) return 0;
			if (bc[t.b][t.c]>kk) return 0;
			if (ac[t.a][t.c]>kk) return 0;
		}
	return 1;
}

void dfs(int m,int s){
	if (m==::m){
		
			if (s>ans){
				ans = s;
				//printf("***%d\n",ans);
				for(int i=0;i<m;i++)
					ans_pick[i] = pick[i];
			}
		
		return;
	}
	if (s + ::m-m <= ans) return;
	match t = matches[m];
	int flg=1;
	if (ab[t.a][t.b]>=kk) flg=0; 
	if (bc[t.b][t.c]>=kk) flg=0;
	if (ac[t.a][t.c]>=kk) flg=0;
	if (flg){
		pick[m] = 1;
		ab[t.a][t.b]++;
		ac[t.a][t.c]++;
		bc[t.b][t.c]++;
		dfs(m+1,s+1);
		pick[m] = 0;
		ab[t.a][t.b]--;
		ac[t.a][t.c]--;
		bc[t.b][t.c]--;
	}
	

	dfs(m+1,s);
	
}

int main(){
	#ifdef LOACL
	freopen("C-small-attempt2.in","r",stdin);
	freopen("c.out","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	for(int times=1;times<=T;times++){
		scanf("%d%d%d%d",&n1,&n2,&n3,&kk);
		printf("Case #%d: ",times);
		memset(pick,0,sizeof(pick));
		memset(ans_pick,0,sizeof(ans_pick));
		memset(ab,0,sizeof(ab));
		memset(ac,0,sizeof(ac));
		memset(bc,0,sizeof(bc));
		m = 0;
		for(int i=1;i<=n1;i++)
			for(int j=1;j<=n2;j++)
				for(int k=1;k<=n3;k++)
					matches[m++] = match(i,j,k);
		ans = -1;
		if (kk<n1 || kk<n2 || kk<n3) {
			dfs(0,0);
			printf("%d\n",ans);
			for(int i=0;i<m;i++)
			if (ans_pick[i]){
				matches[i].print();
			}
		}else{
			printf("%d\n",m);
			for(int i=0;i<m;i++) matches[i].print();
		}
	}
	return 0;
}
