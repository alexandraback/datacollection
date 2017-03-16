#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 2999;
using namespace std;

int countAlphabet[99], countDigit[10][99], usedDigit[10];

char * digitName[] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

void countNumber(char * str) {
	for (int i = 0; str[i]; i++)
		countAlphabet[str[i] - 'A']++;
}

void greedyUse(int digit) {
	int maxUse = MAX;

	for (char abc = 'A'; abc <= 'Z'; abc++) {
		if (countDigit[digit][abc - 'A'])
			maxUse = min(maxUse, countAlphabet[abc - 'A'] / countDigit[digit][abc - 'A']);
	}

	usedDigit[digit] += maxUse;

	for (char abc = 'A'; abc <= 'Z'; abc++) {
		countAlphabet[abc - 'A'] -= maxUse * countDigit[digit][abc - 'A'];
	}
}

int main() {
	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; digitName[i][j]; j++) {
			countDigit[i][digitName[i][j] - 'A']++;
		}
	}

	int numCase, nowCase;
	scanf("%d", &numCase);
	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		memset(countAlphabet, 0, sizeof(countAlphabet));
		memset(usedDigit, 0, sizeof(usedDigit));

		char str[MAX];
		scanf("%s", str);

		countNumber(str);

		greedyUse(0); //Zero
		greedyUse(2); //tWo
		greedyUse(4); //foUr
		greedyUse(6); //siX
		greedyUse(8); //eiGht
		//absoulute greedy

		greedyUse(1); //One
		greedyUse(5); //Five
		greedyUse(3); //THRee
		greedyUse(7); //SeVen
		greedyUse(9); //NINE
		//relative greedy

		printf("Case #%d: ", nowCase);
		for (int digit = 0; digit < 10; digit++) {
			for (int i = 0; i < usedDigit[digit]; i++)
				printf("%d", digit);
		}
		puts("");
	}

	return 0;
}