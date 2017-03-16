#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

int n;
char str[1000];
int pd[52][52];
vector <string> words;
char word[10000];

int solve(int i, int bla)
{
	if (i == n)
		return 0;
	int& ret = pd[i][bla+5];
	if (ret != -1)
		return ret;

	ret = 1000;

	for (int j = 0; j < words.size(); j++) {
		int nerr = 0;
		int lasterr = bla;
		int ok = 1;

		if (i + words[j].size() > n)
			continue;

		for (int k = 0; k < words[j].size(); k++) {
			if (words[j][k] != str[i+k]) {
				if (!(k >= lasterr+5)) {
					ok = 0;
					break;
				}
				nerr ++;
				lasterr = k;
			}
		}

		if (ok) {
			ret = min(ret, nerr + solve(i + words[j].size(), max(-5, lasterr - (int)words[j].size())));
		}
	}

	return ret;
}

int main()
{
	int ntest;

	scanf("%d", &ntest);

	FILE* f = fopen("dict.txt", "r");

	while (fscanf(f, " %s", word) > 0) {
		words.push_back(string(word));
	}
	fclose(f);
	
	for (int t = 0; t < ntest; t++) {
		scanf(" %s", str);
		n = strlen(str);
		memset(pd, -1, sizeof(pd));
		printf("Case #%d: %d\n", t+1, solve(0, -5));
	}

	return 0;
}
