#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

char s[200];
int n, l, t[200];

int f(char c){
	if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
		c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') return 1;
	return 0;
}

int main(){
	int t, c = 1;
	
	scanf("%d", &t);
	while(t--){
		scanf(" %s %d", s, &n);
		l = strlen(s);
			
		int res = 0;
		for(int j = l-1; j >= 0; --j){
			for(int i = 0; i <= j; ++i){
				int cont = 0, flag = 0;
				for(int k = i; k <=j; ++k){
					if(cont >= n) flag = 1;
					if(f(s[k])) cont++;
					else cont = 0;
					if(cont >= n) flag = 1;
				}
				if(flag) res++;	
			}
		}
		printf("Case #%d: %d\n", c++, res);
	}
	
return 0;
}
