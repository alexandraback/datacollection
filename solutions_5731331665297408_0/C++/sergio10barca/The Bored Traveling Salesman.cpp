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
#define MAX 51
#define MOD 1000000007
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;

int vec8[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};// signo x+
int vec4[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};//signo +

string int_to_string(int n, int base = 10){
	string s = "";
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

int Orientacion(Point p, Point q, Point r){
	//devuelve negativo si la orientacion es en el sentido de las manecillas del reloj es decir negativa
    return (q.x*r.y + r.x*p.y + p.x*q.y) - (q.x*p.y + r.x*q.y + p.x*r.y);
}

string val[MAX];
int mat[MAX][MAX];
int in[MAX], vis[MAX], ida[MAX];
set<Point> q;
map<Point, int> dic;

bool puede(int origen, int destino, int n){
	int i, j;
//	cout << origen << " " << destino << endl;
	if(mat[origen][destino] == 1 && in[destino] == 0){
		dic[Point(destino, origen)] = 1;
		in[destino] = 1;
		ida[destino] = 0;
		return true;
	}
	for(i = 1; i <= n; i++){
//		cout << "or " << origen << " " << i << " " << (q.find(Point(i, origen)) != q.end()) << endl;
		if(i != origen && mat[origen][i] && in[i] && !vis[i] && dic.find(Point(i, origen)) != dic.end() && dic[Point(i, origen)]>0){
			vis[i] = 1;
			dic[Point(i, origen)] = 0;
			if(puede(i, destino, n))
				return true;
			dic[Point(i, origen)] = 1;
		}
	}
	return false;
}

string solve(int n){
	int i, j, v[MAX];
	string s = "", minima = "", t;
	for(i = 1; i < MAX; i++)
		v[i-1] = i;
	do{
		memset(in, 0, sizeof(in));
		in[v[0]] = 1;
		s = val[v[0]];
		for(j = 1; j <= n; j++)
			ida[j] = 1;
		q.clear();
		dic.clear();
		for(j = 1; j < n; j++){
			memset(vis, 0, sizeof(vis));
			vis[v[j-1]] = 1;
//			cout << "ir de "<< v[j-1] << " " << v[j] << endl;
			if(puede(v[j-1], v[j], n))
				s+=val[v[j]];
			else
				break;
		}
/*		cout << "puede j " << j << " " << (j == n) << endl;
		for(int k = 0; k < n; k++)
			printf("%d%c", v[k], k == (n-1) ? '\n' : ' ' );//*/
		if(j >= n){
//			cout << s << endl;//*/
			if(minima == ""){
				minima = s;
			}
			minima = min(minima, s);
		}
	}while(next_permutation(v, v+n));
	return minima;
}

int main(){
	int i, j, a, b, n, m, casos;
	scanf("%d", &casos);
	for(i = 0; i < casos; i++){
		scanf("%d%d", &n, &m);
		memset(mat, 0, sizeof(mat));
		for(j = 1; j <= n; j++){
			cin >> val[j];
		}
		for(j = 0; j < m; j++){
			scanf("%d%d", &a, &b);
			mat[a][b] = mat[b][a] = 1;
		}
		printf("Case #%d: %s\n", i+1, solve(n).c_str());
	}
	return 0;
}
