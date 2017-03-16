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

int mat[50][50];
int vis[50][50];

int A, B, C;

bool is_valid (int x, int y){
	if (x<0) return false;
	if (y<0) return false;
	if (x>=A) return false;
	if (y>=B) return false;
}

int main (){
	int T;
	scanf (" %d", &T);
	FORR (cx, T){
		scanf (" %d %d %d", &A, &B, &C);
		memset (mat, 0, sizeof mat);
		int R = A*B-C, M = B;
		if (A<B) M = A;
		printf ("Case #%d:\n", cx+1);
		bool ok = true;
		if (M==2 && (R&1) && R!=1) ok = false;
		if (R<=2*M+1 && M!=1){
			if (R==2||R==3||R==5||R==7) {
				ok = false;
			} else {
				if (R==1){
					mat[0][0] = 1;
				} else {
					if (R&1){
						mat[2][0] = mat[2][1] = mat[2][2] = 1;
						R -= 3;	
					}
					FORR (i, R/2){
						mat[0][i] = mat[1][i] = 1;
					}
				}
			}
		} else {
			FORR (i, R){
				int xi = i/M, xj = i%M;
				mat[xi][xj] = 1;
			}
			if (R%M==1){
				mat[R/M][1] = 1;
				mat[R/M-1][M-1] = 0;
			}
		}		
		if (!ok) {
			printf ("Impossible\n");
		} else {
			FORR (i, A){
				FORR (j, B){
					int xi = i, xj = j;
					if (M!=B) swap (xi, xj);
					if (i==0&&j==0) {
						printf ("c");
					} else if (mat[xi][xj]==1) {
						printf (".");
					} else {
						printf ("*");
					}
				}
				printf ("\n");
			}
		}
		

	}
}

