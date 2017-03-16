#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long absl(long long a, long long b) {
	if(a >= b) return a - b;
	else return b - a;
}

pair<long long, pair<string, string> > candidate(string a, string b, int ptr) {
	for(int j = 0; j < ptr; j++) {
		if(a[j] == '?' && b[j] == '?') {
			a[j] = b[j] = '0';
		} else if(a[j] == '?') {
			a[j] = b[j];
		} else if(b[j] == '?') {
			b[j] = a[j];
		}
	}

	if(a[ptr] == '?' && b[ptr] == '?') {
		a[ptr] = '0';
		b[ptr] = '1';
	} else if(b[ptr] > '0' && a[ptr] == '?') {
		a[ptr] = b[ptr] - 1;
	} else if(a[ptr] < '9' && b[ptr] == '?') {
		b[ptr] = a[ptr] + 1;
	} else if(a[ptr] != '?' && b[ptr] != '?' && a[ptr] < b[ptr]) {
		// do nothing
	} else {
		return pair<long long, pair<string, string> >(-1, pair<string, string>("", ""));
	}
	

	long long va, vb;
	va = vb = 0;
	long long digit = 1;
	for(int i = a.size() - 1; i > ptr; i--) {
		if(a[i] == '?') {
			va += (digit * 9);
			a[i] = '9';
		} else {
			va += ((a[i] - '0') * digit);
		}
		if(b[i] == '?') {
			b[i] = '0';
		} else {
			vb += ((b[i] - '0') * digit);
		}
		digit *= 10;
	}
	va += (a[ptr] * digit);
	vb += (b[ptr] * digit);

	return pair<long long, pair<string, string> >(absl(va, vb), pair<string, string>(a, b));
}

int main(int argc, char** argv) {

	int t;

	cin >> t;

	for(int i = 1; i <= t; i++) {
		string a, b;
		cin >> a >> b;
		long long digit = 1;
		int n = a.size();
		int ptr = n;
		pair<string, string> answer;

		for(int j = 0; j < n; j++) {
			if(a[j] != '?' && b[j] != '?' && a[j] != b[j]) {
				ptr = j;
				break;
			}
		}

		if(ptr < n) {
			long long diff = -1;
			pair<long long, pair<string, string> > res;
			for(int j = ptr; j >= 0; j--) {
				res = candidate(a, b, j);
				if(res.first != -1 && (diff == -1 || res.first < diff || (res.first == diff && (res.second.first < answer.first || (res.second.first == answer.first && res.second.second < answer.second))))) {
					diff = res.first;
					answer = res.second;
				}
				res = candidate(b, a, j);
				if(res.first != -1 && (diff == -1 || res.first < diff || (res.first == diff && (res.second.second < answer.first || (res.second.second == answer.first && res.second.first < answer.second))))) {
					diff = res.first;
					answer = pair<string, string>(res.second.second, res.second.first);
				}
			}
		} else {
			for(int j = 0; j < n; j++) {
				if(a[j] == '?' && b[j] == '?') {
					a[j] = b[j] = '0';
				} else if(a[j] == '?') {
					a[j] = b[j];
				} else if(b[j] == '?') {
					b[j] = a[j];
				}
			}
			answer.first = a;
			answer.second = b;
		}

		cout << "Case #" << i << ": " << answer.first << " " << answer.second << endl;
	}

	return 0;
}
