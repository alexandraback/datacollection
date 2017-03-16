#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int T; scanf("%d",&T);
	char S[1111];
	for (int t=1;t<=T;++t){
		scanf("%s",S);
		string ans = "";

		for (int i=0;S[i];++i){
			ans = max(ans+S[i], S[i]+ans);
		}

		printf("Case #%d: %s\n", t, ans.c_str());
	}
	return 0;
}
