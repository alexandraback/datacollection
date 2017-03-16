#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long double real;

///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = a; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define MOD 100
#define INCMOD(a,b) a = (a+b)%MOD
#define DECMOD(a,b) a = (a+MOD-1)%mod
#define ROUNDINT(a) (int)((double)a + 0.5)
#define INF 2000000000
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)

unsigned long long int a[101];
unsigned long long int b[101];
int A[101];
int B[101];
unsigned long long int dp[101][101];
int n, m;

void solve(){
	CLEAR(dp);
	for(int i = 1; i<n+1; i++){
		for(int j = 1; j<m+1; j++){
			dp[i][j] = dp[i-1][j];
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
			unsigned long long int novo = dp[i-1][j-1];
			if(A[i] == B[j]) novo += (a[i] < b[j]) ? a[i] : b[j];
			dp[i][j] = max(dp[i][j], novo);
		}
	}
	
	/*
	cout << "MAT: \n";
	REP(i, n+1){
		REP(j, m+1) cout << dp[i][j] << " ";
		cout << endl;
	}*/
}
	

int main()
{
	long long unsigned int t, num, lastnum;
	int type, lasttype, dec, rn, rm;
	scanf(" %llu ", &t);
	REP(ca, t){
		scanf(" %d %d ", &n, &m);
		lastnum = lasttype = 0;
		
		REP(i, n){
			scanf(" %llu %d ", &num, &type);
			if(type == lasttype){
				a[i] += num;
				n--;	
				i--;
			}
			else{
				a[i+1] = num;
				A[i+1] = type;
			}
			lasttype = type;
		}

		lasttype = 0;
		REP(i, m){
			scanf(" %llu %d ", &num, &type);
			if(type == lasttype){
				b[i] += num;
				m--;	
				i--;
			}
			else{
				b[i+1] = num;
				B[i+1] = type;
			}
			lasttype = type;
		}
		solve();
		printf("Case #%d: %llu\n", ca+1, dp[n][m]);
	}
}
