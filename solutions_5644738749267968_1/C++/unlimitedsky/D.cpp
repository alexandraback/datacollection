//Template for Dev-C++ 5.3.0.4 by unlimitedsky
//2013 March 4 20:58 (UTC +07.00)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FOR(i,a,b,c) for (int i = a; i <= b; i+=c)
#define FORR(i,a,b,c) for (int i = a; i >= b; i-=c)
#define INC(i,a,b) for (int i = a; i <= b; i++)
#define DEC(i,a,b) for (int i = a; i >= b; i--)
#define MP make_pair
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a)
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int tc, n, co, ce, seth, gilbert;
double naomi[10000], ken[10000];

int main(){
	scanf("%d", &tc);
	INC(i,1,tc){
		scanf("%d", &n);
		INC(j,1,n){
			scanf("%lf", &naomi[j]);
		}
		INC(j,1,n){
			scanf("%lf", &ken[j]);
		}
		sort(naomi+1, naomi+n+1);
		sort(ken+1, ken+n+1);
		/*
		DEC(i,n,1){
			printf("%.3lf %.3lf\n", naomi[i], ken[i]);
		}
		*/
		ce = co = n;
		seth = 0;
		while (ce > 0 && co > 0){
//			printf("%d %d\n", ce, co);
			if (naomi[ce] > ken[co]) ce--;
			else{
				seth++;
				ce--;
				co--;
			}
		}
		ce = co = n;
		gilbert = 0;
		while (ce > 0 && co > 0){
//			printf("%d %d\n", ce, co);
			if (naomi[ce] < ken[co]){
				gilbert++;
				co--;
			}
			else{
				ce--;
				co--;
			}
		}
		
		printf("Case #%d: %d %d\n", i, n-gilbert, n-seth);
	}
	
	return 0;
}
