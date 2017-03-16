#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define  S_MAX 1000

void solve(char *S)
{
	size_t i;
	char   local[(S_MAX + 1) * 2];
	
	size_t start;
	size_t end;
	
	start = end = S_MAX + 1;
	
	local[start] = S[0];
	
	for(i = 1; S[i] != 0; i++) {
		// Before
		if(S[i] >= local[start]) {
			local[--start] = S[i];
		} else {
			local[++end] = S[i];
		}
	}
	local[end + 1] = 0;
	
	printf("%s\n", &local[start]);
}

int main(int argc, char *argv[])
{
	size_t T;
	size_t i;
	char   S[S_MAX + 1];
	
	scanf("%u", &T);
	
	for(i = 0; i < T; i++) {
		scanf("%1000s", S);
		printf("Case #%u: ", i + 1);
		solve(S);
	}
}