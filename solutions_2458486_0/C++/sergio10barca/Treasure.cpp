#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 25
#define MOD 1000000007
#define INF 288230376151711744LL
using namespace std;

int vec8[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};// signo x+
int vec4[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};//signo +

void int_to_char(int n, char s[], int base = 10){
	int i = 0;
	do{
		s[i++] = (n%base)+'0';
		n /= base;
	}while(n > 0);
	reverse(s, s+i);
	return;
}

string int_to_string(int n, int base = 10){
	string s = "";
	int i = 0;
	do{
		s += char((n%base)+'0');
		n /= base;
	}while(n > 0);
	reverse(s.begin(), s.end());
	return s;
}

int gcd(int uno, int dos)/*calculo el maximo comun divisor*/
{
	if(dos == 0)
		return uno;
	return gcd(dos, uno%dos);/*si este es uno los numeros solo tienen a 1 como maximo comun divisor*/
}

int mcm(int x, int y)/*minimo comun multiplo*/
{
   return (x/gcd(x,y))*y;/*es mejor primero dividir para no desbordar*/
}

typedef long long int entero;
typedef pair<int, int> Point;

pair<int, int> dp[1048576];
int n, times, max_key, min_key, abre[MAX];
bool visita[MAX];
set<int> G[MAX];
set<int> q[MAX];
vector<int> llaves[MAX];
set<int> d[MAX*MAX];
int traigo[MAX*MAX], dp_abre[MAX*MAX];
vector<int> resp;

void imprime_G(){
	int i, j;
	set<int>::iterator it;
	for(i = 0; i <= n; i++){
		printf("%d:", i);
		for(it = G[i].begin(); it != G[i].end(); it++){
			printf(" %d", *it);
		}
		printf("\n");
	}
	return;
}

void Genera_graph(){
	int i, j, k;
	set<int> q;
	set<int>::iterator it;
	for(i = 0; i <= n; i++){
		for(j = 0; j < llaves[i].size(); j++){
			q = d[llaves[i][j]];
			for(it = q.begin(); it != q.end(); it++)
				if((*it) != i)
					G[i].insert(*it);
		}
	}
//	imprime_G();
	return;
}

bool DFS(int vertice, int faltan, int mask){
//	cout << "Estoy en "<< vertice << endl;
	times++;
	if(mask == 0){
		if(faltan != 0){
			cout << "wrong" << endl;
			exit(0);
		}
		return true;
	}
	int i, res, vec, cont;
	set<int>::iterator it;

	q[vertice].clear();
	for(it = G[vertice].begin(); it != G[vertice].end(); it++)
		q[vertice].insert(*it);
	for(i = min_key; i <= max_key; i++)
		if(traigo[i] > 0)
			for(it = d[i].begin(); it != d[i].end(); it++)
				q[vertice].insert(*it);
	
	for(it = q[vertice].begin(); it != q[vertice].end(); it++){
//		cout << "vertex " << vertice << " -> " << (*it) << endl;
		if(visita[*it]){
			visita[*it] = false;
			
			for(i = 0; i < llaves[*it].size(); i++)
				traigo[llaves[*it][i]]++;
				
			traigo[abre[*it]]--;
//			cout << "entra " << *it << endl;
			res = mask^(1<<((*it)-1));
//			cout << hex << " " << res << endl;
			vec = cont = 0;
			for(i = min_key; i <= max_key; i++)
				if(traigo[i]>0){
//					cout << i << " " << traigo[i] << endl;
					cont += traigo[i];
					vec |= dp_abre[i];
				}
/*			cout << "vec " << hex << vec << " " << res << " "<<dp[res].x << dec <<" "<<dp[res].y<< endl;
			cout << "cont = " << cont << endl;
			printf("%x %x\n", (vec&res), dp[res].x&res);
			system("pause");//*/
			if(((vec&res)|(dp[res].x&res)) == res && (cont+dp[res].y)>=(faltan-1) && times < 10000000){
				if(DFS(*it, faltan-1, res)){
					resp.push_back(*it);
					return true;
				}
			}
			
			traigo[abre[*it]]++;
			for(i = 0; i < llaves[*it].size(); i++)
				traigo[llaves[*it][i]]--;
				
			visita[*it] = true;
		}
	}
//	cout << "salir de vertice " << vertice << endl;
//	system("pause");//*/
	q[vertice].clear();
	return false;
}

bool Valida(int vertex){
	int i, cont = 0;
	queue<int> q;
	set<int>::iterator it;
	q.push(vertex);
	for(i = 0; i <= n; i++)
		visita[i] = true;
	visita[vertex] = false;
	while(!q.empty()){
		cont++;
		vertex = q.front();
		q.pop();
		for(it = G[vertex].begin(); it != G[vertex].end(); it++){
			if(visita[*it]){
				visita[*it] = false;
				q.push(*it);
			}
		}
	}
//	cout << cont << " " << n << endl;
	return cont > n;
}

void Genera_dp(){
	int a, b, vec, i, j, k = 1<<n, cont;
	char activa[MAX];
	set<int>::iterator it;
	set<int> q;
//	cout <<"dp = "<< n << " "<< hex << k << dec<<endl;
	for(i = 1; i < k; i++){
		j = i, vec = cont = 0;
		for(a = 0; j > 0; j>>=1, a++){
			if(j&1){
				for(it = G[a+1].begin(); it != G[a+1].end(); it++){
					vec = vec|(1<<((*it)-1));
				}
				cont += llaves[a+1].size();
			}
		}
//		cout<<dec << i << " "<< hex << vec <<" "<< dec << cont<< endl;
		dp[i] = Point(vec, cont);
	}
//	cout << dec << endl;
//	cout << "llaves" << endl;
	for(i = min_key; i <= max_key; i++){
		q = d[i];
		vec = cont = 0;
		for(it = q.begin(); it != q.end(); it++)
			vec = vec | (1<<((*it)-1));
		dp_abre[i] = vec;
//		cout<<dec << (*ij).x << " "<< hex << vec << endl;
	}
	return;
}

int main(){
	int i, j, a, m, k, casos, K, ans = 0, v[100];
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		times = 0;
		scanf("%d%d", &K, &n);
//		printf("%d %d\n", K, n);
		memset(traigo, 0, sizeof(traigo));
		max_key = -1000000, min_key = INT_MAX;
		for(i = 0; i < K; i++){
			scanf("%d", &v[i]);
//			printf("%d ", v[i]);
			llaves[0].push_back(v[i]);
			traigo[v[i]]++;
			max_key = max(max_key, v[i]);
			min_key = min(min_key, v[i]);
		}
//		printf("\n");
		for(i = 1; i <= n; i++){
			scanf("%d%d", &abre[i], &m);
			max_key = max(max_key, abre[i]);
			min_key = min(min_key, abre[i]);
//			printf("%d %d %d", i, abre[i], m);
			for(j = 0; j < m; j++){		
				scanf("%d", &a);
//				printf(" %d", a);
				llaves[i].push_back(a);
				max_key = max(max_key, a);
				min_key = min(min_key, a);
			}
//			printf("\n");
			d[abre[i]].insert(i);
		}
//		cout << min_key << " - " << max_key << endl;
		Genera_graph();
		if(Valida(0)){
			Genera_dp();
//			cout << "go " << endl;
			for(i = 0; i <= n; i++)
				visita[i] = true;
			DFS(0, n, (1<<n)-1);
		}
		if(resp.size() == 0)
			printf("Case #%d: IMPOSSIBLE\n", k);
		else{
			printf("Case #%d:", k);
			for(i = resp.size()-1; i >= 0; i--)
				printf(" %d", resp[i]);
			printf("\n");
		}
		for(i = min_key; i <= max_key; i++)
			d[i].clear();
		for(i = 0; i < MAX; i++)
			G[i].clear(), llaves[i].clear(), q[i].clear();
		resp.clear();
	}
	return 0;
}
