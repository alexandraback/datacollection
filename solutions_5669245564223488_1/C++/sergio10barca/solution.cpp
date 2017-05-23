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

vector<string> v;
entero fact[MAX];
int usado[MAX];

void genera(){
	entero i;
	fact[0] = fact[1] = 1;
	for(i = 2; i < MAX; i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
	return;
}

bool checa(string s){
	int i, j;
	char c = s[0];
	set<char> q;
	q.insert(c);
	i = 1;
	while(i < s.size()){
		if(c != s[i]){
			c = s[i];
			if(q.find(c) != q.end())
				return false;
			q.insert(c);
		}
		i++;
	}
	return true;
}

int concatena(char c, char d, deque<string> &r){
	int i, j;
	for(i = 0; i < v.size(); i++){
		if(v[i][0] == v[i][v[i].size()-1] && v[i][0] == c){
			r.push_front(v[i]);
			v.erase(v.begin()+i, v.begin()+i+1);
			return 1;
		}
		if(v[i][0] == v[i][v[i].size()-1] && v[i][0] == d){
			r.push_back(v[i]);
			v.erase(v.begin()+i, v.begin()+i+1);
			return 1;
		}
	}
	for(i = 0; i < v.size(); i++){
		if(v[i][v[i].size()-1] == c){
			for(j = 0; j < v[i].size(); j++)
				if(v[i][j] != c && usado[v[i][j]])
					return -1;
			for(j = 0; j < v[i].size(); j++)
				usado[v[i][j]] = 1;
			r.push_front(v[i]);
			v.erase(v.begin()+i, v.begin()+i+1);
			return 1;
		}
		if(v[i][0] == d){
			for(j = 0; j < v[i].size(); j++)
				if(v[i][j] != d && usado[v[i][j]])
					return -1;
			for(j = 0; j < v[i].size(); j++)
				usado[v[i][j]] = 1;
			r.push_back(v[i]);
			v.erase(v.begin()+i, v.begin()+i+1);
			return 1;
		}
	}
	return 0;
}

entero obtener(){
	entero resp = 1;
	string s = v[0];
	char c = s[0], d = s[s.size()-1];
	deque<string> r;
	int i, cont, k;
	for(i = 0; i < s.size(); i++)
		if(usado[s[i]]){
//			cout << "aqui" << endl;
			return -1;
		}
	for(i = 0; i < s.size(); i++)
		usado[s[i]] = 1;
	r.push_back(s);
	if(!checa(s)){
		return -1;
	}
	v.erase(v.begin(), v.begin()+1);
	while((k = concatena(c, d, r)) > 0){
//		cout << k << endl;
		s = r[r.size()-1];
		c = r[0][0], d = s[s.size()-1];
	}
	if(k < 0)
		return -1;
	for(i = 0; i < r.size(); i++){
		for(cont = 0; i < r.size() && r[i][0] == r[i][r[i].size()-1]; cont++, i++);
//			cout << r[i]<<" ";
/*		if(i<r.size())
		cout << r[i]<<" ";//*/
		resp *= fact[cont];
		resp %= MOD;
	}
//	cout << endl;
	return resp;
}

int solve(int n){
	int i, cont = 0;
	entero resp = 1;
	for(i = 0; i < v.size(); i++)
		if(!checa(v[i]))
			return 0;
	memset(usado, 0, sizeof(usado));
	while(v.size()>0){
		resp *= obtener();
		if(resp < 0)
			return 0;
		resp %= MOD;
		cont++;
//		cout << cont << endl;
	}
	return (resp*fact[cont])%MOD;
}

int main(){
	int i, j, n, k, casos;
	string s;
	genera();
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			cin >> s;
			v.push_back(s);
//			cout << s << " ";
		}
//		cout <<endl;
		printf("Case #%d: %d\n", k, solve(n));
		v.clear();
	}
	return 0;
}
