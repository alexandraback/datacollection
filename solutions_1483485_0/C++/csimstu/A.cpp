#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int MAP[26] = {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};
string str;
int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int TST;
	scanf("%d\n", &TST);

	for ( int tst = 1; tst <= TST; tst ++ ) {
		printf("Case #%d: ", tst);
		getline(cin, str);
		int len = str.size();
		for ( int i = 0; i < len; i ++ )
			if ( str[i] == ' ' )
				printf(" ");
			else
				printf("%c", MAP[str[i] - 'a'] + 'a');
		printf("\n");
	}
}
