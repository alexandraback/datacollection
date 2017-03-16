#include <stdio.h>
#include <string.h>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int p[30] = {0,};
int s[60] = {0,};
int t[60] = {0,};
int q[50000][60] = {0,};
int c = 0;
void play(int x, int y){
	if(y > 24) return ;
	p[y] = x;
	int i, j;
	for(i = 0; i <= y; i++) s[i] = p[i];
	for(i = y+1; i <= 2*y; i++) s[i] = p[2*y-i];
	for(i = 0; i <= 2*y; i++){
		t[i] = 0;
		for(j = 0; j <= i; j++){
			t[i] += s[j]*s[i-j];
		}
	}
	int ch0 = 0, ch1 = 0;
	for(i = 0; i <= 2*y; i++) if(t[i] >= 10) ch0 = 1;
	if(ch0 == 0){
		for(i = 0; i <= 2*y; i++) fprintf(output, "%d", t[i]);
		for(i = 2*y-1; i >= 0; i--) fprintf(output, "%d", t[i]);
		fprintf(output, ", ");
		c++;
	}
	for(i = y+1; i <= 2*y+1; i++) s[i] = p[2*y+1-i];
	for(i = 0; i <= 2*y+1; i++){
		t[i] = 0;
		for(j = 0; j <= i; j++){
			t[i] += s[j]*s[i-j];
		}
	}
	for(i = 0; i <= 2*y+1; i++) if(t[i] >= 10) ch1 = 1;
	if(ch1 == 0){
		for(i = 0; i <= 2*y+1; i++) fprintf(output, "%d", t[i]);
		for(i = 2*y; i >= 0; i--) fprintf(output, "%d", t[i]);
		fprintf(output, ", ");
		c++;
	}
	if(ch0 == 1 && ch1 == 1) return ;
	for(i = 0; i < 10; i++) play(i, y+1);
}
int main(){
	int i, j;
	for(i = 1; i <= 9; i++){
		play(i, 0);
	}
	return 0;
}