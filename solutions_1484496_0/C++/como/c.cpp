#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std; 

int a[501];
int stat[2000005];
int n; 
int maxSum; 
void input(){
	scanf("%ld", &n);
	maxSum = 0; 
	for (int i = 0; i < n; i++){
		scanf("%ld", &a[i]);
		maxSum += a[i];
	}	
	memset(stat, 255, sizeof(int) * (maxSum + 1));
}

void output(int i){
	if (stat[i] == 0){
		printf("%ld\n", i);
		return; 
	}
	printf("%ld ", i - stat[i]);
	output(stat[i]);
}

void work(){
	for (int i = 0; i < n; i++){
		for (int j = maxSum - a[i]; j >= 0; j--){
			if (stat[j] == -1 && j != 0) continue; 
			if (stat[j + a[i]] == -1) {
				stat[j + a[i]] = j; 
				continue; 
			}
			output(j + a[i]);
			if (j != 0){
				printf("%ld ", a[i]);
				output(j);
			} else printf("%ld\n", a[i]);
			return; 
		}
	} 
	printf("Impossible\n");
}
int main(){
	freopen("/Users/qiaomiao/Downloads/C-small-attempt0.in", "r", stdin);
	freopen("/Users/qiaomiao/code/googlejam/out.txt", "w", stdout);
	int t; 
	scanf("%ld", &t);
	for (int testCase = 0; testCase < t; testCase ++){
		input();
		printf("Case #%ld:\n", testCase + 1);
		work();
		
	}
	fclose(stdin);
	fclose(stdout);
}