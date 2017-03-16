#include <cstdio>
#include <list>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int t;
char str_in[1001];


int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s",str_in);

		list<char> str_out;
		list<char>::iterator i_str_out;

		str_out.push_back(str_in[0]);

		for (int k = 1; str_in[k] != '\0'; k++) {
			i_str_out = str_out.begin();
			if ((str_in[k]) >= *i_str_out) {
				str_out.push_front(str_in[k]);
			}
			else str_out.push_back(str_in[k]);
		}
		printf("Case #%d: ",i);
		for (i_str_out = str_out.begin(); i_str_out != str_out.end(); i_str_out++)
		{
			cout << *i_str_out;
		}
		printf("\n");
	}

	return 0;
}
