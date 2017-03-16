#include <stdio.h>

main() {
	int N, Q;
	char line[110];
	char * at;

//	int swap[] = {24,13,5,8,2,22,11,1,10,20,14,12,23,18,4,21,25,15,3,17,9,6,19,7,0,16};

	int swap[] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};

	scanf(" %d", &N);

	for(Q = 1; Q <= N; Q++) {
		scanf(" %[^\n]", line);

		for(at = line; *at != 0; at++)
			if(*at != ' ')
				*at = (char)(swap[*at - 'a'] + 'a');

		printf("Case #%d: %s\n", Q, line);
	}
}
