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

int t, n, tab[107], p, s;
int main(){
	scanf("%d",&t);
	REP(nr,t){
		printf("Case #%d: ",nr+1);
		scanf("%d%d%d",&n, &s, &p);
		int res = 0;
		REP(i, n){
		       scanf("%d",&tab[i]);
		       if (tab[i] >= max(p, 3*p-2)) res++;
		       else if (s && tab[i] >= max(p, 3*p-4)){
			       res++;
			       s--;
		       }
		}
		printf("%d\n", res);
	}
}
