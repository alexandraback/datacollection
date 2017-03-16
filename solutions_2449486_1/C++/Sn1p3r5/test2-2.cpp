#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int mat[105][105];

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	bool ans, status, legit;
	int tc, rows, cols;
	scanf("%d", &tc);
	for (int a=1; a<=tc; a++){
		scanf("%d%d", &rows, &cols);
		for (int b=1; b<=rows; b++){
			for (int c=1; c<=cols; c++){
				scanf("%d", &mat[c][b]);
			}
		}
		for (int now=1; now<=100; now++){
			ans=true;
			for (int b=1; b<=rows; b++){
				for (int c=1; c<=cols; c++){
					if (mat[c][b]==now){
						legit=false;
						status=true;
						for (int d=1; d<=rows; d++){
							if (mat[c][d]!=now && mat[c][d]!=0){
								status=false;
								break;
							}
						}
						if (status){
							legit=true;
							for (int d=1; d<=rows; d++){
								mat[c][d]=0;
							}
						}
						status=true;
						for (int d=1; d<=cols; d++){
							if (mat[d][b]!=now && mat[d][b]!=0){
								status=false;
								break;
							}
						}
						if (status){
							legit=true;
							for (int d=1; d<=cols; d++){
								mat[d][b]=0;
							}
						}
						if (!legit){
							ans=false;
							break;
						}
					}
				}
				if (!ans) break;
			}
			if (!ans) break;
		}
		if (!ans){
			printf("Case #%d: NO\n", a);
			continue;
		}
		ans=true;
		for (int b=1; b<=rows; b++){
			for (int c=1; c<=cols; c++){
				if (mat[c][b]!=0){
					ans=false;
					break;
				}
			}
		}
		if (!ans){
			printf("Case #%d: NO\n", a);
		}
		else {
			printf("Case #%d: YES\n", a);
		}
	}
}
