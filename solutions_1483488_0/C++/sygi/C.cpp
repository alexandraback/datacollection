//Jakub Sygnowski
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
//#include<gmp.h> // http://gmplib.org/
//#include<gmpxx.h>
using namespace std;
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define ST first
#define ND second
#define INF 1000000007
#define PB push_back
#define MP make_pair
typedef pair<int,int> PII;
typedef long long LL;

int t, n, a, b, dzies;
long long res;
int len(int x){
	int rs = 0;
	while(x){
		rs++;
		x/=10;
	}
	return rs;
}
vector<int> jakie;
int ile(int x){
	jakie.clear();
	int rs = 0, c = x;
	for(int i = 0; i< n ; i++){
		jakie.PB(c);
		c+=dzies * (c%10); c/=10;
		if (jakie.back() < a || jakie.back() > b) jakie.pop_back();
		for(int j = 0; j < jakie.size() -1 ; j++){
			if (jakie[j] == jakie.back()){
				jakie.pop_back();
				break;
			}
		}
	}
//	sort(ALL(jakie)); jakie.resize(unique(ALL(jakie))-jakie.begin());
//	rs = -1;
//	printf("permutacje %d : ", x);
//	REP(i, jakie.size()) printf("%d ",jakie[i]);
///	printf("\n");
//	for(int i = 0; i < jakie.size(); i++){
//		if (jakie[i] >=a && jakie[i]<=b)
//			rs++;
//	}
	rs = jakie.size()-1;
//	printf("ile %d -> %d\n",x , rs);
	return rs;
}
int main(){
	scanf("%d",&t);
	REP(nr,t){
		printf("Case #%d: ",nr+1);
		scanf("%d%d",&a,&b);
		n = len(a);
		dzies = 1; REP(i, n) dzies*=10;
		res = 0;
		for(int i = a; i<=b;i++){
			res += ile(i);	
		}
		printf("%lld\n", res/2);
	}
}
