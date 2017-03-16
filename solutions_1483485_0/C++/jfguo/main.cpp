#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

map<char, char> m;

string calc()
{
    //string s;
    //cin >> s;

    string line;
    getline(cin, line);
    string s = "";
    for (int i = 0; i < line.length(); ++i) {
        s += m[line[i]];
    }
    return s;
}

string s1 = "yeq ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string s2 = "aoz our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main(void)
{
	int N;
	cin >> N;

    m['z'] = 'q';
    for (int i = 0; i < s1.length(); ++i) {
        m[s1[i]] = s2[i];
    }
    /*
    cout << m.size() << endl;
    for (map<char,char>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << (*it).first << ' ' << (*it).second << endl;
    }
    */

    // NOTE: if using getline() to read the input, the following two lines should be
    // added to read the line sepeartor in the first line. 
    string line;
    getline(cin, line);
	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
