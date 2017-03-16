#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int mat[105][105];

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	bool ans, status;
	int tc, rows, cols;
	scanf("%d", &tc);
	for (int a=1; a<=tc; a++){
		scanf("%d%d", &rows, &cols);
		for (int b=1; b<=rows; b++){
			for (int c=1; c<=cols; c++){
				scanf("%d", &mat[c][b]);
			}
		}
		ans=true;
		for (int b=1; b<=rows; b++){
			for (int c=1; c<=cols; c++){
				if (mat[c][b]==1){
					status=true;
					for (int d=1; d<=rows; d++){
						if (mat[c][d]!=1){
							status=false;
							break;
						}
					}
					if (status) continue;
					status=true;
					for (int d=1; d<=cols; d++){
						if (mat[d][b]!=1){
							status=false;
							break;
						}
					}
					if (status) continue;
					ans=false;
					break;
				}
			}
			if (!ans) break;
		}
		if (ans) printf("Case #%d: YES\n", a);
		else if (!ans) printf("Case #%d: NO\n", a);
	}
}
