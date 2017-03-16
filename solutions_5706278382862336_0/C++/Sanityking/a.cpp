#include <iostream>
#include <cstdio>
using namespace std;

int t, ans;

int main(){
	scanf("%d", &t);
	int i, j;
	for(int a = 1; a <= t; ++a){
		scanf("%d/%d", &i, &j);
		ans = 0;
		int temp = j;
		while(temp > 1){
			if(temp%2 != 0){
				ans = -1;
				break;
			}
			temp /= 2;
		}
		if(ans == -1){
			printf("Case #%d: impossible\n", a);
			continue;
		}
		while(i < j){
			i *= 2;
			++ans;
			//cout << i << ": " << ans << endl;
		}
		printf("Case #%d: %d\n", a, ans);
	}
	return 0;
}
