#define INPUT "test.in"
#define OUTPUT "test.out"

#include <fstream>
#include <string>

using namespace std;

void get_mapping(string encoded, string decoded, char mapping[])
{
	int inverse[26];

	for (int i = 0; i < 26; i++) inverse[i] = -1;

	for (int i = 0, l = encoded.length(); i < l; i++) {
		if (encoded[i] == ' ') continue;
		mapping[encoded[i] - 'a'] = decoded[i];
		inverse[decoded[i] - 'a'] = encoded[i] - 'a';
	}


	for (int i = 0; i < 26; i++) {
		if (!mapping[i]) {
			for (int j = 0; j < 26; j++) {
				if (inverse[j] == -1) {
					mapping[i] = char('a' + j);
				}
			}
		}
	}
}

void print(string res, int i, ofstream &ouf)
{
	ouf << "Case #" << i << ": " << res << endl;
}

string translate(string s, char mapping[])
{
	for (int i = 0, l = s.length(); i < l; i++) {
		if (s[i] != ' ') s[i] = mapping[s[i] - 'a'];
	}
	return s;
}

void work(char mapping[])
{
	ifstream inf(INPUT);
	ofstream ouf(OUTPUT);

	int t;
	string s, res;
	inf >> t;
	getline(inf ,s);	
	for (int i = 0; i < t; i++) {
		getline(inf, s);
		res = translate(s, mapping);
		print(res, i + 1, ouf);
	}
}

int main()
{
	string encoded = "aoz ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string decoded = "yeq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	char mapping[26];
	get_mapping(encoded, decoded, mapping);

	work(mapping);

	return 0;
}


