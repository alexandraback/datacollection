#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
bool used[20];
const int N = 1111;
char s[N];
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int cases = 1; cases <= cas; cases ++) {
		int n, i;
		scanf("%s", s);
		string str = "";
		for (int i = 0; i < strlen(s); i++)
			if (str.length() == 0 || s[i] >= str[0])
				str = s[i] + str;
			else
				str = str + s[i];
		printf("Case #%d: ", cases);
		cout << str << endl;

	}
}
