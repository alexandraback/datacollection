#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long double real;

///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = a; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define MOD 100
#define INCMOD(a,b) a = (a+b)%MOD
#define DECMOD(a,b) a = (a+MOD-1)%mod
#define ROUNDINT(a) (int)((double)a + 0.5)
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)

char aux[8], ns[8], *last;
int a, b, n; 

int reverse()
{
	//cout << "LAST EH " << &ns[7]-last << endl;
	//cout << "TENTANDO COM " << n << endl;
	//cout << "STRING RECEBIDA: ";
	//for(char *i = last+1; i<&ns[7]; i++) putchar(*i);
	//putchar('\n');
	int num, res = 0;
	int tam = (&ns[6] - last);
	int lim = tam-1;
	tr1::unordered_map<int, bool> used;
	REP(i, lim){
		int pos = 0;
		REPD(j, i+1) aux[pos++] = ns[6-j];
		char *c = last+1;
		while(c != &ns[6-i]){
			aux[pos++] = *c;
			c++;
		}
		aux[pos] = '\0';
		num = atoi(aux);
		
		if(num > n && num >= a && num <= b){
			//cout << num << endl;
			//v.push_back(make_pair(n,num));
			if(used.count(num) == 0){
				used[num] = true;
				res++;
			}
		}
	}
	return res;
}
		
	
void toString(int i, char *is){
	int pos = 6;
	is[7] = '\0';
	while(i){
		is[pos--] = (i%10)+'0';
		i /= 10;
	}
	last = &is[pos];
}

int main()
{
	int t, rev, ca = 0;
	unsigned long long int res = 0;
	scanf(" %d ", &t);
	while(t--){
		res = 0;
		scanf(" %d %d ", &a, &b);
		toString(a, ns);

		for(n = a; n<b; n++){
	
			rev = reverse();
			res += rev;
			//if(rev) cout << res << endl;

			char *pos = &ns[6];
			while(*pos == '9') *(pos--) = 0+'0';

			if(pos == last){
				*(pos) = 1;
				last--;
			}
			else{
				(*pos)++;
			}
		}
		//sort(v.begin(), v.end());
		//REP(z, v.size()) cout << "(" << v[z].first << "," << v[z].second << ")" << endl;
		printf("Case #%d: %lld\n", ++ca, res);

	}
}
