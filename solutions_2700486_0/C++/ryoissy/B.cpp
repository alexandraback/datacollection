#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <complex> 
#include <string>
#include <vector> 
#include <list>
#include <deque> 
#include <stack> 
#include <queue> 
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm> 
#include <numeric> 
#include <typeinfo> 
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <climits> 
#include <ctime>
using namespace std;

typedef __int64 ll;
typedef pair<double,double> P;

int t;
int nm,x,y;
int fie[501][501];
double ka[501][501];

void dfs(int n,int px,int py,double p){
	if(n>=nm)return;
	if(py==250 || (fie[px-1][py+1]==1 && fie[px+1][py+1]==1)){
		fie[px][py]=1;
		ka[px][py]+=p;
		dfs(n+1,250,0,p);
		fie[px][py]=0;
	}
	else if(fie[px][py+2]==1){
		if(fie[px-1][py+1]==0 && fie[px+1][py+1]==0){
			dfs(n,px-1,py+1,p/2);
			dfs(n,px+1,py+1,p/2);
		}else if(fie[px-1][py+1]==0){
			dfs(n,px-1,py+1,p);
		}else if(fie[px+1][py+1]==0){
			dfs(n,px+1,py+1,p);
		}else{
			fie[px][py]=1;
			ka[px][py]+=p;
			dfs(n+1,250,0,p);
			fie[px][py]=0;
		}
	}else if(fie[px-1][py+1]==1 && fie[px+1][py+1]==0){
		dfs(n,px+1,py+1,p);
	}else if(fie[px-1][py+1]==0 && fie[px+1][py+1]==1){
		dfs(n,px-1,py+1,p);
	}else{
		dfs(n,px,py+1,p);
	}
}

int main(void){
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		scanf("%d%d%d",&nm,&x,&y);
		memset(fie,0,sizeof(fie));
		memset(ka,0.0,sizeof(ka));
		if(abs(x)+abs(y)>=250)printf("Case #%d: 0.00000000\n",test);
		else{
			dfs(0,250,0,1.0);
			printf("Case #%d: %0.9f\n",test,ka[250+x][250-y]);
		}
	}
	return 0;
}