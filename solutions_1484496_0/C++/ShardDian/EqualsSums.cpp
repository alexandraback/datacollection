#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int t;
int n;
int numbers[22];
bool used[22];

int firstSet[22];
int nFirst;
int secondSet[22];
int nSecond;

bool checkSecondSet(int sumFirst, int prevSum, int prevI){
	if(sumFirst == prevSum){
		return true;
	}
	nSecond++;
	for(int i = prevI + 1; i <= n; i++){
		if(!used[i]){
			used[i] = true;
			secondSet[nSecond] = numbers[i];
			if(checkSecondSet(sumFirst, prevSum + numbers[i], i)){
				return true;
			}	
			used[i] = false;
		}
	}
	nSecond--;
	return false;
}

bool createFirstSet(int prevSum, int prevI){
	nFirst++;
	for(int i = prevI + 1; i <= n; i++){
		used[i] = true;
		firstSet[nFirst] = numbers[i];
		if(checkSecondSet(prevSum + numbers[i], 0, 0)){
			return true;
		}
		if(createFirstSet(prevSum + numbers[i], i)){
			return true;
		}
		used[i] = false;
	}
	nFirst--;
	return false;
}

int main(){
	scanf("%d", &t);
	for(int cases = 1; cases <= t; cases++){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &numbers[i]);
		}
		sort(numbers + 1, numbers + 1 + n);
		
		memset(used, 0, 22);
		nFirst = 0;
		nSecond = 0;
		
		printf("Case #%d:\n", cases);
		
		if(createFirstSet(0,0)){
			printf("%d", firstSet[1]);
			for(int i = 2; i <= nFirst; i++){
				printf(" %d", firstSet[i]);
			}
			printf("\n");
			printf("%d", secondSet[1]);
			for(int i = 2; i <= nSecond; i++){
				printf(" %d", secondSet[i]);
			}
			printf("\n");
		}
		else{
			printf("Impossible\n");
		}
		
		
	}
	return 0;
}