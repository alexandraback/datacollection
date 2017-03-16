#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
  
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, n) FOR(i, 0, n)
#define sz(e) (int)e.size()
#define all(e) e.begin(), e.end()
#define pb push_back
#define CLR(x, a) memset(x, a, sizeof(x))
  
#define ll long long
#define ull unsigned ll
#define ii pair<int, int>
#define vi vector<int>
  
using namespace std;

double C, F, X;

double solve (int M){
	double T = 0, P = 2;
	double res = X/P;
	FORR (i, M){
		T += C/P;
		P += F;
		res = min (res, T + X/P); 
	}
	return res;
}

int main (){
	int T;
	scanf (" %d", &T);
	FORR (cx, T){
		
		scanf (" %lf %lf %lf", &C, &F, &X);
		//double M = 1. + (2. * C - X * F) / C * F;
		//int M1 = (int) M, M2 = M+1;
		//double res = min (solve (M1), solve(M2));
		printf ("Case #%d: %.7lf\n", cx+1, solve (2*X+10));

	}
}

