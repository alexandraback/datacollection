#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

using namespace std;
const int maxn = 1300;
const int inf = 1e9+7;

char s[maxn], ans[maxn];
int n;

int main(){

	int t; scanf("%d", &t);
	for(int it=1;it<=t;it++){
		scanf("%s", s);
		int len = strlen(s); int n = 0;
		for(int i=0;i<len;i++){
			if ( n==0 ) ans[n++] = s[i];
			else if ( ans[0]>s[i] ) {
				ans[n++] = s[i];
			}	
			else {
				for(int j=n;j>0;j--){
					ans[j] = ans[j-1];
				}
				n++;
				ans[0] = s[i]; 
			}
		}
		ans[n] = 0;
		printf("Case #%d: %s\n", it, ans);
	}

	return 0;
}

