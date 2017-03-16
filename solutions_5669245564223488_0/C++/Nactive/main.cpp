#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
typedef unsigned int uint;
typedef long long vlong;

vector<vlong> faculteit;

vlong bereken(vlong a, vlong b) {
	if (a == 0 && b == 0)
		return 1;

	if (a == 0)
		return b;
	
	if (b == 0)
		return a;
	
	return (a * b) % 1000000007;
}

vlong koppel(vlong a, vlong b) {
	if (a == 0 && b == 0)
		return 1;

	if (a == 0)
		return b;

	if (b == 0)
		return a;

	return (a * b) % 1000000007;
}

void solve(istream& is, uint index)
{
	vector<vlong> hele_strings(26);
	vector<vlong> kopele_strings(26);
	vector<bool> kopel_niet_beginnen(26);
	vector<bool> middel_teken(26);
	for (uint i = 0; i < kopele_strings.size(); i++)
		kopele_strings[i] = 999;

	vector<vlong> resultaten;
	//TODO: Supporteren van deel strings + + geval string is maar 1 character is dit mogelijk ? + strings met 1 teken ondersteunen

	int aantal_string;
	is >> aantal_string;

	bool valid = true;
	for (int i = 0; i < aantal_string; i++) {
		string s;
		is >> s;
		char begin = s[0]; char last = s[s.size() - 1];

		int bk = 0;
		while (bk < s.size() && s[bk] == begin) {
			bk++;
		}

		int ek = s.size() - 1;
		while (ek >= 0 && s[ek] == last) {
			ek--;
		}

		char vorige = 'Z';
		for (int ik = bk; ik <= ek; ik++) {
			int idx = s[ik] - 'a';
			if (vorige != s[ik] && middel_teken[idx] == true) {
				valid = false;
			}

			vorige = s[ik];
			middel_teken[idx] = true;
		}

		middel_teken[begin - 'a'] = true;
		middel_teken[last - 'a'] = true;

		if (begin == last) {
			hele_strings[begin - 'a']++;
		}
		else {
			if (kopele_strings[begin - 'a'] != 999) {
				valid = false;
			}
			for (int l = 0; l < kopele_strings.size(); l++) {
				if (kopele_strings[l] == (last - 'a')) {
					valid = false;
				}
			}

			kopele_strings[begin - 'a'] = last - 'a';
			kopel_niet_beginnen[last - 'a'] = true;
		}
	}

	if (valid) {
		//Hele strigns combo bepalen
		for (uint i = 0; i < hele_strings.size(); i++) {
			hele_strings[i] = faculteit[hele_strings[i]];
		}

		for (uint i = 0; i < hele_strings.size(); i++) {
			uint j = i;
			if (kopel_niet_beginnen[j] == false) {
				vlong sub = hele_strings[j];
				hele_strings[j] = 999999999999;

				while (kopele_strings[j] != 999) {
					j = kopele_strings[j];
					sub = koppel(sub, hele_strings[j]);
					hele_strings[j] = 999999999999;
				}

				if (sub != 0) {
					resultaten.push_back(sub);
				}
			}
		}

		for (uint i = 0; i < hele_strings.size(); i++) {
			if (hele_strings[i] != 999999999999) {
				valid = false;
			}
		}
	}

	vlong resultaat = 0;
	
	if (valid) {
		for (int i = 0; i < resultaten.size(); i++) {
			resultaat = koppel(resultaat, resultaten[i]);
		}
		resultaat = koppel(resultaat, faculteit[resultaten.size()]);
	}
	
	cout << "Case #" << index << ": " << resultaat << endl;
}

void oef(istream& is)
{
	uint n;
	is >> n;
	for (uint i = 0; i < n; i++)
		solve(is, i + 1);
}



int main()
{
	faculteit.push_back(0);
	faculteit.push_back(1);
	faculteit.push_back(2);
	faculteit.push_back(6);
	faculteit.push_back(24);
	faculteit.push_back(120);
	faculteit.push_back(720);
	faculteit.push_back(5040);
	faculteit.push_back(40320);
	faculteit.push_back(362880);
	faculteit.push_back(3628800);

#ifdef EIGENTEST
	ifstream myfile;
	myfile.open("C:\\Users\\Brouckaert\\Desktop\\gcj\\data\\test.txt");
	oef(myfile);
	cin.get();
#else
	ifstream myfile;
	myfile.open("C:\\Users\\Brouckaert\\Desktop\\gcj\\data\\B-small-attempt1.in");
	oef(myfile);
	cin.get();
#endif
	return 0;
}

