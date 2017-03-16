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

int p[210];

int main()
{
	int t, n, ca = 0, total;
	double sum, sum2, aux;
	double parc;
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d ", &n);
		sum = 0.0;
		total = n;
		
		REP(i, n){
			scanf(" %d ", &p[i]);
			sum += (double) p[i];
		}
		
		parc = (2*sum)/total;

			//cout << " PRIM PARC " << parc << endl;
		sum2 = sum;

		int ind = 0;
		while(ind < n){
			for(ind = 0; ind<n; ind++){
				if(p[ind] > parc){
					sum2 -= p[ind];
					p[ind] = -1;
					parc = (sum+sum2)/total;
					total--;
				}
			}
		}

		parc = (sum+sum2)/total;
		//cout << "PARC " << parc << endl;
		printf("Case #%d:", ++ca);
		REP(i, n){
			if(p[i] == -1) aux = 0.0;
			else{
				//cout << " PARA " << i << "(parc - p[i])" << (parc - p[i]);
				aux = ((parc - p[i])) / ((double) sum);
			}
			
			printf(" %.6lf", 100*aux);
		}
		printf("\n");
	}
}
