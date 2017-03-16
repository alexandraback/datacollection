#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_SHYNESS_ARRAY = 1005;

int minInvite(int maxShyness, char *shynessValue){
	int peopleCumulative[MAX_SHYNESS_ARRAY];
	int invite = 0;
	
	//Make cumulative with array[i] = count people with shyness 0..i
	peopleCumulative[0] = shynessValue[0] - '0';
	for(int shyness=1; shyness<=maxShyness; shyness++){
		peopleCumulative[shyness] = peopleCumulative[shyness-1] + (shynessValue[shyness] - '0');
	}
	
	//Find the minimum invite. Assume we can always invite people with shyness = 0 
	for(int shyness=1; shyness<=maxShyness; shyness++){
		if(shyness > peopleCumulative[shyness-1])
			invite = max(invite, shyness-peopleCumulative[shyness-1]);
	}
	
	return invite;
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int t=1; t<=tc; t++){
		int maxShyness;
		char shynessValue[MAX_SHYNESS_ARRAY];
		scanf("%d %s", &maxShyness, shynessValue);
		printf("Case #%d: %d\n", t, minInvite(maxShyness, shynessValue));
	}
	return 0;
}
