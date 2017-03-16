
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	
	int s[10];
	int testcase; scanf("%d", &testcase);
	char str[10][101];
	int hash[26];

	for(int t=1; t<=testcase; ++t){
		int n; scanf("%d", &n);
		for(int i=0; i<n; ++i){
			s[i] = i;
			scanf("%s", str[i]);
		}
		int count = 0;
		do{
			memset(hash, 0, sizeof(hash));
			int p = -1;
			int fail = 0;
			for(int i=0; i<n && !fail; ++i){
				int k = strlen(str[s[i]]);
				for(int j=0; j<k && !fail; ++j){
					if(str[s[i]][j]-'a' != p){
						if(!hash[str[s[i]][j]-'a']){
							hash[str[s[i]][j]-'a'] = 1;
							p = str[s[i]][j]-'a';
						}else{
							fail = 1;
						}
					}
				}
			}
			if(!fail){
				count ++;
			}
		}while(next_permutation(s, s+n));
		printf("Case #%d: %d\n", t, count);
	}
	
	return 0;
}
