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
#define MAX 1010
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

double naomi[MAX], ken[MAX];

void imprime(int n, double v[]){
	for(int i = 0; i < n; i++)
		printf("%0.5lf%c", v[i], i == (n-1) ? '\n' : ' ');
	return;
}

int solve1(int n){
	int i, j, pts;
	char used[MAX];
//	set<int> q;
	sort(naomi, naomi+n);
	sort(ken, ken+n);
	memset(used, 0, sizeof(used));
	for(i = 0, pts = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(!used[j] && ken[j] > naomi[i]){
				used[j] = 1;
				break;
			}
		}
		if(j == n)
			pts++;
	}
	return pts;
}

bool gana(set<double> a, set<double> b){
	set<double>::iterator it, ij;
	for(it = a.begin(), ij = b.begin(); it != a.end(); it++, ij++){
		if((*it) < (*ij))
			return false;
	}
	return true;
}

int solve2(int n){
	set<double> na, ke;
	int i, j;
	for(i = 0; i < n; i++)
		na.insert(naomi[i]);
	for(i = 0; i < n; i++)
		ke.insert(ken[i]);
//	imprime(n, naomi);
//	imprime(n, ken);
	for(i = 0, j = n-1; i < n; i++, j--){
		if(gana(na, ke)){
			return na.size();
		}
		na.erase(na.begin());
		ke.erase(ken[j]);
	}//*/
	return 0;
}

void lee(int n, double v[]){
	int i;
	for(i = 0; i < n; i++)
		scanf("%lf", &v[i]);
	return;
}

int main(){
	int k, casos, n;
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		scanf("%d", &n);
		lee(n, naomi);
		lee(n, ken);
		printf("Case #%d: %d %d\n", k, solve2(n), solve1(n));
	}
	return 0;

}
