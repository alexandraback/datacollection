#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string>
#include <set>
using namespace std;

int K, L, S;
string KEY, TARGET;

int get_overwrap(string s)
{
	const char* p = s.c_str();
	size_t length = s.size();
	for (int i = 1; i < length; i++) {
		if (strncmp(p, p + i, length - i) == 0) {
			return (int) (length - i);
		}
	}
	return 0;
}

int total;
int hit;
void makeall_impl(char* p, int pos)
{
	if (pos == S) {
		total++;
		for (int i = 0; i <= S - L; i++) {
			if (strncmp(p + i, TARGET.c_str(), L) == 0) {
				hit++;
			}
		}
		return;
	}
	for (int i = 0; i < KEY.size(); i++) {
		p[pos] = KEY[i];
		makeall_impl(p, pos + 1);
	}
}

void makeall()
{
	total = 0;
	hit = 0;
	char buffer[10] = {};
	makeall_impl(buffer, 0);
}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		FILE* fp;
		freopen_s(&fp, argv[1], "r", stdin);
	}

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> K >> L >> S;
		cin >> KEY >> TARGET;

		makeall();
		if (hit == 0) {
			cout << "Case #" << t << ": 0.0" << endl;
		} else {
			int overwrap = get_overwrap(TARGET);
			int maxr = (S - overwrap) / (L - overwrap);
			float result = maxr - ((float) hit / total);
			printf("Case #%d: %0.7f\n", t, result);
			//cout << "Case #" << t << ": " << result << endl;
		}
		
	}

	return 0;
}
