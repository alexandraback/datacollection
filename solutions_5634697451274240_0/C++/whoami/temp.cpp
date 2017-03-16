#include <stdio.h>
#include <string.h>
using namespace std;
char pan[105];
void flip(int j){
	for (int i = 0; i <= j; i++){
		if (pan[i] == '-')
			pan[i] = '+';
		else
			pan[i] = '-';
	}
	for (int i = 0; i <= j / 2; i++){
		char temp;
		temp = pan[i];
		pan[i] = pan[j - i];
		pan[j - i] = temp;
	}
}
int main(){
	int testt;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &testt);
	for (int test = 1; test <= testt; test++){
		int ans,n;
		scanf("%s", pan);
		n = strlen(pan);
		for (ans = 0;; ans++){
			bool flag = 0;
			for (int i = n - 1; i >= 0; i--){
				if (pan[i] == '-'){
					flag = 1;
					if (pan[0] == '-'){
						flip(i);
					}
					else{
						for (int j = i - 1; j >= 0; j--){
							if (pan[j] == '+'){
								flip(j);
								break;
							}
						}
					}

					break;
				}
			}
			if (!flag) break;
		}
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
