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
#define MAX 100
#define MOD 1000000007
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;

int vec3[3][2] = {{-1, 0}, {-1, -1}, {0, -1}};// signo x+
int vec8[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};// signo x+
int vec4[4][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};//signo +

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

void imprime(vector<string> v){
	int i;
	for(i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return;
}


void agrega(int cuenta, int r, int c, vector<string> &v){
	int i, a, b;
	Point p;
	char m[MAX][MAX];
	memset(m, 0, sizeof(m));
	m[r-1][c-1] = m[r-1][c-2] = m[r-2][c-1] = m[r-2][c-2] = 1;
	queue<Point> q;
	q.push(Point(r-2, c-1));
	q.push(Point(r-2, c-2));
	q.push(Point(r-1, c-2));
	while(!q.empty()){
		p = q.front();
		q.pop();
		for(i = 0; i < 3 && cuenta > 0; i++){
			a = p.x+vec3[i][0], b = p.y+vec3[i][1];
			if(IN(a, r) && IN(b, c) && !m[a][b]){
				m[a][b]	= 1;
				v[a][b] = '.';
				q.push(Point(a, b));
				cuenta--;
//				cout << a << " " << b << endl;
			}
		}
	}
	return;
}

bool analiza(int r, int c, vector<string> v){
	int i, j, k, a, b, na, nb;
	char m[MAX][MAX];
	Point p;
	queue<Point> q;
	memset(m, 0, sizeof(m));
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++)
			if(v[i][j] == 'c'){
				for(k = 0; k < 8; k++){
					na = i+vec8[k][0], nb = j+vec8[k][1];
					if(IN(na, r) && IN(nb, c) && v[na][nb] == '*'){
						return false;
					}
				}
				q.push(Point(i, j));
				m[i][j] = 1;
				break;
			}
		if(j < c)
			break;
	}
	while(!q.empty()){
		p = q.front();
		q.pop();
//		printf("%d %d\n", p.x, p.y);
		for(i = 0; i < 8; i++){
			a = p.x+vec8[i][0], b = p.y+vec8[i][1];
			if(IN(a, r) && IN(b, c) && !m[a][b] && v[a][b] != '*'){
				m[a][b] = 1;
				for(j = 0; j < 8; j++){
					na = a+vec8[j][0], nb = b+vec8[j][1];
					if(IN(na, r) && IN(nb, c) && v[na][nb] == '*')
						break;
				}
				if(j == 8)
					q.push(Point(a, b));
			}
		}
	}
//	cout << minix << " - " << miniy << endl;

	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			if(v[i][j] == '.' && m[i][j] == 0){
//				imprime(v);
				return false;
			}
	return true;
}

void rellena(int i, int j, int r, int c, int cont, vector<string> &s){
	char m[MAX][MAX];
	queue<Point> q;
	q.push(Point(i, j));
	memset(m, 0, sizeof(m));
	m[i][j] = 1;
	while(!q.empty() && cont > 0){
		Point p = q.front();
		s[p.x][p.y] = '*';
		q.pop();
		if(r < c){
			if(IN(p.y+1, c) && !m[p.x][p.y+1]){
				m[p.x][p.y+1] = 1;
				q.push(Point(p.x, p.y+1));
			}
		}
		else{
			if(IN(p.x+1, r) && !m[p.x+1][p.y]){
				m[p.x+1][p.y] = 1;
				q.push(Point(p.x+1, p.y));
			}
			if(IN(p.y+1, c) && !m[p.x][p.y+1]){
				m[p.x][p.y+1] = 1;
				q.push(Point(p.x, p.y+1));
			}
		}
		cont--;
	}
	return;
}

vector<string> transforma(int r, int c, vector<string> s){
	int i, j, k, cont;
//	cout << "transforma" << endl;
	for(i = r-2; i >= 0 && s[i][c-1] == '.'; i--);
	i++;
	for(j = c-1; j >= 0 && s[i][j] == '.'; j--);
	j++;
	for(k = c-2; k >= 0 && s[r-1][k] == '.'; k--);
	k++;
	if(k < j){//esta arriba
//		cout << "arriba" << j << endl;
		for(j = k, cont = 0; j < c && s[i][j] == '*'; j++, cont++)
			s[i][j] = '.';
//		cout << cont << endl;
		j = k;
		rellena(i, j, r, c, cont, s);
	}
	else{//esta izquierda
//		cout << "izquierda "<<j << endl;
		for(i = r-1, cont = 0; i >= 0 && s[i][j] == '*'; i--, cont++)
			s[i][j] = '.';
//		cout << cont << endl;
		for(; i >= 0 && s[i][j] == '.'; i--);
		i++;
		rellena(i, j, r, c, cont, s);
	}
	return s;
}

vector<string> solve(int r, int c, int m){
	string s = "";
	vector<string> v;
	int i, x, y;
	for(i = 0; i < c; i++)
		s += char('*');
	if(r >= 2 && c >= 2){
		if(m == (r*c-1)){
			for(i = 0; i < r; i++)
				v.push_back(s);
			v[r-1][c-1] = 'c';
		}
		else if(m <= (r*c-4)){
			for(i = 0; i < r; i++)
				v.push_back(s);
			v[r-1][c-1] = 'c', v[r-2][c-1] = '.', v[r-1][c-2] = '.', v[r-2][c-2] = '.';
			agrega(r*c-4-m, r, c, v);
			imprime(v);
			if(analiza(r, c, v))
				return v;
			else{
				v = transforma(r, c, v);
				if(analiza(r, c, v))
					return v;
				v.clear();
				v.push_back("Impossible");
				return v;
			}
		}
		else{
			v.push_back("Impossible");
		}
	}
	else{
		for(i = 0; i < r; i++)
			v.push_back(s);
		v[r-1][c-1] = 'c';
		if(r == 1){
			for(i = m; i < (c-1); i++)
				v[0][i] = '.';
		}
		else{
			for(i = m; i < (r-1); i++)
				v[i][0] = '.';
		}
	}
	return v;
}

vector<string> bruta(int r, int c, int m){
	int a, b, i, j, k, cont, lim = 1<<(r*c);
	string s = "";
	for(i = 0; i < c; i++)
		s += char('*');
	vector<string> v;
	for(i = 0; i < r; i++)
		v.push_back(s);
	for(i = 0; i < lim; i++){
		for(j = i, cont = 0; j > 0; j>>=1)
			if((j&1))
				cont++;
		if(cont == m){
			for(a = r-1, j = i; a >= 0; a--)
				for(b = c-1; b >= 0; b--, j >>= 1){
					if(j&1)
						v[a][b] = '*';
					else
						v[a][b] = '.';
				}
//			cout << "cont = " << cont << " " << m << endl;
//			imprime(v);//*/
			for(a = 0; a < r; a++)
				for(b = 0; b < c; b++)
					if(v[a][b] == '.'){
//						cout << a << " ++ " << b << endl;
						v[a][b] = 'c';
						if(analiza(r, c, v) || (r*c-1) == m)
							return v;
						v[a][b] = '.';
					}
		}
	}
	v.clear();
	v.push_back("Impossible");
	return v;
}


int main(){
	int k, casos, r, c, m;
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", k);
//		imprime(solve(r, c, m));
		imprime(bruta(r, c, m));
	}
	return 0;

}
