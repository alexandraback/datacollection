#include <cstdio>
#include <cstring>

using namespace std;

const char* arr[] = {"X won", "O won", "Draw", "Game has not completed"};

int r[4];
int c[4];
int d[2];

int main() {
	int test;
	scanf("%d", &test);
	
	for(int k = 1; k <= test; k++) {
		char p;
		bool dot = false;
		int i = 0;
		int t = -101;
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		while(i < 16) {
			scanf("%c", &p);
			if(p == 'O') {
				r[i/4]--;
				c[i%4]--;
				if(i/4 == i%4) d[0]--;
				if((i/4) + (i%4) == 3) d[1]--;
				i++;
			} else if(p == 'X') {
				r[i/4]++;
				c[i%4]++;
				if(i/4 == i%4) d[0]++;
				if((i/4) + (i%4) == 3) d[1]++;
				i++;
			} else if(p == 'T') {
				t = i;
				i++;
			} else if(p == '.') {
				i++;
				dot = true;
			}
		}
		
		int ans = 2;
		for(i = 0; i < 4; i++) {
			if(r[i] == 4) ans = 0;
			if(r[i] == -4) ans = 1;
			if(c[i] == 4) ans = 0;
			if(c[i] == -4) ans = 1;
			
			if(r[i] == 3 && t/4 == i) ans = 0;
			if(r[i] == -3 && t/4 == i) ans = 1;
			if(c[i] == 3 && t%4 == i) ans = 0;
			if(c[i] == -3 && t%4 == i) ans = 1;
		}
		
		if(d[0] == 4) ans = 0;
		if(d[0] == -4) ans = 1;
		if(d[1] == 4) ans = 0;
		if(d[1] == -4) ans = 1;
		
		if(d[0] == 3 && t/4 == t%4) ans = 0;
		if(d[0] == -3 && t/4 == t%4) ans = 1;
		if(d[1] == 3 && (t/4) + (t%4) == 3) ans = 0;
		if(d[1] == -3 && (t/4) + (t%4) == 3) ans = 1;
		
		if(dot && ans == 2) ans = 3;
		
		printf("Case #%d: %s\n", k, arr[ans]);
	}
	
	return 0;
}
