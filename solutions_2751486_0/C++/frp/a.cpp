#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isvowel(char c) {
	return c == 'a' || c == 'u' || c == 'e' || c == 'i' || c== 'o';
}

bool iscons(char c) {
	return !isvowel(c);
}

bool check(string& s, int start, int end, int n) {
	int max_c_num = 0;
	bool last_cons = false;
	int c_num = 0;
	for (int i = start; i <= end; i++)
		if (isvowel(s[i])) {
			max_c_num = max(max_c_num, c_num);
			last_cons = false;
			c_num = 0;
		}
		else {
			last_cons = true;
			c_num ++;
		}
	max_c_num = max(max_c_num, c_num);
	return max_c_num >= n;
}

void test(int num) {
	cout << "Case #" << num << ": ";
	string name;
	int n;
	cin >> name >> n;
	int result = 0;
	for (int i = 0; i < name.size(); i++)
		for (int j = i; j < name.size(); j++)
			if(check(name, i, j, n))
				result++;
	cout << result << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		test(i+1);
}
