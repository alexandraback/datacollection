#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <limits>
#include <map>

using namespace std;

void solve();

int main(){
	int cases;
	scanf("%d", &cases);

	for(int i=0; i<cases; i++){
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}

void solve(){
	int max;
	char members[1010];

	scanf("%d", &max);
	scanf("%s", members);

	int curr = 0, extra=0;
	for(int i=0; i<max+1; i++){
		if(curr<i){
			curr++;
			extra++;
		}
		curr+=(members[i]-'0');
	}

	printf("%d\n", extra);
}