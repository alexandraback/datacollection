#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[200];
int n;

int main() {
	int T;
	scanf("%d", &T);
	for(int _case=1; _case<=T; ++_case) {
		scanf("%s", s);
		n = strlen(s);
		int nstep = 0;
		bool stop = false;
		while(!stop) {
			int p = 0;
			while( p < n && s[p] == s[0]) ++p;
			if(s[0] == '+') {
				if( p == n ) break;
				fill(s, s+p, '-');
			}
			else {
				if( p == n ) {
					++nstep;
					break;
				}
				fill(s, s+p, '+');
			}
			++nstep;
		}
		printf("Case #%d: %d\n", _case, nstep);
	}
	return 0;
}
