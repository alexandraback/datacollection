#include <cstdio>
using namespace std;

// 0/1
int mark[102];
char str[102];

// Solve
int solve(int len, int target){
	int i, T = 0, F = 0, lastT, lastF;
	for(i = 0; i < len; i++)
		if(mark[i] == target){
			T++;
			lastT = i;
		}
		else{
			F++;
			lastF = i;
		}

	// All ok
	if(T == len) return 0;

	// All not ok
	if(F == len) return 1;

	// Flip
	if(mark[len-1] == target) return solve(lastF+1, target);
	return solve(lastT+1, !target) + 1;
}

// Main
int main(void)
{
	int tc, cs, i;

	// Test case
	scanf("%d", &tc);
	for(cs = 1; cs <= tc; cs++){
		printf("Case #%d: ", cs);
		scanf("%s", str);
		for(i = 0; str[i] != '\0'; i++)
			mark[i] = str[i] == '+';
		printf("%d\n", solve(i, 1));
	}

	return 0;
}
