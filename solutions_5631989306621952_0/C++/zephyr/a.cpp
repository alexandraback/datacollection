#include <iostream>
#include <string>
using namespace std;
int N;
#define MAX(a,b) ((a)>(b)?(a):(b))

int main()
{	
	freopen("A-small-attempt1.in", "r", stdin);
	int T;
	cin >> T;
	FILE* fout = fopen("output", "w");
	for (int t = 1; t <= T; t++) {
		char str[1001];
		char rs[2001];
		int first = 1000;
		int last = 1000;		
		cin >> str;
		rs[first] = str[0];
		for (int i = 1; str[i]; i++) {
			if (str[i] >= rs[first]) rs[--first] = str[i];
			else rs[++last] = str[i];
		}
		rs[++last] = '\0';
		fprintf(fout, "Case #%d: %s\n", t, (rs + first));
	}
	return 0;
}

