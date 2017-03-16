#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
typedef unsigned long long hash;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define N 200000

double prod[N];
double p[N];

int a, b;

int main(){
	int casos;
	scanf("%d", &casos);
	for(int ca = 1; ca <= casos; ++ca){
		scanf("%d%d", &a, &b);
		
		prod[0] = 1;
		for(int i = 1; i <= a; ++i){
			scanf("%lf", p + i );
			prod[i] = prod[i-1] * p[i];
		}
		
		double E = (b - a + 1) * prod[a] + ( (b - a + 1) + b + 1) * ( 1 - prod[a]);
		E = min(E, 2.0 + b);
		
		for(int i = a; i > 0; --i){
			double passos = (a - i + 1) + (b - i + 1) + 1;
			E = min( E, passos * prod[i-1] + (passos + b + 1) * (1 - prod[i-1]));
		}
		
		printf( "Case #%d: %.6lf\n", ca, E);
	}	
}


