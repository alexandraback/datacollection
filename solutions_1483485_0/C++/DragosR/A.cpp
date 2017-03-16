#include <cstdio>
#include <cstring>
#include <string>

const int maxn = 110;

using namespace std;

int m[] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
char s[maxn]; 
int n, T;
int main() {
	
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	scanf("%d\n", &T);
	for(int i = 1; i <= T; ++i) {
		gets(s); n = strlen(s); 
		printf("Case #%d: ", i);

		for(int i = 0; i < n; ++i) {
			if(s[i] == ' ') printf(" "); else 
			printf("%c", m[s[i] - 'a'] + 'a');
		}
		printf("\n");
	}
	return 0;
}
