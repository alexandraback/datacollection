#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
#include<climits>
#include <string>
#include <sstream>

typedef unsigned long long int ULONG;
typedef long long int LONG;
typedef unsigned int UINT;

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)

#ifndef ONLINE_JUDGE
#include <time.h>
#endif

#include<stdio.h>
#include<iostream>
#include<math.h>

map<int,int> M;
vector< vector<int> >C;
int DFS(int N){
	N--;	
	if(M[N]==1)return 1;	
	M[N]=1;
	FOR(i,0,C[N].size()){
		if(DFS(C[N][i])==1)return 1;
	}
	return 0;
}

int main(){
	freopen("input.in","r",stdin);
#ifndef _DEBUG 
	freopen ("output.txt","w",stdout);
#endif
	clock_t start = clock();
		
	int T;
	scanf("%d",&T);	
	FOR(tT,0,T){
		int N;
		C.clear();
		scanf("%d",&N);
		FOR(i,0,N){
			int M,m;
			vector<int> I;
			scanf("%d",&M);
			FOR(j,0,M){
				scanf("%d",&m);
				I.push_back(m);
			}
			C.push_back(I);
		}

		FOR(i,1,N+1){
			M.clear();
			if(DFS(i)==1){
				printf("Case #%d: Yes\n",tT+1);
				goto END;
			}
		}
		printf("Case #%d: No\n",tT+1);
		END:;

	}
	//printf("Case #%d: ",tT+1);
	
#ifdef _DEBUG 	
	printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}






