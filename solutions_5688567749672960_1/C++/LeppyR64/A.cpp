#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int mz[15] = {0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};

string sub1(string a) {
	string b = "1";
	while(b.size() < a.size())
		b += "0";
	if(a == b) {
		b = "";
		while(b.size() < a.size() - 1)
			b = b + "9";
		return b;
	}
	else {
		int x = a.size()-1;
		while(a[x] == '0')
			a[x--] = '9';
		a[x] = a[x] - 1;
		return a;
	}
}

bool is101(string a) {
	string b = "1";
	while(b.size() < a.size()-1)
		b += "0";
	b += "1";
	return a == b;
}


long long dist(string a) {
	long long result = 0;
	if(a == "1")
		result = 1;
	else if(a[a.size()-1] == '0') {
		result = 1;
		result += dist(sub1(a));
	}
	else if(a[a.size()-1] != '1') {
		string b = a;
		result = b[b.size()-1] - '1';
		b[b.size()-1] = '1';
		result += dist(b);
	}
	else if(is101(a)) {
		result = 2;
		result += dist(sub1(sub1(a)));
	}
	else {
		string b = a;
		for(int x = 1, z = 10; x <= mz[b.size()]; x++, z *= 10) {
			result += (b[b.size()-1-x] - '0') * z;
			b[b.size()-1-x] = '0';
		}
		reverse(b.begin(), b.end());
		if(is101(b))
			result += dist(b);
		else
			result += 1 + dist(b);
	}
	// cout << a << " " << result << endl;
	return result;
}

int main() {
	int T;
	string N;
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		cin >> N;
		cout << "Case #" << Z << ": " << dist(N) << endl;
	}
}