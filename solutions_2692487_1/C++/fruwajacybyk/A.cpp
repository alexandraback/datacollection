#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define pb push_back

int x[105];
int ile[105];

int main(){
	int z; scanf("%d",&z);
	FOR(test,1,z+1){
		int A,N;
		scanf("%d%d",&A,&N);
		FOR(i,0,N) scanf("%d",&x[i]);
		sort(x,x+N);
		if(A==1){
			printf("Case #%d: %d\n",test,N);			
			continue;
		}
		FOR(i,0,N) ile[i]=0;
		int akt = A;
		int ilruch = 0;
		FOR(i,0,N){
			while(akt<=x[i]){
				akt=2*akt-1; ilruch++;
			}
			akt+=x[i];
			ile[i]=ilruch;
		}
		int best = N;
		FOR(i,0,N){
			best = min(best,(N-i-1)+ile[i]);
		}
		printf("Case #%d: %d\n",test,best);	
		

	}
	return 0;
}
