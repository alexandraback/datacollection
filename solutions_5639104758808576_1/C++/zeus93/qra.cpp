#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 1005

char s[N];

int main(){
	int t;
	scanf("%d", &t);
	int n, f, st;
	for(int i = 1; i<= t; i++){
		scanf("%d%s", &n, s);
		f = st = 0;
		st += (s[0] - '0');
		for(int j = 1; j <= n; j++){
			if(st < j){
				f += (j - st);
				st = j;
			}
			st += (s[j] - '0');
		}
		printf("Case #%d: %d\n", i, f);
	}
	return 0;
}
