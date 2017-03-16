#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	char str[104];
	for(int NOWCASE=1; NOWCASE<=T; ++NOWCASE) {
		scanf("%s", str);
		int id = strlen(str) - 1;
		while( id>=0 && str[id]=='+' )
			--id;
		char now = '-';
		int ans = 0;
		while( id>=0 ) {
			++ans;
			while( id>=0 && str[id]==now )
				--id;
			now = (now=='-')? '+' : '-';
		}
		printf("Case #%d: %d\n", NOWCASE, ans);
	}
	return 0;
}
