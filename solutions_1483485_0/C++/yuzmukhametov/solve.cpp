#include <iostream>
#include <string>
using namespace std;
string p = "yhesocvxduiglbkrztnwjpfmaq";
char S[1000];

void solve(int num) {
	do {
		gets(S);
	} while (!S[0]);
	printf("Case #%d: ", num);
	for (int i = 0; S[i]; ++i) {
        printf("%c", p[S[i] - 'a']);
    }
	printf("\n");
}

int main() {
//	freopen("d:\\work\\input.txt", "r", stdin);
freopen("d:\\work\\A-small-attempt0.in", "r", stdin);
	freopen("d:\\work\\output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) solve(i);
	return 0;
}

