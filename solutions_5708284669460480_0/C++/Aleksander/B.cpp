#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

int alphabetSize, wordSize, symbols;
char buf[105];
string alphabet, word;

int letCnt[200];
double letP[200];

int nextPos[200][200];

double p[200], pNew[200], expVal[200], expNew[200];

void clearAll () {
	for (int i = 'A'; i <= 'Z'; i++) {
		letCnt[i] = 0;
		letP[i] = 0;
	}
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			nextPos[i][j] = 0;
		}
		p[i] = 0;
		pNew[i] = 0;
		expVal[i] = 0;
		expNew[i] = 0;
	}
}

int getSuffix (const string & s) {
	for (int i = 1; i < s.size(); i++) {
		bool ok = true;
		for (int j = i, k = 0; j < s.size(); j++, k++) {
			if (s[j] != word[k] ) {
				ok = false;
				break;
			}
		}

		if (!ok)
			continue;

		return (int) s.size() - i;
	}
	return 0;
}

void getNextPos () {
	for (int i = 1; i < wordSize; i++) {
		for (int j = 'A'; j <= 'Z'; j++) {
			string s;
			for (int k = 0; k < i; k++)
				s.push_back(word[k] );
			s.push_back(j);
			nextPos[i][j] = getSuffix(s);
		}
	}
}

int getMaxAns () {
	int ans = 0;
	for (int i = 0, len = 0; i < symbols; i++) {
		if (len != wordSize - 1) {
			if (letP[word[len] ] == 0)
				return 0;
			len++;
			continue;
		}

		if (letP[word[len] ] == 0)
			return 0;
		ans++;
		len = nextPos[len][word[wordSize - 1] ];
	}
	return ans;
}

double getExpAns () {
	for (int i = 0; i < wordSize; i++) {
		p[i] = 0;
		expVal[i] = 0;
	}
	p[0] = 1;

	for (int i = 0; i < symbols; i++) {
		for (int j = 0; j < wordSize; j++) {
			pNew[j] = 0;
			expNew[j] = 0;
		}

		for (int j = 0; j < wordSize; j++) {
			for (int k = 'A'; k <= 'Z'; k++) {
				int add = 0;
				if (j == wordSize - 1 && k == word[wordSize - 1] )
					add++;

				int pos = nextPos[j][k];
				if (k == word[j] && add == 0)
					pos = j + 1;
				pNew[pos] += p[j] * letP[k];
				expNew[pos] += expVal[j] * letP[k] + add * p[j] * letP[k];
			}
		}

		for (int j = 0; j < wordSize; j++) {
			p[j] = pNew[j];
			expVal[j] = expNew[j];
		}
	}

	double ans = 0;
	for (int i = 0; i < wordSize; i++)
		ans += expVal[i];
	return ans;
}

void solve ()
{
	clearAll();
	for (int i = 0; i < alphabetSize; i++) {
		letCnt[alphabet[i] ]++;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		letP[i] = (letCnt[i] * 1.) / (alphabetSize * 1.);
	}

	getNextPos();

	int maxAns = getMaxAns();
	double expAns = getExpAns();
	printf("%.12lf", maxAns - expAns);
}

int main ()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test_amount, test_num;

	scanf("%d\n", &test_amount);
	for (test_num = 0; test_num < test_amount; test_num++)
	{
		if (test_num)
			printf("\n");

		printf("Case #%d: ", test_num + 1);

		// input

		scanf("%d%d%d\n", &alphabetSize, &wordSize, &symbols);
		scanf("%s", buf);
		alphabet = string(buf);
		scanf("\n");
		scanf("%s", buf);
		word = string(buf);
		scanf("\n");

		// #input

		solve();
	}

	return 0;
}