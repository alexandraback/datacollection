#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

char num[][10] = {
	"ZERO",
	"SIX",
	"FOUR",
	"EIGHT",
	"TWO",

	"ONE",
	"THREE",
	"FIVE",
	"SEVEN",

	"NINE",
};

char mark[] = {
	'Z',
	'X',
	'U',
	'G',
	'W',

	'O',
	'T',
	'F',
	'S',
	
	'N',
};

int val[] = {
	0,
	6,
	4,
	8,
	2,
	
	1,
	3,
	5,
	7,

	9
};

int main() {
	char input[2005];
	int cnt[1000];

	int T; scanf("%d",&T);
	for (int t=1;t<=T;++t) {
		scanf("%s", input);
		memset(cnt,0,sizeof(cnt));

		for (int i=0;input[i];++i) cnt[input[i]]++;
		vector<int> digits;

		for (int d = 0; d < 10; ++d) {
			while (cnt[mark[d]] > 0) {
				digits.push_back(val[d]);
				for (int i=0;num[d][i];++i) cnt[num[d][i]]--;
			}
		}

		sort(digits.begin(), digits.end());

		printf("Case #%d: ", t);
		for (int i = 0; i < digits.size(); ++i) {
			printf("%d", digits[i]);
		}

		puts("");
	}
	return 0;
}

