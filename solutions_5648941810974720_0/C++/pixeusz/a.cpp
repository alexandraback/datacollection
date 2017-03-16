#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

#define MAXL 2002
char S[MAXL];
int nrCounts[10];
int letterCounts[100];

void SolveCase(int caseId);

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
		SolveCase(i);
	return 0;
}

void Reduce(int digit, char letter, const string& s)
{
	int d = nrCounts[digit] = letterCounts[letter];
	for(char c : s)	letterCounts[c] -= d;
}

void SolveCase(int caseId)
{
	scanf("%s", S);
	int len = strlen(S);

	for(int i = 'A'; i <= 'Z'; ++i)
		letterCounts[i] = 0;
	for(int i = 0; i < len; ++i)
		++letterCounts[S[i]];
		
	Reduce(6, 'X', "SIX");
	Reduce(2, 'W', "TWO");
	Reduce(0, 'Z', "ZERO");
	Reduce(8, 'G', "EIGHT");
	Reduce(3, 'T', "THREE");
	Reduce(4, 'R', "FOUR");
	Reduce(5, 'F', "FIVE");
	Reduce(7, 'S', "SEVEN");
	Reduce(1, 'O', "ONE");
	Reduce(9, 'I', "NINE");

	printf("Case #%d: ", caseId);
	for(int i = 0; i <= 9; ++i)
		for(int k = 0; k < nrCounts[i]; ++k)
			printf("%d", i);
	puts("");
}


