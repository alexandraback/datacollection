#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii > vii;
typedef queue<int> qi;
typedef set<int> si;

#define RE(i,b) for(int i=0; i<(int)(b); i++)
#define REP(i,a,b) for(int i=(a); i<(int)(b); i++)
#define BREP(i,a,b) for(int i=(a)-1; i>=(b); i--)
#define FE(i,X) for(typeof((X).begin()) i=(X).begin(); i!=(X).end(); ++i)

#define INF 1000000000
#define MP make_pair
#define FI first
#define SE second
template<class t> void setmin(t &a, t b){a=min(a,b);}

int B; LL M;
LL A[100];
bool X[100][100];

void dfs(int a);

void dfs2(int a, int i){
// 	printf("%d %d\n",a,i);
	if(i>=B){
		dfs(a+1);
		return;
	}
	A[i]+=A[a];
	X[a][i]=true;
	dfs2(a,i+1);
	A[i]-=A[a];
	X[a][i]=false;
	dfs2(a,i+1);
}

bool don;

void dfs(int a){
	if(don)
		return;
	if(a>=B-1){
		if(A[B-1]==M){
			printf("POSSIBLE\n");
			don=true;
			RE(g,B){
				RE(h,B){
					printf("%d",X[g][h]);
				}
				printf("\n");
			}
		}
		return;
	}
	dfs2(a,a+1);
}

int main(){
	int TC;scanf("%d ",&TC);
	RE(tc,TC){
		printf("Case #%d: ",tc+1);
		scanf("%d %lld ",&B,&M);
		don=false;
		A[0]=1;
		RE(g,100)RE(h,100)X[g][h]=0;
		dfs(0);
		if(!don)
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
