#include <iostream>
#include <string>

using namespace std;

int T;

char t1[20];
char t2[20];
char t3[20];

bool possible(const char *pattern, const char *num, int len)
{
	for (int i = 0; i < len; i++) {
		if (pattern[i] !='?' && pattern != num[i])
			return false;
	}

	return true;
}

bool plus(const chat *pattern, char *input, int len) {
	if (len == 0)
		return false;
	if (pattern[len-1] != '?')
		return false;
	if (input[len-1] == '9') {
		input[len-1] = '0';
		return plus(pattern, input, len - 1);
	}
	else
		input[len-1] = input[len-1] + 1;
}

bool minus(const char *pattern, char *input, int len) {
	if (len == 0)
		return false;
	if (pattern[len-1] != '?')
		return false;
	if (input[len-1] == '0') {
		input[len-1] = '9';
		return minus(pattern, input, len - 1);
	}
	else
		input[len-1] = input[len-1] - 1;
}

void solve(const char *s1, const char *s2)
{
	char c1, c2;
	const char *o1 = s1;
	const char *o2 = s2;
	int tie = 0;
	int i = 0;
	int j;
	while (c1 = *s1++) {
		c2 = *s2++;
		
		if (tie == 0) {
			if (c1 == '?' && c2 == '?') {
				t1[i] = '0';
				t2[i] = '0';
			}
			else if (c1 == '?') {
				t1[i] = c2;
				t2[i] = c2;
			}
			else if (c2 == '?') {
				t1[i] = c1;
				t2[i] = c1;
			}
			else {
				t1[i] = c1;
				t2[i] = c2;

				if (c1 > c2) {
					if (c1 - c2 < 5) {
						tie = 1;
					}
					else {
						for (int j = 0; j < i; j++) {
							t3[j] = t1[j];
						}
						if (minus(o1, t3, i)) {
							for (int j = 0; j < i; j++)
								t1[j] = t3[j];
							tie = -1;
							continue;
						}



						for (int j = 0; j < i; j++) {
							t3[j] = t1[j];
						}
						if (plus(o2, t3, i)) {
							for (int j = 0; j < i; j++)
								t1[j] = t3[j];
							tie = -1;
							continue;
						}

						tie = 1;
					}
				}
				else if (c1 < c2) {
					if (c2 - c1 < 5) {
						tie = -1;
					}
					else {
						for (int j = 0; j < i; j++) {
							t3[j] = t1[j];
						}
						if (minus(o1, t3, i)) {
							for (int j = 0; j < i; j++)
								t1[j] = t3[j];
							tie = 1;
							continue;
						}

						for (int j = 0; j < i; j++) {
							t3[j] = t1[j];
						}
						if (plus(o2, t3, i)) {
							for (int j = 0; j < i; j++)
								t1[j] = t3[j];
							tie = 1;
							continue;
						}

						tie = -1;
					}
				}
			}

		}
		else if (tie == -1) {
			if (c1 == '?' && c2 == '?') {
				t1[i] = '9';
				t2[i] = '0';
			}
			else if (c1 == '?') {
				t1[i] = '9';
				t2[i] = c2;
			}
			else if (c2 == '?') {
				t1[i] = c1;
				t2[i] = '0';
			}
			else {
				t1[i] = c1;
				t2[i] = c2;
			}
		}
		
		else {
			if (c1 == '?' && c2 == '?') {
				t1[i] = '0';
				t2[i] = '9';
			}
			else if (c1 == '?') {
				t1[i] = '0';
				t2[i] = c2;
			}
			else if (c2 == '?') {
				t1[i] = c1;
				t2[i] = '9';
			}
			else {
				t1[i] = c1;
				t2[i] = c2;
			}
		}
		i++;
	}

	t1[i] = 0;
	t2[i] = 0;
}

string tmp1, tmp2;
int main()
{
	cin >> T;
	
	for (int i = 1; i <= T; i++) {
		cin >> tmp1;
		cin >> tmp2;
		solve(tmp1.c_str(), tmp2.c_str());

		cout << "Case #" << i << ": " << t1 << " " << t2 << endl;
	}
}

