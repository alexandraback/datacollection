#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <string.h>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

int T;
string A, B;
vector<string> pali;
vector<string> square_of_pali;

string rev(string s) {
	string res;
	for(int i = s.size() - 1; i >= 0; i--) {
		res += s[i];
	}
	return res;
}

void gen_pal() {
	for(int i = 1; i < 10000; i++) {
		stringstream ss;
		ss << i;
		string s = ss.str();
		string s_cut = s.substr(0, s.size() - 1);
		pali.push_back(s + rev(s));
		pali.push_back(s + rev(s_cut));
	}
}

string square(string s) {
	stringstream ss(s);
	long long val;
	ss >> val;

	stringstream sss;
	sss << val * val;
	string res = sss.str();

	return res;
}

void gen_sq_pal() {
	for(int i = 0; i < pali.size(); i++) {
		square_of_pali.push_back(square(pali[i]));
	}
}

void generate() {
	gen_pal();
	gen_sq_pal();
}

bool is_pali(string s) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}

int comp(string a, string b) {
	if(a.size() != b.size()) {
		return a.size() > b.size() ? 1 : -1;
	} else {
		for(int i = 0; i < a.size(); i++) {
			if(a[i] != b[i]) return a[i] > b[i] ? 1 : -1;
		}
		return 0;
	}
}

bool in_range(string s) {
	return comp(s, A) >= 0 && comp(s, B) <= 0;
}

int main() {
	generate();
	// DEBUG(square_of_pali.size());

	// DEBUG(square("14"));
	// DEBUG(square("4312"));
	// DEBUG()
	cin >> T;
	for(int Ti = 1; Ti <= T; Ti++) {
		cin >> A >> B;
		int res = 0;
		for(int i = 0; i < square_of_pali.size(); i++) {
			if(in_range(square_of_pali[i]) && is_pali(square_of_pali[i])) res++;
		}
		cout << "Case #" << Ti << ": " << res << endl;
	}

    return 0;
}