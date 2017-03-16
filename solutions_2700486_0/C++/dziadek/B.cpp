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
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair 
typedef long long ll;

int t,x,y,n;
double memo[1005][1005],res;

double calc(int a, int b){
	if(a<0) return 0;
	if(a==0 && b==0) return 1;
	if(a>b) return 0;
	if(memo[a][b]!=-1) return memo[a][b];
	//a sukcesow
	//b zdarzen
	double p=calc(a-1,b-1)+calc(a,b-1);
	memo[a][b]=p/2;
	return memo[a][b];
}

int main(){
	scanf("%d",&t);
	REP(i,t){
		scanf("%d%d%d",&n,&x,&y);
		int sum=abs(x)+y;
		sum/=2;
	
		if(n<=2*sum*sum-sum){
			res=0;
			goto print_result;
		}

		++sum;
		if(n>=2*sum*sum-sum){
			res=1;
			goto print_result;
		}
		
		--sum;
		n-=(2*sum*sum-sum);

		if(y>=n){
			res=0;
			goto print_result;
		}

		if(x==0){			
			res=0;
			goto print_result;
		}		

		if(n>=2*(sum+1)+y-1){
			res=1;
			goto print_result;
		}

		REP(j,n+1)
			REP(k,n+1) memo[j][k]=-1;

		res=0;
		FOR(j,y+1,n) res+=calc(j,n);

		print_result:
		printf("Case #%d: %lf\n",i+1,res);
	}
	return 0;
}

