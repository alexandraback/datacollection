#include <iostream>

using namespace std;

int T;
int R, C, W;

int main(){
	FILE *fp1 = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "w");
	fscanf(fp1, "%d", &T);

	for (int test = 1; test <= T; test++){

		fscanf(fp1, "%d %d %d", &R, &C, &W);
		//R==1;
		int answer = 0;

		answer = R * (C / W);
		if (C%W == 0){
			answer += (W - 1);
		}
		else{
			answer += W;
		}

		fprintf(fp2, "Case #%d: %d\n", test, answer);
	}
	return 0;
}