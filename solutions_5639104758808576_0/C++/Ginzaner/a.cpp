#include <cstdio>

using namespace std;

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		
		int S;
		scanf(" %d ", &S);
		
		int stand = 0;
		int inv = 0;
		
		for(int i = 0; i <= S; i++) {
			char c;
			scanf("%c", &c);
			int w = (int)(c-'0');
			if(stand < i) {
				inv += i-stand;
				stand = i;
			}
			stand += w;
		}
		
		printf("%d\n", inv);
	}
	
	return 0;
}
