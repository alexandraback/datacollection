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
#define MAX 110
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

int n, m, v[MAX][MAX], o[MAX][MAX];
int u[MAX][MAX];

void Imprime(int c[MAX][MAX]){
	int i, j;
	cout << "Va la impresion" << endl;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
	return;
}

void solve(int cortar){
	int i, j, cont;
	memset(u, 0, sizeof(u));
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(cortar < v[i][j])
				break;
		}
		if(j == m)
			for(j = 0; j < m; j++) o[i][j] = cortar;
	}
	for(j = 0; j < m; j++){
		for(i = 0; i < n; i++){
			if(cortar < v[i][j])
				break;
		}
		if(i == n)
			for(i = 0; i < n; i++) o[i][j] = cortar;
	}
	return;
}

bool iguales(){
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(v[i][j] != o[i][j])
				return false;
	return true;
}

int main(){
	int i, j, k, casos;
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++)	
			for(j = 0; j < m; j++){
				scanf("%d", &v[i][j]);
				o[i][j] = 100;
			}
		for(i = 99; i > 0; i--){
			solve(i);
		}
//		Imprime(o);
		if(iguales())
			printf("Case #%d: YES\n", k);
		else
			printf("Case #%d: NO\n", k);
	}
	return 0;
}
