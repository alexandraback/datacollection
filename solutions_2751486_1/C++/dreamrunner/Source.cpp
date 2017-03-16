using namespace std;

#include <iostream>
#include <cmath>

int isV(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

int findCon(char name[1000000], int l, int n, int start) {
	int position = 0, con = 0, num = 0;
	if (start) {
		position = n - 1;
		con = n - 1;
	}
	while (position < l) {
		//cout << name[position] << endl;
		if (!isV(name[position])) {
			con++;
			if (con == n) {
				return position - n + 1;
			}
		} else {
			con = 0;
		}
		position++;
	}
	return -1;
}

long long solve(char name[1000000], int l, int n) {
	int appear = 0;
	int position = 0, first = -1, current;
	long long total = 0;
	while ((current= findCon(name + position, l - position, n, appear)) > -1) {
		position += current;
		//cout << "position " << position << endl;
		total += (long long)(position + 1) * (l - position - n + 1);
		if (appear) {
			//cout << "total_1 " << total << endl;
			total -= (long long)(first + 1) * (l - position - n + 1);
		} else {
		}
		//cout << "total " << total << endl;
		first = position;
		appear++;
		position++;
	}
	return total;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 1; test < tests + 1; test++) {
		int l = 0, n = 0;
		char readchar, name[1000000];
		readchar = getchar();
		readchar = getchar();
		while (readchar != ' ') {
			//cout << readchar << endl;
			name[l] = readchar;
			l++;
			readchar = getchar();
		}
		cin >> n;
		cout << "Case #" << test << ": " << solve(name, l, n) << endl;
		//cout << "Case #" << test << ": " << 0 << endl;
	}
	return 0;
}