//Author: net12k44
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
const int limit = 1000 + 5;
char a[limit];
int solve(){
	int n; scanf("%d",&n);
	scanf("%s", a);
	
	int sum = 0;
	int result = 0;
	for(int i = 0; i <= n; ++i){
		int cur = a[i] - '0';
		if (sum < i) 
			result += i-sum,
			sum = i;
		sum += cur;
	}
	return result;
}

int main(){	
	int test; scanf("%d",&test);
	freopen("file.out","w",stdout);
	for(int i = 1; i<=test; ++i){
		printf("Case #%d: %d\n", i, solve());
	}
}