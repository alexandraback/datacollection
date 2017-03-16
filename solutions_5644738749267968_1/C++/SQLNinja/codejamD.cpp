#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
#include<climits>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a,b;
double t1[1001],t2[1001];
int M[2010][2010],m;
int check[2010];
int T,TT,n;

bool dfs(int v);

int main(){
     freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int i,j;
	scanf("%d",&TT);
	while(TT--){
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%lf",&t1[i]);
		for(i=0;i<n;i++)scanf("%lf",&t2[i]);
		m=2*n+1;
				memset(g,0,sizeof(g));
        sort(t2,t2+n);
        		sort(t1,t1+n);


		for(i=0;i<n;i++)M[0][1+i]=1;
		for(i=0;i<n;i++)M[1+n+i][m]=1;
		for(i=0;i<n;i++)for(j=0;j<n;j++)
			M[1+i][1+n+j]=(t1[i]>t2[j]?1:0);
		for(a=0;dfs(0);a++);

		a=0;
		for(i=j=n-1;i>=0&&j>=0;){
			if(t1[i]>t2[j]){
				a++;
				i--;
			}else{
				j--;
			}
		}

		b=0;
		for(i=j=n-1;i>=0;i--){
			if(t1[i]>t2[j]){
				b++;
			}else{
				j--;
			}
		}

		printf("Case #%d: %d %d\n",++T,a,b);
	}
	return 0;
}


bool dfs(int v){
	if(v==m)return 1;
	check[v]=1;
	for(int i=0;i<=m;i++)
		if(M[v][i]&&!check[i]&&dfs(i)){
			M[v][i]=0;
			M[i][v]=1;
			check[v]=0;
			return 1;
		}
	check[v]=0;
	return 0;
}
