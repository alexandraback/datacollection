#include <iostream>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

int t;

char cal(char first, char second) {	// h = 1, n = -1, o = -i, p = -j, q = -k
	if(first == 'h') 
		return second;
	if(first == 'i') {
		if(second == 'h')
			return 'i';
		if(second == 'i')
			return 'n';
		if(second == 'j')
			return 'k';
		if(second == 'k')
			return 'p';
		if(second == 'n')
			return 'o';
		if(second == 'o')
			return 'h';
		if(second == 'p')
			return 'q';
		if(second == 'q')
			return 'j';
	}
	if(first == 'j') {
		if(second == 'h')
			return 'j';
		if(second == 'i')
			return 'q';
		if(second == 'j')
			return 'n';
		if(second == 'k')
			return 'i';
		if(second == 'n')
			return 'p';
		if(second == 'o')
			return 'k';
		if(second == 'p')
			return 'h';
		if(second == 'q')
			return 'o';
	}
	if(first == 'k') {
		if(second == 'h')
			return 'k';
		if(second == 'i')
			return 'j';
		if(second == 'j')
			return 'o';
		if(second == 'k')
			return 'n';
		if(second == 'n')
			return 'q';
		if(second == 'o')
			return 'p';
		if(second == 'p')
			return 'i';
		if(second == 'q')
			return 'h';
	}
	if(first == 'n') {
		if(second == 'h')
			return 'n';
		if(second == 'i')
			return 'o';
		if(second == 'j')
			return 'p';
		if(second == 'k')
			return 'q';
		if(second == 'n')
			return 'h';
		if(second == 'o')
			return 'i';
		if(second == 'p')
			return 'j';
		if(second == 'q')
			return 'k';
	}
	if(first == 'o') {
		if(second == 'h')
			return 'o';
		if(second == 'i')
			return 'h';
		if(second == 'j')
			return 'q';
		if(second == 'k')
			return 'j';
		if(second == 'n')
			return 'i';
		if(second == 'o')
			return 'n';
		if(second == 'p')
			return 'k';
		if(second == 'q')
			return 'p';
	}
	if(first == 'p') {
		if(second == 'h')
			return 'p';
		if(second == 'i')
			return 'k';
		if(second == 'j')
			return 'h';
		if(second == 'k')
			return 'o';
		if(second == 'n')
			return 'j';
		if(second == 'o')
			return 'q';
		if(second == 'p')
			return 'n';
		if(second == 'q')
			return 'i';
	}
	if(first == 'q') {
		if(second == 'h')
			return 'q';
		if(second == 'i')
			return 'p';
		if(second == 'j')
			return 'i';
		if(second == 'k')
			return 'h';
		if(second == 'n')
			return 'k';
		if(second == 'o')
			return 'j';
		if(second == 'p')
			return 'o';
		if(second == 'q')
			return 'n';
	}
}

bool total_product(string s, long long x) {
	int len = s.size();
	char result = s[0];
	for(int i = 1; i < len; ++i) {
		result = cal(result, s[i]);
	}
//	cout << "result: " << result << ", x: " << x << endl;
	if(result == 'h')
		return false;
	if(result == 'n') {		
		if(x % 2 == 0)
			return false;
		else
			return true;
	}
	if(x % 4 == 2)
		return true;
	return false;
}

int main() {

	ifstream fin("C-small-attempt2.in", ifstream::in);
	ofstream fout("result.out", ofstream::out);
	fin >> t;
//	cin >> t;
	int l;
	long long x;
	string s;
	bool get_i = false, get_j = false;
	char result = 'h';
	for(int i = 0; i < t; ++i) {
		fin >> l >> x >> s;
//		cin >> l >> x >> s;
//		cout << "l: " << l << ", x: " << x << endl;
		
		if(l * x < 3) {
			cout << "Case #" << (i+1) << ": " <<  "NO" << endl;
			fout << "Case #" << (i+1) << ": " <<  "NO" << endl;
			continue;
		}
		if(s.find('i') == string::npos && s.find('j') == string::npos || s.find('j') == string::npos && s.find('k') == string::npos
			|| s.find('k') == string::npos && s.find('i') == string::npos) {
			cout << "Case #" << (i+1) << ": " <<  "NO" << endl;
			fout << "Case #" << (i+1) << ": " <<  "NO" << endl;
			continue;
		}
		get_i = false, get_j = false;
		result = 'h';
		if(total_product(s, x)) {			
			for(int j = 0; j < x; ++j) {
				for(int k = 0; k < l; ++k) {
					result = cal(result, s[k]);
					if(!get_i) {						
						if(result == 'i') {
							get_i = true;
							result = 'h';
						}
					}
					else {
						if(result == 'j') {
							get_j = true;
							goto success;
						}
					}
				}
			}
		}
		else {
			cout << "Case #" << (i+1) << ": " <<  "NO" << endl;
			fout << "Case #" << (i+1) << ": " <<  "NO" << endl;
			continue;
		}
success:
		if(get_i && get_j) {
			cout << "Case #" << (i+1) << ": " <<  "YES" << endl;
			fout << "Case #" << (i+1) << ": " <<  "YES" << endl;
		}
		else {
			cout << "Case #" << (i+1) << ": " <<  "NO" << endl;
			fout << "Case #" << (i+1) << ": " <<  "NO" << endl;
		}
	}
	
	return 0;
}
