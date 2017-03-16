#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include <cassert>
#include <string>

using namespace std;

char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int n ; ~scanf("%d\n", &n);) {
		for (int  t = 0; t < n; ) {
			printf("Case #%d: ", ++t);
			string line;
			getline(cin, line);
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ' ') putchar(' ');
				else putchar(map[line[i] - 'a']);
			}
			puts("");
		}
	}
	return 0;
}
