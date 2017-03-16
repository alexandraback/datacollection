//Jakub Sygnowski
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
//#include<gmp.h> // http://gmplib.org/
//#include<gmpxx.h>
using namespace std;
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define ST first
#define ND second
#define INF 1000000007
#define PB push_back
#define MP make_pair
typedef pair<int,int> PII;
typedef long long LL;

int t, n;
char line[142];
char mapping[256];
int main(){
	scanf("%d\n",&t);
mapping['e'] = 'o';
mapping['j'] = 'u';
mapping['p'] = 'r';
mapping[' '] = ' ';
mapping['m'] = 'l';
mapping['y'] = 'a';
mapping['s'] = 'n';
mapping['l'] = 'g';
mapping['j'] = 'u';
mapping['y'] = 'a';
mapping['l'] = 'g';
mapping['c'] = 'e';
mapping[' '] = ' ';
mapping['k'] = 'i';
mapping['d'] = 's';
mapping[' '] = ' ';
mapping['k'] = 'i';
mapping['x'] = 'm';
mapping['v'] = 'p';
mapping['e'] = 'o';
mapping['d'] = 's';
mapping['d'] = 's';
mapping['k'] = 'i';
mapping['n'] = 'b';
mapping['m'] = 'l';
mapping['c'] = 'e';
mapping[' '] = ' ';
mapping['r'] = 't';
mapping['e'] = 'o';
mapping[' '] = ' ';
mapping['j'] = 'u';
mapping['s'] = 'n';
mapping['i'] = 'd';
mapping['c'] = 'e';
mapping['p'] = 'r';
mapping['d'] = 's';
mapping['r'] = 't';
mapping['y'] = 'a';
mapping['s'] = 'n';
mapping['i'] = 'd';
mapping['r'] = 't';
mapping['b'] = 'h';
mapping['c'] = 'e';
mapping['p'] = 'r';
mapping['c'] = 'e';
mapping[' '] = ' ';
mapping['y'] = 'a';
mapping['p'] = 'r';
mapping['c'] = 'e';
mapping[' '] = ' ';
mapping['r'] = 't';
mapping['t'] = 'w';
mapping['c'] = 'e';
mapping['s'] = 'n';
mapping['r'] = 't';
mapping['a'] = 'y';
mapping[' '] = ' ';
mapping['d'] = 's';
mapping['k'] = 'i';
mapping['h'] = 'x';
mapping[' '] = ' ';
mapping['w'] = 'f';
mapping['y'] = 'a';
mapping['f'] = 'c';
mapping['r'] = 't';
mapping['e'] = 'o';
mapping['p'] = 'r';
mapping['k'] = 'i';
mapping['y'] = 'a';
mapping['m'] = 'l';
mapping[' '] = ' ';
mapping['v'] = 'p';
mapping['e'] = 'o';
mapping['d'] = 's';
mapping['d'] = 's';
mapping['k'] = 'i';
mapping['n'] = 'b';
mapping['k'] = 'i';
mapping['m'] = 'l';
mapping['k'] = 'i';
mapping['r'] = 't';
mapping['k'] = 'i';
mapping['c'] = 'e';
mapping['d'] = 's';
mapping['d'] = 's';
mapping['e'] = 'o';
mapping[' '] = ' ';
mapping['k'] = 'i';
mapping['r'] = 't';
mapping[' '] = ' ';
mapping['k'] = 'i';
mapping['d'] = 's';
mapping[' '] = ' ';
mapping['e'] = 'o';
mapping['o'] = 'k';
mapping['y'] = 'a';
mapping['a'] = 'y';
mapping[' '] = ' ';
mapping['k'] = 'i';
mapping['w'] = 'f';
mapping[' '] = ' ';
mapping['a'] = 'y';
mapping['e'] = 'o';
mapping['j'] = 'u';
mapping[' '] = ' ';
mapping['t'] = 'w';
mapping['y'] = 'a';
mapping['s'] = 'n';
mapping['r'] = 't';
mapping[' '] = ' ';
mapping['r'] = 't';
mapping['e'] = 'o';
mapping[' '] = ' ';
mapping['u'] = 'j';
mapping['j'] = 'u';
mapping['d'] = 's';
mapping['r'] = 't';
mapping[' '] = ' ';
mapping['l'] = 'g';
mapping['k'] = 'i';
mapping['g'] = 'v';
mapping['c'] = 'e';
mapping[' '] = ' ';
mapping['j'] = 'u';
mapping['v'] = 'p';
mapping['q'] = 'z';
mapping['z'] = 'q';
	REP(nr,t){
		printf("Case #%d: ",nr+1);
		gets(line);
		n = strlen(line);
		for(int i = 0; i < n;i++){
			printf("%c",mapping[line[i]]);
		}
		printf("\n");
	}
}
