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

bool analiza(int r, int c, vector<string> v){
	int i, j, k, a, b, na, nb, cont = 0;
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

vector<string> genera(int r, int c, int m){
	int i, j;
	string s = "";
	for(i = 0; i < c; i++)
		s += ".";
	vector<string> v;
	for(i = 0; i < r; i++)
		v.push_back(s);
	for(i = 0; i < (r-2); i++){
		for(j = 0; j < (c-2) && m > 0; j++, m--){
			v[i][j] = '*';
		}
	}
	if(m&1){
//		cout << "Pendiente "<<m << endl;
		for(i = 0; i < (r-3) && m > 1; i++, m-=2)
			v[i][c-2] = v[i][c-1] = '*';
		if(m == 1){
			v[r-3][c-3] = '.';
			if(c > 3)
				v[r-1][0] = v[r-2][0] = '*';
			else
				v[i][c-1] = v[i][c-2] = '*';
			v[r-1][c-1] = 'c';
		}
		else{
			for(j = 0; j < c && m > 1; j++, m-=2)
				v[r-1][j] = v[r-2][j] = '*';
			v[r-3][c-3] = '.';
			v[r-2][j] = v[r-1][j] = '*';
			m = 0;
//			cout << m << endl;
			v[r-1][c-1] = 'c';
		}
//		imprime(v);
		if(!analiza(r, c, v)){
			cout << "error" << endl;
			exit(0);
		}
	}
	else{
		for(i = 0; i < (r-2) && m > 0; i++, m-=2)
			v[i][c-2] = v[i][c-1] = '*';
		for(j = 0; j < c && m > 0; j++, m-=2)
			v[r-1][j] = v[r-2][j] = '*';
		v[r-1][c-1] = 'c';
//		imprime(v);
		if(!analiza(r, c, v)){
			cout << "Error" << endl;
			exit(0);
		}
	}
	return v;
}

vector<string> solve(int r, int c, int m){
	string s = "", t = "";
	vector<string> v;
	int i, j, minas = m;
	for(i = 0; i < c; i++)
		s += char('*'), t += ".";
	if((r*c-1) == m){
		for(i = 0; i < r; i++)
			v.push_back(s);
		v[r-1][c-1] = 'c';
		return v;
	}
	else if(r >= 2 && c >= 2 && (r == 2 || c == 2)){
		for(i = 0; i < r; i++)
			v.push_back(t);
		if(r == 2){
			for(j = 0; j < c && minas > 0; j++){
				for(i = 0; i < r && minas > 0; i++, minas--){
					v[i][j] = '*';
				}
			}
			v[r-1][c-1] = 'c';
			if(analiza(r, c, v) || (r*c-1) == m)
				return v;
			v.clear();
			v.push_back("Impossible");
			return v;
		}
		else{
			for(i = 0; i < r && minas > 0; i++){
				for(j = 0; j < c && minas > 0; j++, minas--){
					v[i][j] = '*';
				}
			}
			v[r-1][c-1] = 'c';
			if(analiza(r, c, v) || (r*c-1) == m)
				return v;
			v.clear();
			v.push_back("Impossible");
			return v;
		}
	}
	else if(r > 2 && c > 2){
		if((r*c-7) == m || (r*c-5) == m || (r*c-3) == m || (r*c-2) == m){
			v.push_back("Impossible");
			return v;
		}
		else{
			return genera(r, c, m);
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
	vector<string> u, v;
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", k);
		imprime(u = solve(r, c, m));
//		printf("%d %d %d\n", r, c, m);
/*		imprime(v = bruta(r, c, m));
		if(v[0] == "Impossible"){
			if(v != u){
				cout << "Error" << endl;
				exit(1);
			}
		}//*/
	}
	return 0;

}
