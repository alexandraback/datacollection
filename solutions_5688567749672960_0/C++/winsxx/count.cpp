#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

#define MAX_V 1000005
int minCount[1000005];

int inverseNum(int x){
	stringstream ss;
	ss << x;
	string xs = ss.str();
	reverse(xs.begin(), xs.end());
	int inv = atoi(xs.c_str());
	return inv;
}

int main(){
	int T;
	
	for(int i=0; i<=1000000; i++){
		minCount[i] = MAX_V;
	}
	minCount[0] = 0;
	//Pre compute
	for(int i=0; i<=1000000; i++){
		minCount[i+1] = min(minCount[i+1], minCount[i]+1);
		int inv = inverseNum(i);
		minCount[inv] = min(minCount[inv], minCount[i]+1); 
	}
	
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N;
		scanf("%d", &N);
		printf("Case #%d: %d\n",t, minCount[N]);
	}
	return 0;
}