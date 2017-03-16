#include <stdio.h>
#include <string>
using namespace std;

int flipPlus(string S);
int flipMinus(string S);

int flipPlus(string S)
{
	if (S.find_first_of('-')==string::npos) {
		return 0;
	}

	if (S[S.length()-1]=='+')
		return flipPlus(S.substr(0, S.length()-1));
	else 
		return flipMinus(S.substr(0, S.length()-1))+1;
}

int flipMinus(string S)
{
	if (S.find_first_of('+')==string::npos) {
		return 0;
	}

	if (S[S.length()-1]=='-') 
		return flipMinus(S.substr(0, S.length()-1));
	else
		return flipPlus(S.substr(0, S.length()-1))+1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=0;i<T;i++) {
		char line[1000];
		scanf("%s", line);
		printf("Case #%d: %d\n", i+1, flipPlus(string(line)));
	}
	return 0;
}
