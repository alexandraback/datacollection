#include <iostream>
#include <string>
using namespace std;

char M[26];
bool M1[26];
string S1[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string S2[] = {"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"};

int main() {
	freopen("a-small.txt", "r", stdin);
	freopen("a-small-out.txt", "w", stdout);
	int i, j;
	string s1, s2;
	memset(M, -1, sizeof(M));
	memset(M1, false, sizeof(M1));
	M['q' - 'a'] = 'z';
	for(i = 0; i < 3; i++) {
		s1 = S1[i]; s2 = S2[i];
		for(j = 0; j < s1.size(); j++) {
			if (s1[j] != ' ') {
				M[s1[j] - 'a'] = s2[j];
				M1[s2[j] - 'a'] = true;
			}
		}
	}
//	int cnt = 0;
	
	for(i = 'a'; i <= 'z'; i++) if (M[i - 'a'] == -1) break;
	for(j = 'a'; j <= 'z'; j++) if (!M1[j - 'a']) break;
	M[i - 'a'] = j;
	
	int tt;
	cin >> tt; cin.ignore();
	for(int t = 1; t <= tt; t++) {
		getline(cin, s1);
//		cout << s1 << endl;
		for(i = 0; i < s1.size(); i++) {
			s1[i] = (s1[i] == ' ' ? ' ' : M[s1[i] - 'a']);
		}
		cout << "Case #" << t << ": " << s1 << endl;
	}
	
//	system("pause");
    return 0;
}
