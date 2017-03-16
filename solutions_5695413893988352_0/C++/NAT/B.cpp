#include <cstdio>

int T;
char C[5], J[5];
int in[10];
int len;
int minn;
int c, j;

int abs(int x){
	if(x < 0)x = -x;
	return x;
}

void find(int idx){
	if(idx == 2*len){
		int a = 0, b = 0;

		for(int i = 0; i < len; i++){
			a *= 10;
			a += in[i];
		} 
		for(int i = len; i < 2 * len; i++){
			b *= 10;
			b += in[i];
		}

		if(abs(a-b) < minn){
			minn = abs(a-b);
			c = a;
			j = b;
		}
	} else if( idx < len){
		if(C[idx] != '?'){
			in[idx] = C[idx] - '0';
			find(idx + 1);
		} else {
			for(int i = 0; i <= 9; i++){
				in[idx] = i;
				find(idx + 1);
			}
		} 
	} else {
		if(J[idx - len] != '?'){
			in[idx] = J[idx - len] -'0';
			find(idx + 1);
		} else {
			for(int i = 0; i <= 9; i++){
				in[idx] = i;
				find(idx + 1);
			}
		}
	}
}

int main(){
	scanf("%d", &T);
	for(int tt = 1; tt <= T; tt++){
		scanf("%s %s", C, J);

		for(len = 0; C[len] != '\0'; len++);

		minn = 999999999;
		find(0);

		if(len == 1)
			printf("Case #%d: %01d %01d\n", tt, c, j);
		else if(len == 2)
			printf("Case #%d: %02d %02d\n", tt, c, j);
		else if(len == 3)
			printf("Case #%d: %03d %03d\n", tt, c, j);
	}
}