#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <numeric>
#include <queue>
#define f(i,x,y) for(int i = x;i<y; i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
#define FOR(it,A) for (typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(),(v).end()
#define rall(V) (v).rbegin(),(v).rend()
#define oo (1<<30)
#define eps (1e-9)
#define pb push_back
#define clr(A,x) memset(A,x,sizeof(A))
#define ones(x) __builtin_popcount (x)
#define cua(x) (x)*(x)
#define vint vector<int>
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
using namespace std;

int T, caso = 1;
double p[100005];
int n,m;

int main(){
	cin  >> T;
	while (T--){
		cin >> m >> n;
		f(i,0,m) cin >> p[i];
		double res = n+2;
		double P = 1;
		f(s,0,m+1){
			double tmp = m + n + 1 -s -s + (1-P)*(n+1);
			P *= p[s];
			res = min (res, tmp);
		}
		printf ("Case #%d: %.7f\n", caso++, res);
	}
}



