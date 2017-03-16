#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int ncases, r1, r2, cont;
	double t;
	double a, PI;
	PI = atan(1.0)*4;
	scanf("%d",&ncases);
	f(i,1,ncases+1){
		scanf("%d %lf",&r1, &t);
		cont = 0;
		r2 = r1 + 1;
		a = (r2*r2 - r1*r1);
		while(t>=a){
			cont++;
			t -= a;
			r1 += 2;
			r2 += 2;
			a = (r2*r2 - r1*r1);
		}
		printf("Case #%d: %d\n",i,cont);
	}
	return 0;
}
