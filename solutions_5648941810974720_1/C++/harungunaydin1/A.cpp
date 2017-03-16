#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end() 
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
vector < int > res;
int H[MAXN];
string letters[20] = { "ZERO" , "ONE" , "TWO" , "THREE" , "FOUR" , "FIVE" , "SIX" , "SEVEN" , "EIGHT" , "NINE" };
void handle(char c,int x) {

	int i,t = H[c];
	FOR(i,1,t)
		res.push_back(x);

	for( i = 0; i < letters[x].size(); i++ )
		H[ letters[x][i] ] -= t;

}
void solve() {

	string str;

	cin >> str;
	int i;
	for( i = 0; i < str.size(); i++ )
		H[ str[i] ]++;

	handle('Z',0);
	handle('W',2);
	handle('U',4);
	handle('F',5);
	handle('X',6);
	handle('V',7);
	handle('G',8);
	handle('R',3);
	handle('O',1);
	handle('E',9);

	sort( all(res) );
	for( vector < int > :: iterator it = res.begin(); it != res.end(); ++it )
		printf("%d" , *it );
	printf("\n");
	res.clear();

}
int main()
{
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout );
	int T = read() , i;
	FOR(i,1,T) {
		memset( H , 0 , sizeof H );
		printf("Case #%d: " , i );
		solve();
	}

	return 0;
}
