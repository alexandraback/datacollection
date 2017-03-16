#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <fstream>

using namespace std;

#define PQ priority_queue
typedef long long LL;
typedef pair<LL,LL> pll;
bool check_digit[10];

void init() {
	for (int i=0;i<10;i++)
		check_digit[i] = false;
}

void parse_digit(int n) {
	while (n>0) {
		check_digit[n%10] = true;
		n /= 10;
	}
}

bool is_asleep() {
	for (int i=0;i<10;i++)
		if (!check_digit[i]) return false;
	return true;
}

int main() {
	int T,N;
	ifstream file_in ("A-large.in");
	ofstream file_out ("A-large.txt");
	file_in>> T;
	for (int i=0;i<T;i++) {
		file_in >> N;
		init();
		file_out << "Case #" << i+1 << ": ";
		if (N==0) file_out << "INSOMNIA\n";
		else {
			int count = 1,tmp = N;
			while (true) {
				parse_digit(tmp);
				count++;
				if (is_asleep()) {
					file_out << tmp << endl;
					break;
				}
				tmp += N;
			}
		}
	}
	return 0;

}
