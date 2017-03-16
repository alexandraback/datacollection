#include <iostream>
#include <fstream>
using namespace std;

	#define cin fin
	#define cout fout
	ifstream fin("A-small-attempt3.in");
	ofstream fout("A.out");

char s1[] =
"ejp mysljylc kd kxveddknmc re jsicpdrysi"
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
"de kr kd eoya kw aej tysr re ujdr lkgc jv";
char s2[] =
"our language is impossible to understand"
"there are twenty six factorial possibilities"
"so it is okay if you want to just give up";
char t[128];
char s[1000];

int main() {
	for (int i=0; i<128; ++i) t[i] = i;
	for (int i=0; s1[i]; ++i) t[s1[i]] = s2[i];
	t['z'] = 'q';
	t['q'] = 'z';

	int cn = 1;
	int cs; cin >> cs; cin.ignore(100, '\n');
	while (cs--) {
		cin.getline(s, 1000);
		cout << "Case #" << cn++ << ": ";
		for (int i=0; s[i]; ++i)
			cout << t[s[i]];
		cout << endl;
	}
	system("pause");
	return 0;
}
