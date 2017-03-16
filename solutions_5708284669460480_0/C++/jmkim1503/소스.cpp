#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int T;
int K, L, S;
char str1[10], str2[10];
int counter[26];

bool checker(void){

	for (int i = 0; i < strlen(str2); i++){

		if (counter[str2[i] - 'A'] == 0)
			return false;
	}
	return true;
}

int main(){
	FILE *fp1 = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "w");
	fscanf(fp1, "%d", &T);

	for (int test = 1; test <= T; test++){
		for (int i = 0; i < 26; i++)
			counter[i] = 0;
		fscanf(fp1, "%d %d %d", &K, &L, &S);

		fscanf(fp1, "%s %s", str1, str2);

		for (int i = 0; i < strlen(str1); i++){

			counter[str1[i] - 'A']++;
		}
		long double answer;
		if (checker() == false)
			fprintf(fp2, "Case #%d: 0.0\n", test);
		else{
			answer = 1;
			for (int i = 0; i < strlen(str2); i++){
				answer *= counter[str2[i] - 'A'];
				answer /= K;
			}
			fprintf(fp2, "Case #%d: %lf\n", test, (1 + (S - L)) * (1 - answer));
		}
	}
	return 0;
}