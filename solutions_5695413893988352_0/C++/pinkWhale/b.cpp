#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<fstream>
using namespace std;

bool satisfy(char str[], int score) {
	int len = strlen(str);

	for (int i = len-1; i >= 0; i--) {
		int num = score % 10;
		if (str[i] != '?' && str[i] != char('0' + num))
			return false;
		score /= 10;
	}
	return true;
}

string getStrScore(int score, int len) {
	string str = to_string(score);
	while (str.length() < len)
		str = "0" + str;
	return str;
}

int main() {
	int test;
	FILE *fp = NULL;
	fp = fopen("B-small-attempt1.in", "r");
	ofstream out;
	out.open("output.txt");

	fscanf(fp, "%d", &test);

	char co[20], ja[20];
	for (int t = 1; t <= test; t++) {
		fscanf(fp, "%s %s", co, ja);
		int len = strlen(co);

		int maxNum = pow(10, len);
		int scoreC, scoreJ, diff = maxNum;
		
		for (int i = 0; i < maxNum; i++) {
			for (int j = 0; j < maxNum; j++) {
				if (satisfy(co, i) && satisfy(ja, j) && diff > abs(i - j)) {
					diff = abs(i - j);
					scoreC = i; scoreJ = j;
				}
			}
		}
		
		string cc, jj;
		cc = getStrScore(scoreC, len);
		jj = getStrScore(scoreJ, len);

		out << "Case #" << t << ": ";
		out << cc << " " << jj << "\n";
	}

	return 0;
}