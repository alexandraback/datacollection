#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int diningTime(int pancake, int nDiner, int* diner){	
	int penalty = 0;
	for(int i=0; i<nDiner; i++){
		penalty += ceil(diner[i]/(double) pancake)-1;
	}
	return pancake+penalty;
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=1; t<=tc; t++){
		int nDiner;
		scanf("%d", &nDiner);
		
		int diner[nDiner];
		int maxPancake = 0;
		for(int i=0; i<nDiner; i++){
			scanf("%d", &diner[i]);
			if(diner[i]>maxPancake) maxPancake = diner[i];
		}
		
		int minDiningTime = maxPancake;
		for(int i=1; i<=maxPancake; i++){
			int time = diningTime(i, nDiner, diner);
			if(time < minDiningTime) minDiningTime = time;
		}
		
		printf("Case #%d: %d\n", t, minDiningTime);
	}
	return 0;
}