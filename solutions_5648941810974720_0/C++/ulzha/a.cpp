#include <iostream>
#include <string>
using namespace std;

/*
#ZERO
#ONE
#TWO
#THREE
#FOUR
#FIVE
#SIX
#SEVEN
#EIGHT
NINE

X Z G W H U O F V
6 0 8 2 3 4 1 5 7

*/

char name[10][6] = {
	"ZERO",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE",
}, order[11] = "XZGWHUOFVI";
int dorder[10] = {
	6, 0, 8, 2, 3, 4, 1, 5, 7, 9,
};

int main() {
	int nt, it;

	cin >> nt;
	for (it = 0; it < nt; it++) {
		int cc[246] = {}, i, j, cd[10] = {};
		string s;
		cin >> s;

		for (i = 0; i < s.size(); i++) cc[s[i]]++;

		for (i = 0; i < 10; i++) {
			char c = order[i];
			int d = dorder[i];

			cd[d] = cc[c];
			for (j = 0; name[d][j]; j++) cc[name[d][j]] -= cd[d];
		}

		cout << "Case #" << it + 1 << ": ";
		for (i = 0; i < 10; i++) for (j = 0; j < cd[i]; j++) cout << i;
		cout << endl;
	}
}
