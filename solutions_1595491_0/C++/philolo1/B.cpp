#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

// defines
#define ll long long int
#define REP(a,b) for(int (a)=0;a<(int)b;a++)
#define FOR(a,b,c) for(int (a)=b;a<(int)c;a++)
#define MP(A,B) make_pair(A,B)
#define PB push_back
#define S(a) scanf("%d",&a);
#define SCH(a) scanf("%s",a);
#define foreach(a,b) for(__typeof(b).begin() a  = b.begin(); a != b.end();a++)
#define debug(a) cout<<a<<endl;
#define INIT(a) memset(a,0,sizeof(a))

using namespace std;

int dp[200][200];
int sum[100];
int N;
int P;

int Calc(int pos, int remain){
	if(remain<0) return -1000;
	
	if(pos==N){
		if(remain==0){
			return 0;
		}else{
			return -1000;
		}
	}
	
	if(dp[pos][remain]==-1){
		dp[pos][remain]=-1000;
		int val = sum[pos];
		
		bool less[] = {false,false};
		bool greater[] = {false,false};
		
		for(int a=0;3*a<=val;a++){			
			for(int b=0;b<=2;b++){
				for(int c=0;c<=2;c++){
					if(3*a+b+c==val){
						if(a+c<P){
							less[(b==2 || c==2)]=true;
						}else{
							greater[(b==2 || c==2)]=true;
						}
					}
				}
			}
		}
		
		if(less[0]){
			dp[pos][remain]=max(dp[pos][remain],Calc(pos+1,remain));
		}
		
		if(greater[0]){
			dp[pos][remain]=max(dp[pos][remain],1+Calc(pos+1,remain));
		}
		
		if(less[1]){
			dp[pos][remain]=max(dp[pos][remain],Calc(pos+1,remain-1));
		}
		
			
		if(greater[1]){
			dp[pos][remain]=max(dp[pos][remain],1+Calc(pos+1,remain-1));
		}
	}
	
	return dp[pos][remain];
	
	
}

int main(){
	int T;
	int S;

	S(T);
	
	FOR(t,1,T+1){
		memset(dp,-1,sizeof(dp));
		S(N);
		S(S);
		S(P);
		REP(n,N) S(sum[n]);
		
		 printf("Case #%d: %d\n",t,Calc(0,S));
	}
	
}
