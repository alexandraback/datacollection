#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <algorithm>
using namespace std;
const int N = 60;
typedef long long ll;

int t,n;
double x[N],y[N];
bool vis[N];
int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%lf",x+i);
		for(int i=0;i<n;++i)scanf("%lf",y+i);
		int res1=0,res2=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i){
			int index=-1;
			double value=-1;
			for(int j=0;j<n;++j){
				if(value<y[j]&&y[j]<x[i] && !vis[j]){
					value = y[j];
					index = j;
				}
			}
			if(index!=-1){
				vis[index]=1;
				++res1;
			}
		}
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i){
			int index=-1;
			double Mx = (1<<30);
			for(int j=0;j<n;++j){
				if(!vis[j] && Mx>y[j] && y[j]>x[i]){
					Mx = y[j];
					index = j;
				}
			}
			if(index!=-1){
				vis[index]=1;
			}else{
				++res2;
			}
		}
		printf("Case #%d: %d %d\n",k,res1,res2);
	}
	
    return 0;
}
