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
#define MAX 10100
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

int e, n, r, v[MAX], dp[MAX][12];

int rec(int i, int tengo){
//	cout << i << " " << tengo << endl;
	if(dp[i][tengo] < 0){
		if(i == n)
			return dp[i][tengo] = 0;
		if(tengo > e)
			tengo = e;
		int j, lim = min(tengo, e), maxi = 0;
		for(j = 0; j <= lim; j++){
			maxi = max(maxi, (rec(i+1, lim-j+r)+v[i]*j));
		}
		return dp[i][tengo] = maxi;
	}
	return dp[i][tengo];
}

int main(){
	int i, k, casos, resp;
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		scanf("%d%d%d", &e, &r, &n);
		memset(dp, -1, sizeof(dp));
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);
		resp = rec(0, e);
		printf("Case #%d: %d\n", k, resp);
	}
	return 0;
}
