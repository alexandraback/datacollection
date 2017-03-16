#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

int dp[55][55][2505];
int dm[55][2505];
int ans[55];
void process(){
	int r,c,m;
	scanf("%d %d %d",&r,&c,&m);
	m=r*c-m;
	if(r==1){
		printf("c");
		for(int i=2;i<=m;i++) printf(".");
		for(int i=m+1;i<=c;i++) printf("*");
		printf("\n");
		return;
	}
	if(c==1){
		printf("c\n");
		for(int i=2;i<=m;i++) printf(".\n");
		for(int i=m+1;i<=r;i++) printf("*\n");
		return;
	}
	for(int i=0;i<=r;i++) for(int j=0;j<=r*c;j++) dm[i][j]=-1;
	for(int i=0;i<=r;i++) for(int j=0;j<=c;j++) for(int k=0;k<=r*c;k++) dp[i][j][k]=-1;
	dp[1][1][1]=0;
	dm[1][1]=1;
	for(int i=2;i<=c;i++){
		dp[2][i][2*i]=i;
		dm[2][2*i]=i;
	}
	for(int i=3;i<=r;i++){
		for(int j=2;j<=c;j++){
			for(int k=j;k<=m;k++){
				if(dm[i-1][k-j]>=j){
					dp[i][j][k]=dm[i-1][k-j];
					dm[i][k]=j;
				}
			}
		}
	}
	for(int i=1;i<=r;i++) ans[i]=0;
	for(int i=1;i<=r;i++) if(dm[i][m]!=-1){
		int o=i,p=m;
		while(o!=0){
			if(o==1) ans[1]=p,o--;
			else if(o==2) ans[1]=ans[2]=p/2,o-=2;
			else{
				ans[o]=dm[o][p];
				p-=dm[o][p];
				o--;
			}

		}
		for(int j=1;j<=r;j++,printf("\n")){
			if(j==1) printf("c");
			for(int k=(j==1)?2:1;k<=ans[j];k++) printf(".");
			for(int k=ans[j]+1;k<=c;k++) printf("*");
		}
		return;
	}
	printf("Impossible\n");
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: \n",i);
		process();
	}
	return 0;
}