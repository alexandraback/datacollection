#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		char str[3000];
		scanf("%s", str);

		int count[26];
		fill(count, count+26, 0);
		for (int i=0; str[i] != '\0'; i++)
			count[str[i]-'A'] ++;

		int digits[10];
		fill(digits, digits+10, 0);
		while (count['Z'-'A'] > 0) {
			digits[0]++;
			count['Z'-'A']--;
			count['E'-'A']--;
			count['R'-'A']--;
			count['O'-'A']--;
		}

		while (count['W'-'A'] > 0) {
			digits[2]++;
			count['T'-'A']--;
			count['W'-'A']--;
			count['O'-'A']--;
		}

		while (count['U'-'A'] > 0) {
			digits[4]++;
			count['F'-'A']--;
			count['O'-'A']--;
			count['U'-'A']--;
			count['R'-'A']--;
		}

		while (count['X'-'A'] > 0) {
			digits[6]++;
			count['S'-'A']--;
			count['I'-'A']--;
			count['X'-'A']--;
		}

		while (count['R'-'A'] > 0) {
			digits[3]++;
			count['T'-'A']--;
			count['H'-'A']--;
			count['R'-'A']--;
			count['E'-'A']--;
			count['E'-'A']--;
		}

		while (count['F'-'A'] > 0) {
			digits[5]++;
			count['F'-'A']--;
			count['I'-'A']--;
			count['V'-'A']--;
			count['E'-'A']--;
		}

		while (count['V'-'A'] > 0) {
			digits[7]++;
			count['S'-'A']--;
			count['E'-'A']--;
			count['V'-'A']--;
			count['E'-'A']--;
			count['N'-'A']--;
		}

		while (count['H'-'A'] > 0) {
			digits[8]++;
			count['E'-'A']--;
			count['I'-'A']--;
			count['G'-'A']--;
			count['H'-'A']--;
			count['T'-'A']--;
		}

		while (count['O'-'A'] > 0) {
			digits[1]++;
			count['O'-'A']--;
			count['N'-'A']--;
			count['E'-'A']--;
		}

		while (count['I'-'A'] > 0) {
			digits[9]++;
			count['N'-'A']--;
			count['I'-'A']--;
			count['N'-'A']--;
			count['E'-'A']--;
		}

		printf("Case #%d: ", iC);
		for (int i=0; i<10; i++) {
			for (int j=0; j<digits[i]; j++)
				printf("%c", '0'+i);
		}
		printf("\n");
	}
	return 0;
}