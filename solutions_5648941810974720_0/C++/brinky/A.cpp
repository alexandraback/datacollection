#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cstring>

using namespace std;

char words[][20] = {"ZERO", "TWO", "SIX", "SEVEN", "FIVE", "FOUR", "ONE", "THREE", "EIGHT", "NINE"};
int num[] = {0, 2, 6, 7, 5, 4, 1, 3, 8, 9};
char sr[] = "ZWXSVUORTI";

int cnt[255];
int res[10];

int main(){
	int tcn, tc;
	cin >> tcn;
	for(tc = 1; tc <= tcn; ++tc){
		memset(res, 0, sizeof(res));
		memset(cnt, 0, sizeof(cnt));
		string w;
		cin >> w;
		for(int i=0; i<w.size(); ++i){
			cnt[w[i]]++;
		}
		for(int i=0; i<10; ++i){
			res[num[i]] = cnt[sr[i]];
			for(int j=0; words[i][j]; ++j){
				cnt[words[i][j]] -= res[num[i]];
			}
		}
		printf("Case #%d: ", tc);
		for(int i=0; i<10; ++i){
			for(int j=0; j<res[i]; ++j){
				putchar('0'+i);
			}
		}
		printf("\n");
	}
}
