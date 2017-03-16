#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
#include<cmath>
#include<utility>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#define MAX 1000005
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair 

int motes[MAX],t,n,res,moves;
long long A;

int main(){
	scanf("%d",&t);
	REP(i,t){
		scanf("%lld%d",&A,&n);
		res=n;
		moves=0;

		REP(j,n) scanf("%d",&motes[j]);
		sort(motes,motes+n);

		int j=0;
		while(j<n){
			if(A>motes[j]){
				A+=motes[j];
				++j;
				res=min(res,moves+n-j);
			}
			else{
				if(A==1) break;
				A+=(A-1);
				++moves;
			}
		}	
		printf("Case #%d: %d\n",i+1,res);
	}
	return 0;
}

