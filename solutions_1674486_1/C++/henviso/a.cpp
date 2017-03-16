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
#define MAX 1001

int grafo[MAX][MAX];
int grau[MAX];
int n;
bool flag[MAX];

bool bfs(int start)
{
	int fila[MAX];
	int ini = 0, fim = 0;
	CLEAR(flag);
	fila[fim++] = start;
	flag[start] = true;
	//cout << "COMECEI COM " << start << endl;
	while(ini != fim){

		int no = fila[ini++];
		
		for(int i = 0; i<grau[no]; i++)
		{
			int viz = grafo[no][i];
			//cout << " viz eh " << viz << endl;
			if(flag[viz]) return true;
			fila[fim++] = viz;
			flag[viz] = true;
		}

	}
	return false;
}


int main()
{
	int t, aux, tam;
	scanf(" %d ", &t);
	REP(ca, t){
		CLEAR(grau);
		scanf(" %d ", &n);
		REP(i, n){
			scanf(" %d ", &tam);
			REP(j, tam){
				scanf(" %d ", &aux);
				grafo[(i+1)][grau[i+1]++] = aux;
			}
		}
		/*cout << "GRAFO:\n";
		for(int i = 1; i<n; i++){
			cout << i << ": ";
			REP(j, grau[i]) cout << " " << grafo[i][j];
			cout << endl;
		}*/
		int i;
		for(i = 1; i<n; i++) if(bfs(i)) break;
		if(i != n) printf("Case #%d: Yes\n", ca+1);
		else printf("Case #%d: No\n", ca+1);
	}
}
