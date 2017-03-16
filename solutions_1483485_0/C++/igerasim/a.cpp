#include <memory>
#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[])
{
	char g2s[256];
	memset(g2s, 'q', sizeof(g2s));
	char* samples_s[4];
	char* samples_g[4];
	samples_s[0] = "a zoo";
	samples_s[1] = "our language is impossible to understand";
	samples_s[2] = "there are twenty six factorial possibilities";
	samples_s[3] = "so it is okay if you want to just give up";
	samples_g[0] = "y qee";
	samples_g[1] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	samples_g[2] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	samples_g[3] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	for (int i = 0; i != 4; ++i) {
		for (const char* s = samples_s[i], * g = samples_g[i]; *s; ++s, ++g) {
			g2s[*g] = *s;
		}
	}
	char buff[128];
	int T;
	cin >> T;
	cin.getline(buff, 128); // skip the new line char
	for (int t = 0; t != T; ++t) {
		cin.getline(buff, 128);
		for (char* b = buff; *b; ++b) {
			*b = g2s[*b];
		}
		cout << "Case #" << (t + 1) << ": " << buff << endl;
	}
	return 0;
}

