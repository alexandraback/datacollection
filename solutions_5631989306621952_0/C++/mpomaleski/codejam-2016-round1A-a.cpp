#include <bits/stdc++.h>

using namespace std;

int main(){
	char s[5000], r[5000];
	int t;
	scanf(" %d", &t);
	for(int k = 1; k <= t; k++){
		scanf(" %s", s);
		int st = 2000, end = 2000;
		r[2000] = s[0];
		int tam = strlen(s);
		for(int i = 1; i < tam; i++){
			if(s[i] < r[st]){
				end++;
				r[end] = s[i];
			} else {
				st--;
				r[st] = s[i];
			}
		}
		r[end+1] = '\0';
		printf("Case #%d: %s\n", k, &(r[st]));
	}
	return 0;
}