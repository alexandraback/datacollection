#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(double i,double j){
	return (i<j);
}

int main(){
	int numTestCase = 0, numBlock;
	int lastFindIndex, findIndex, findCount, defaultPoint, deceitfulPoint;
	int i, j, temp;
	double tempDouble;
	int testCase, blockCount;
	std::vector<double> blocks1;
	std::vector<double> blocks2;
		
	scanf("%d", &numTestCase);
	
	for(testCase = 0; testCase < numTestCase; testCase++){
		blocks1.clear();
		blocks2.clear();
		scanf("%d", &numBlock);
		
		for(blockCount = 0; blockCount < numBlock; blockCount++){
			scanf("%lf", &tempDouble);
			blocks1.push_back(tempDouble);
		}
		
		for(blockCount = 0; blockCount < numBlock; blockCount++){
			scanf("%lf", &tempDouble);
			blocks2.push_back(tempDouble);
		}

		std::sort (blocks1.begin(), blocks1.end(), cmp);
		std::sort (blocks2.begin(), blocks2.end(), cmp);
		
		findIndex = 0;
		findCount = 0;
		lastFindIndex = -1;
		for(i = 0; i < numBlock; i++){
			for(j = findIndex; j < numBlock; j++){
				if(blocks2[j] > blocks1[i]){
					findIndex = j+1;
					findCount++;
					break;
				}
			}
			
			if(lastFindIndex == findIndex){
				break;
			}
			lastFindIndex = findIndex;
		}
		defaultPoint = numBlock - findCount;
		
		findIndex = numBlock - 1;
		findCount = 0;
		lastFindIndex = -1;
		for(i = numBlock - 1; i >= 0; i--){
			for(j = findIndex; j >= 0; j--){
				if(blocks1[i] > blocks2[j]){
					findIndex = j-1;
					findCount++;
					break;
				}
			}
			
			if(lastFindIndex == findIndex){
				break;
			}
			lastFindIndex = findIndex;
		}
		deceitfulPoint = findCount;
		
		printf("Case #%d: %d %d\n", testCase+1, deceitfulPoint, defaultPoint);
	}
	
	return 0;
}
