#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		string s;
		int alpha[26] = {0};
		int num[10] = {0};
		cin >> s;
		for(int i = 0; i < s.size(); i++)
			alpha[s[i] - 'A']++;
		num[0] = alpha['Z'-'A'];
		num[2] = alpha['W'-'A'];
		num[4] = alpha['U'-'A'];
		num[6] = alpha['X'-'A'];
		num[8] = alpha['G'-'A'];
		num[1] = alpha['O'-'A'] - (num[0] + num[2] + num[4]);
		num[3] = alpha['R'-'A'] - (num[0] + num[4]);
		num[5] = alpha['F'-'A'] - (num[4]);
		num[7] = alpha['S'-'A'] - (num[6]);
		num[9] = alpha['I'-'A'] - (num[5] + num[6] + num[8]);
		printf("Case #%d: ", (t + 1));
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < num[i]; j++)
				printf("%d", i);
		}
		printf("\n");
	}


	return 0;
}