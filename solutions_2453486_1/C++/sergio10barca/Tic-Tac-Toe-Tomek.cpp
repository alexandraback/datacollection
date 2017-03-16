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

string s[4];

bool win(char c){
	int i, j, k[2];
	for(i = 0; i < 4; i++){
		for(j = k[0] = k[1] = 0; j < 4; j++){
			if(s[i][j] == c || s[i][j] == 'T')
				k[0]++;
			if(s[j][i] == c || s[j][i] == 'T')
				k[1]++;
		}
		if(k[0] == 4 || k[1] == 4)
			return true;
	}
	k[0] = k[1] = 0;
	for(i = 0, j = 3; i < 4; i++, j--){
		if(s[i][i] == c || s[i][i] == 'T')
			k[0]++;
		if(s[i][j] == c || s[i][j] == 'T')
			k[1]++;
	}
	if(k[0] == 4 || k[1] == 4)
		return true;
	return false;
}

int main(){
	int i, j, k, casos;
	bool ganaX, ganaO, full;
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		full = true;
		for(i = 0; i < 4; i++){
			cin >> s[i];
			for(j = 0; j < 4; j++)
				if(s[i][j] == '.')
					full = false;
		}
		ganaX = win('X');
		ganaO = win('O');
		if(ganaX == ganaO){
			if(full || ganaX)
				printf("Case #%d: Draw\n", k);
			else
				printf("Case #%d: Game has not completed\n", k);
		}
		else if(ganaX)
			printf("Case #%d: X won\n", k);
		else
			printf("Case #%d: O won\n", k);
	}
	return 0;
}
