// Author : Muhammad Rifayat Samee
// Problem :
// Algorithm:
#pragma warning (disable : 4786)
#pragma comment(linker, "/STACK:16777216")

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define INF 987654321
#define pi (2*acos(0.0))
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define i64 long long
#else
#define i64 __int64
#endif

using namespace std;
int graph[105][105];
int n,m;
int main(){

	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	int cases,i,j,k,ff,ct=1;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&graph[i][j]);
			}
		}
		int res = 1;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				ff = 0;
				for(k=0;k<n;k++){
					if(graph[k][j]>graph[i][j]){
						break;
					}
				}
				if(k==n)ff = 1;
				for(k=0;k<m;k++){
					if(graph[i][k]>graph[i][j]){
						break;
					}
				}
				if(k==m)ff = 1;
				
				if(ff == 0){
					res = 0;
					break;
				}
			}
			if(res == 0)break;
		}
		if(res)
			printf("Case #%d: YES\n",ct++);
		else
			printf("Case #%d: NO\n",ct++);
	}
	return 0;
}
