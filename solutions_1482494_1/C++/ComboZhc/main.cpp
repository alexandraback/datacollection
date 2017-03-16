#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

ifstream in("test.txt");
FILE* out = fopen("answer.txt", "w");

int a[1000], b[1000], c[1000];

void doit(int t) {
	int n;
	in >> n;
	for (int i = 0; i < n; i++) {
		in >> a[i] >> b[i];
		c[i] = 0;
	}
	int nowscore = 0;
	int time = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
			if (b[i] < b[j]) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
			}
	}
	bool find = true;
	while (find && nowscore < 2 * n) {
		find = false;
		for (int i = 0; i < n; i++)
			if (c[i] == 0 && nowscore >= b[i]) {
				++time;
				find = true;
				nowscore += 2;
				c[i] = 2;
				break;
			}
		if (!find)
			for (int i = 0; i < n; i++)
				if (c[i] == 1 && nowscore >= b[i]) {
					++time;
					find = true;
					++nowscore;
					c[i] = 2;
					break;
				} 
		if (!find)
			for (int i = 0; i < n; i++)
				if (c[i] == 0 && nowscore >= a[i]) {
					++time;
					find = true;
					++nowscore;
					c[i] = 1;
					break;
				}
	}
	if (find)
		fprintf(out, "Case #%d: %d\n", t, time);
	else
		fprintf(out, "Case #%d: Too Bad\n", t);
}


int main() {
	int T;
	in >> T;
	for (int i = 1; i <= T; i++) {
		doit(i);
	}
	return 0;
}