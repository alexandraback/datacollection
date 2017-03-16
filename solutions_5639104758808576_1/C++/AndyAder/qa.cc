#include <iostream>
#include <cstdio>

int main()
{
	FILE *fin, *fout;
	int T, test_case;
	int S_max;
	char S[1010];
	int friends, total;

	fin = fopen("A-large.in", "r");
	fout = fopen("output", "w");

	fscanf(fin, "%d", &test_case);
	for(T=1; T<=test_case; T++) {
		friends = total = 0;
		fscanf(fin, "%d %s", &S_max, S);
		for(int i=1; i<=S_max; i++) {
			total += (S[i-1]-'0');
			if(total < i) {
				friends += i - total;
				total += i - total;
			}
		}

		fprintf(fout, "Case #%d: %d\n", T, friends);
	}



	fclose(fin);
	fclose(fout);
}

