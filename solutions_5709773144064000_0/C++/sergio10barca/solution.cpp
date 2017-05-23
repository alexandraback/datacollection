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
#define MAX 4
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

double solve(double C, double F, double X){
	int cont = 0;
	double nuevo, mejor = X/2.0, suma = 2.0, parcial, llevo = 0.0;
	while(true){
		parcial = C/suma;
		suma += F;
		llevo += parcial;
		nuevo = llevo+(X/suma);
//		printf("%lf %lf %lf %lf %lf\n", parcial, llevo, suma, nuevo, mejor);
		if(nuevo < mejor)
			mejor = nuevo;
		else
			break;
		cont++;
	}
//	printf("%d\n", cont);
	return mejor;
}

int main(){
	int k, casos;
	double C, F, X;
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		scanf("%lf%lf%lf", &C, &F, &X);
		printf("Case #%d: %0.8lf\n", k, solve(C, F, X));
	}
	return 0;

}
