#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long LL;

const int maxk = 15;
int r, k, n, m;
int p[maxk];


bool n1(){
	for(int a = 2; a <= m; a++){
		bool ok = true;
		for(int i = 0; i < k; i++){
			if(p[i] == 1 || p[i] == a){
			}else{
				ok = false;
				break;
			}
		}
		if(ok){
			printf("%d\n", a);
			return true;
		}
	}
	return false;
}

bool n2(){
	for(int a = 2; a <= m; a++)
		for(int b = 2; b <= m; b++){
			bool ok = true;
			for(int i = 0; i < k; i++){
				if(p[i] == 1 || p[i] == a || p[i] == b || p[i] == a * b){
				}else{
					ok = false;
					break;
				}
			}
			if(ok){
				printf("%d%d\n", a, b);
				return true;
			}
		}
	return false;
}

bool n3(){
	for(int a = 2; a <= m; a++)
		for(int b = 2; b <= m; b++)
		  for(int c = 2; c <= m; c++){
			  bool ok = true;
			  for(int i = 0; i < k; i++){
				  if(p[i] == 1 || p[i] == a || p[i] == b || p[i] == c ||
					  p[i] == a * b || p[i] == a * c || p[i] == b * c || p[i] == a * b * c){
				  }else{
					  ok = false;
					  break;
				  }
			  }
			  if(ok){
				  printf("%d%d%d\n", a, b, c);
				  return true;
			  }
		  }
	return false;
}

int main(){
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out","w",stdout);
	int T, ca = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &r, &n, &m, &k);
		printf("Case #%d:\n", ++ca);
		for(int x = 0; x < r; x++){
			for(int i = 0; i < k; i++){
				scanf("%d", &p[i]);
			}
			if(n3())continue;
			if(n2())continue;
			if(n1())continue;
			
		}
	}
	return 0;
}