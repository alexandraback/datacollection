#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define MAX 7*1024*1024

int max(int x, int y) {
	return x > y ? x : y;
}

int min(int x, int y) {
	return x < y ? x : y;
}

int consonant(int * s, int n, int L) {
	int* st  = (int*)malloc(sizeof(int) * MAX);
	int* ed = (int*)malloc(sizeof(int) * MAX);
	int segs = 0;
	
	int seg_len = 0;
	for (int i=0; i<n; i++) {
		//printf("%d", s[i]);
		if (s[i]) {
			if (seg_len == 0)
				st[segs] = i;
			seg_len++;
		} else {
			if (seg_len >= L) {
				ed[segs] = i-1;
				segs++;
			}
			seg_len = 0;
		}
	}
	//printf("\n");
	if (seg_len >= L) {
		ed[segs] = n-1;
		segs++;
	}
	
	int result = 0;
	
	for(int idx=0; idx<segs; idx++) {
		int i = st[idx];
		int j = ed[idx];
		//printf("%d %d\n", i, j);
		int k;
		if (idx == segs - 1) 
			k = n - 1;
		else {
			k = min(st[idx + 1] + L - 2, n - 1);
		}
		
		int t = i + 1;
		for (int x = i+L-1; x <= j; x++) {
			result += t;
			//printf("    %d %d\n", x, t);
			t++;
		}
		
		t = j - L + 2;
		for (int x = j + 1; x <= k; x++) {
			result += t;
			//printf("    %d %d\n", x, t);
		}
	}
	free(st);
	free(ed);
	return result;
}
int main() {
	int problem;
	setbuf(stdout, NULL);
	
	scanf("%d\n", &problem);
	
		char* str = (char*)malloc(sizeof(char) * MAX);
		int* s = (int*)malloc(sizeof(int) * MAX);
	for(int pi=0; pi<problem; pi++) {

		int L, n;
		
		scanf("%s %d\n", str, &L);
		n = strlen(str);
		//printf("%s\n", str);
		for(int i=0;i < n; i++) {
			assert(str[i] >='a' && str[i] <= 'z');
			if (str[i] =='a' ||str[i] =='e' ||str[i] =='i' ||str[i] =='o' ||str[i] =='u')
				s[i] = 0;
			else
				s[i] = 1;
		}
		printf("Case #%d: %d\n", pi+1, consonant(s, n, L));
	}
	return 0;
}
