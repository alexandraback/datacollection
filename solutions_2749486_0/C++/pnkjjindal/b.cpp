/*
	Author: Pankaj Jindal
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <math.h>
#include <cassert>
#include <string.h>

using namespace std;

#define DEBUG if(0)

//Numberic Functions
template<class T> inline T gcd(T a, T b){
	if(a<0)return gcd(-a,b); if(b<0)return gcd(a,-b); return (b==0)?a:gcd(b,a%b);
}
template<class T> inline T lcm(T a, T b){
	if(a<0)return lcm(-a,b); if(b<0)return lcm(a,-b); return a*(b/gcd(a,b));
}
template<class T> inline T euclide(T a, T b, T &x, T &y){
	if(a<0){T d=euclide(-a,b,x,y); x=-x; return d;}
	if(b<0){T d=euclide(a,-b,x,y); y=-y; return d;}
	if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}
}

template<class T> inline bool isPrimeNumber(T n){
	if(n<=1)return false;for(T i=2;i*i<=n;i++) if(n%i==0) return false;return true;
}
template<class T> inline T eularFunction(T n){
	vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;
}

//Translator
bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
bool isDigit(char c){return c>='0' && c<='9';}
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for(int i = (int)(s); i < (int)(e); i++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define pb push_back
#define mp make_pair

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const double PT = acos(-1.0);
const double EPS = 1e-11;

#define MAXN 201
#define BUF 100
#define MAXT 510

int X, Y;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct jump
{
	int x;
	int y;
};

jump prev[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main(){
	int i, j, k, T, cnt;
	int px, py, pp;
	int nx, ny, np;

	char ans[MAXT];

	queue< pair<int , jump> > Q;
	pair<int , jump> t;
	jump temp;

	REP(i, MAXN)
		REP(j, MAXN)
			vis[i][j]=false;

	//precompute
	Q.push(mp(0, (jump){BUF, BUF}));
	prev[BUF][BUF] = (jump){BUF, BUF};
	vis[BUF][BUF] = true;

	while(!Q.empty()){
		t = Q.front();
		Q.pop();

		cnt = t.first;
		temp = t.second;

		px = temp.x, py = temp.y;

		for(j=0;j<4;j++){
			nx = px + dx[j]*(cnt+1);
			ny = py + dy[j]*(cnt+1);

			if(nx<MAXN and ny<MAXN and nx>=0 and ny>=0 and !vis[nx][ny]){
				vis[nx][ny] = true;
				prev[nx][ny] = (jump){px, py};
				Q.push(mp(cnt+1, (jump){nx, ny}));
			}
			
		}
	}

	scanf("%d", &T);

	REP(i, T){
		scanf("%d %d", &X, &Y);
		
		X+=BUF, Y+=BUF;
		j=0;
		while(X!=BUF or Y!=BUF){
			nx = prev[X][Y].x, ny = prev[X][Y].y;

			//printf("From %d %d to %d %d\n", X-BUF, Y-BUF, nx-BUF, ny-BUF);

			if(nx>X)
				ans[j++] = 'W';
			else if(nx<X)
				ans[j++] = 'E';
			else if(ny>Y)
				ans[j++] = 'S';
			else
				ans[j++] = 'N';
			X =nx, Y=ny;
		}

		printf("Case #%d: ", i+1);
		for(k=j-1; k>=0;k--)
			printf("%c", ans[k]);
		printf("\n");
		}

		//printf("Case %d: ", i+1);
	return 0;
}
