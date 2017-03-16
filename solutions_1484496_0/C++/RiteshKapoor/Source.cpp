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
		int A[501];
		map<ULONG, vector<int> > sum;
		scanf("%d",&N);
		FOR(i,0,N)scanf("%d",&A[i]);

		for(int C=1;C<(1<<20);C++){
			ULONG s=0;vector<int> set;
			for(int i=0,c=C;i<20;i++,c/=2){
				if(c%2==1){
					s+=A[i];
					set.push_back(A[i]);
				}
			}
			if(sum.find(s)!=sum.end()){
				printf("Case #%d:\n",tT+1);
				vector<int> f=sum[s];
				FOR(i,0,f.size())printf("%d ",f[i]);
				printf("\n");
				FOR(i,0,set.size())printf("%d ",set[i]);
				printf("\n");
				goto END;
			}
			sum[s]=set;
		}
		printf("Case #%d: Impossible\n",tT+1);	
		END:;
		//printf("Case #%d: %d\n",tT+1,L);		
	}
	
#ifdef _DEBUG 	
	printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}





