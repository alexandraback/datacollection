//Author: net12k44
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int limit = 1000 + 5;
int a[limit];

int cal(int n, int left){
	int result = left;
	for(int i = 0; i < n; ++i)
		result += (a[i]-1) / left;
		
	return result;
}

int solve(){
	int n; scanf("%d",&n);
	for(int i = 0; i < n; ++i) 
		scanf("%d",a+i);
		
	int result = 1000 + 5;
	for(int left = 1; left <= 1000; ++left)
		result = min(result, cal(n, left));
	
	return result;	
}

int main(){
	int test; scanf("%d",&test);
	freopen("file.out","w",stdout);
	for(int i = 1; i<=test; ++i){
		printf("Case #%d: %d\n", i, solve());
	}
}