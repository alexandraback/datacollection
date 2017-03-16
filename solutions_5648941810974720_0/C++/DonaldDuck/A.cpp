// Problem A

#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <fstream>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;

void TestCase(int t);

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
		TestCase(t);
	
	return 0;
}

void TestCase(int t) {
	char str[3000];
	cin >> str;
	int l = strlen(str);
	
	int conta[26];
	for (int i=0; i<26; i++) conta[i] = 0;
	for (int i=0; i<l; i++) conta[str[i]-'A']++;
	
	int tel[10];
	tel[0] = conta['Z'-'A'];
	tel[1] = conta['O'-'A'] - conta['Z'-'A'] - conta['W'-'A'] - conta['U'-'A'];
	tel[2] = conta['W'-'A'];
	tel[3] = conta['H'-'A'] - conta['G'-'A'];
	tel[4] = conta['U'-'A'];
	tel[5] = conta['F'-'A'] - conta['U'-'A'];
	tel[6] = conta['X'-'A'];
	tel[7] = conta['V'-'A'] - conta['F'-'A'] + conta['U'-'A'];
	tel[8] = conta['G'-'A'];
	tel[9] = conta['I'-'A'] - conta['G'-'A'] - conta['X'-'A'] - conta['F'-'A'] + conta['U'-'A'];
	
	cout << "Case #" << t << ": ";
	for (int i=0; i<10; i++)
		for (int j=0; j<tel[i]; j++)
			cout << i;
			
	cout << endl;
}
