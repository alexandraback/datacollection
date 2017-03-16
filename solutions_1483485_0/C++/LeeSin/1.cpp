#include <cstdio>
#include <algorithm>
#include <vector>
#define fi(a, b, c) for(int a = b; a < c; a++)
#define fd(a, b, c) for(int a = b; a > c; a--)
#define FI(a, b, c) for(int a = b; a <= c; a++)
#define FD(a, b, c) for(int a = b; a >= c; a--)
using namespace std;

int t;
char c, m[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d\n", &t);
	FI(i, 1, t){
		printf("Case #%d: ", i);
		
		while(scanf("%c", &c) && c != '\n'){
			if(c != ' ') c = m[c - 'a'];
			printf("%c", c);
		}
		
		puts("");
	}
	scanf("\n");
}
