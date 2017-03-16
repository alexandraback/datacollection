#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
char mun[2005];
char digit[11][11] = { "ZERO",
"ONE",
"TWO",
"THREE",
"FOUR",
"FIVE",
"SIX",
"SEVEN",
"EIGHT",
"NINE" };
int cnt[26] = { 0, };
vector<int> print;

void del(int number, int count){
	for (int i = 0; i < strlen(digit[number]); i++){
		cnt[digit[number][i]-'A'] -= count;
	}
	for (int i = 0; i < count;i++)
		print.push_back(number);
	
}
int main(){
	int testt;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &testt);
	for (int test = 1; test <= testt; test++){
		scanf("%s", mun);
		print.clear();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < strlen(mun); i++){
			cnt[mun[i] - 'A']++;
		}

		del(0, cnt['Z' - 'A']);
		del(2, cnt['W' - 'A']);
		del(4, cnt['U' - 'A']);
		del(6, cnt['X' - 'A']);
		del(8, cnt['G' - 'A']);
		del(1, cnt['O' - 'A']);
		del(3, cnt['T' - 'A']);
		del(5, cnt['F' - 'A']);
		del(7, cnt['S' - 'A']);
		del(9, cnt['I' - 'A']);

		bool flag = 0;
		for (int i = 0; i < 26; i++){
			if (cnt[i] != 0)
				flag = 1;
		}
		if (flag == 1){
			for (int i = 0; i < 26; i++){
				if (cnt[i] != 0)
					printf("%d : %d\n", i, cnt[i]);
			}
		}

		sort(print.begin(), print.end());
		printf("Case #%d: ", test);
		for (int i = 0; i < print.size(); i++)
			printf("%d", print[i]);
		printf("\n");
	}
	return 0;
}
