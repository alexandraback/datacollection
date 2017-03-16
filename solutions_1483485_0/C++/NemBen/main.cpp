#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void analize(std::vector<char>& alphabet) {
	std::vector<std::vector<char> > raw;
	std::vector<std::vector<char> > translated;

	std::ifstream in("analize.in");
	std::string str;
	
	int n; in >> n;
	raw.resize(n);

	getline(in,str);
	for (int i = 0; i < n; ++i) {
		getline(in,str);
		for (unsigned int j = 0; j < str.size(); ++j) {
			raw[i].push_back(str[j]);
		}
	}
	translated.resize(n);
	for (int i = 0; i < n; ++i) {
		getline(in,str);
		for (unsigned int j = 0; j < str.size(); ++j) {
			translated[i].push_back(str[j]);
		}
	}

	in.close();

	for (unsigned int i = 0; i < raw.size(); ++i) {
		for (unsigned int j = 0; j < raw[i].size(); ++j) {
			printf("%c",raw[i][j]);
			if (raw[i][j] != ' ') alphabet[raw[i][j]-97] = translated[i][j];
		}
		printf("\n");
	}
	alphabet[16] = 'z';
	alphabet[25] = 'q';
}

void translate(const std::string& raw, std::vector<char>& translated,const std::vector<char>& alphabet) {
	translated.resize(raw.size());
	for (unsigned int i = 0; i < raw.size(); ++i) {
		if (raw[i] != ' ') {
			translated[i] = alphabet[raw[i]-97];
		} else {
			translated[i] = raw[i];
		}
	}
}

void solve(std::string infile, std::string outfile,const std::vector<char>& alphabet) {
	

	std::ifstream in(infile);
	std::ofstream out(outfile);

	std::string raw;

	int cnt; in >> cnt;
	getline(in,raw);

	for (int c = 1; c <= cnt; ++c) {
		getline(in,raw);
		std::vector<char> translated;

		translate(raw,translated,alphabet);

		out << "Case #" << c << ": ";
		for (unsigned int i = 0; i < translated.size(); ++i) {
			out << translated[i];
		}
		out << std::endl;
	}

	out.close();
	in.close();
}

int main() {
	std::vector<char> alphabet; alphabet.resize(26);
	analize(alphabet);

	for (unsigned int i = 0; i < alphabet.size(); ++i) {
		char c = i+97;
		printf("%c -> %c\n",c,alphabet[i]);
	}

	solve("small.in","small.out",alphabet);

	return 0;
}