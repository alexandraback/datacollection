#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define MAXN 20
#define INF 200000000000
typedef long long ll;
int T;
int cnt[26];
int ans[10];
int main(void)
{
	string s;
	cin >> T;
	for(int t=1; t<=T; t++) {
		memset(ans, 0, sizeof(ans));
		memset(cnt, 0, sizeof(cnt));
		cin >> s;
		for(int i=0; i<s.size(); i++) {
			cnt[s[i]-'A']++;
		}
		if(cnt[25] > 0) { // zero
			cnt[4] -= cnt[25];
			cnt[14] -= cnt[25];
			cnt[17] -= cnt[25];
			ans[0] = cnt[25];
			cnt[25] = 0;
		}
		if(cnt[22] > 0) { // two
			cnt[19] -= cnt[22];
			cnt[14] -= cnt[22];
			ans[2] = cnt[22];
			cnt[22] = 0;
		}
		if(cnt[23] > 0) { // six
			cnt[18] -= cnt[23];
			cnt[8] -= cnt[23];
			ans[6] = cnt[23];
			cnt[23] = 0;
		}
		if(cnt[6] > 0) { // eight
			cnt[4] -= cnt[6];
			cnt[8] -= cnt[6];
			cnt[7] -= cnt[6];
			cnt[19] -= cnt[6];
			ans[8] = cnt[6];
			cnt[6] = 0;
		}
		if(cnt[7] > 0) { // three
			cnt[4] -= (2 * cnt[7]);
			cnt[19] -= cnt[7];
			cnt[17] -= cnt[7];
			ans[3] = cnt[7];
			cnt[7] = 0;
		}
		if(cnt[18] > 0) { // seven
			cnt[4] -= (2*cnt[18]);
			cnt[21] -= cnt[18];
			cnt[13] -= cnt[18];
			ans[7] = cnt[18];
			cnt[18] = 0;
		}
		if(cnt[21] > 0) { //five
			cnt[5] -= cnt[21];
			cnt[8] -= cnt[21];
			cnt[4] -= cnt[21];
			ans[5] = cnt[21];
			cnt[21] = 0;
		}
		if(cnt[5] > 0) { // four
			cnt[14] -= cnt[5];
			cnt[20] -= cnt[5];
			cnt[17] -= cnt[5];
			ans[4] = cnt[5];
			cnt[5] = 0;
		}
		if(cnt[14] > 0) { //one
			cnt[4] -= cnt[19];
			cnt[13] -= cnt[19];
			ans[1] = cnt[14];
			cnt[14] = 0;
		}
		if(cnt[8] > 0) { //nine
			cnt[13] -= (2*cnt[8]);
			cnt[4] += cnt[8];
			ans[9] = cnt[8];
			cnt[8] = 0;
		}
		printf("Case #%d: ", t);
		for(int i=0; i<10; i++) {
			for(int j=0; j<ans[i]; j++) printf("%d", i);
		}
		printf("\n");
	}
		
				
			
			
	return 0;
}
