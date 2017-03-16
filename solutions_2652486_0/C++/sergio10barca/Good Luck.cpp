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
#define MAX 101000
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

int p[MAX][100];
int r, n, m, k, cont;
string v[MAX];
map<int, set<string> > dp;


string cad = "23456789";

void rec(int i, string t){
//	cout << i << " " << tengo << endl;
	if(i == n){
		 v[cont++] = t;
		return;
	}
	int j;
	for(j = 0; j < m; j++)
		rec(i+1, t+cad[j]);
	return;
}

void generate(){
	int a, b, i, j, lim =(1<<n), prod;
	set<string> q;
	cont = 0;
	rec(0, "");
//	cout <<"lim = " <<lim << endl;
	for(i = 0; i < cont; i++){
//		cout << v[i] << endl;
		for(j = 0; j < lim; j++){
			for(a = j, p[i][j] = 1, b = 0; a > 0; a>>=1, b++){
				if(a&1){
					p[i][j] *= (v[i][b]-'0');
				}
			}
//			cout << p[i][j] << " ";
			if(dp.find(p[i][j]) == dp.end()){
				dp[p[i][j]] = q;
			}
			dp[p[i][j]].insert(v[i]);
		}
//		cout << endl;
	}
	return;
}


int main(){
	int i, j, k, casos, resp, valor;
	string ss, antes;
	set<string> q, ans, aux;
	set<string>::iterator it;
	map<string, int> veces, previos;
	map<string, int>::iterator ij;
	scanf("%d", &casos);
	printf("Case #1:\n");
	scanf("%d%d%d%d", &r, &n, &m, &k);
	m--;
	generate();
	antes = cad.substr(0, m);
//	cout << "antes = " << antes << endl;
	for(i = 1; i <= r; i++){
		q.clear();
		for(j = 0; j < cont; j++)
			q.insert(v[j]);
		for(j = 0; j < k; j++){
			scanf("%d", &valor);
//			cout << "paso j = " << j << endl;
			if(valor != 1 && dp.find(valor) != dp.end()){
				aux = dp[valor];
				ans.clear();
				for(it = aux.begin(); it != aux.end(); it++){
//					cout << " " << (*it);
					if(q.find(*it) != q.end()){
//						cout << " ok -> ";
						ans.insert(*it);
					}
/*					else
						cout << " -> ";//*/
				}
				q = ans;
//				cout << endl;
			}
		}
//		cout << "van" << endl;
		for(it = ans.begin(), resp = 0; it != ans.end(); it++){
//			cout << (*it) << " ";
			ss = (*it);
			sort(ss.begin(), ss.end());
			veces[ss]++;
			if(veces[ss]>resp){
				resp = veces[ss];
				antes = ss;
			}
		}
		cout << antes << endl;
//		cout << endl;
		veces.clear();
		ans.clear();
	}
	return 0;
}
