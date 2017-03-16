#include<cstdio>

int f(int n, int s){
	if (n == 1){
		return !s;
	}else if (n == 2){
		switch (s){
			case 0: 
			case 1: 
				return 1;
			case 2:
				return 2;
			case 3:
				return 0;
		}
	}else {
		switch (s){
			case 0:
				return f(n - 1, 2) + 1;
			case 3:
				return f(n - 1, 2);
			case 1:
				return f(n - 1, 0);
			case 2:
				return f(n - 1, 0) + 1;
		}
	}
}

int t;
char s[200];

int main(){
	scanf("%d", &t);
	for (int c = 1; c <= t; c++){
		scanf("%s", s);
		int l = 1, i;
		for (i = 1; s[i]; i++){
			if (s[i] != s[i - 1]){
				l++;
			}
		}

		printf("Case #%d: %d\n", c, f(l, (s[0] == '+'? 2: 0) + (s[i - 1] == '+'? 1: 0)));
	}
}
