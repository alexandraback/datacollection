#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

string S;
int freq[0xFF];
int ans[10];

const string numeral[10] = {
	"ZERO", // Z
	"ONE",
	"TWO", // W
	"THREE",
	"FOUR", // U
	"FIVE",
	"SIX", // X
	"SEVEN",
	"EIGHT", // G
	"NINE"};
	
void get(char c, int d) {
	int t = freq[(int)c];
	if ( t> 0)
		cerr << d << " -> " << t << endl;
	
	ans[d] += t;
	for (auto c : numeral[d])
		freq[(int)c] -= t;
}
	
int main() {
	ios_base::sync_with_stdio(0);
	
	int testCount;
	cin >> testCount;
	for (int test = 1; test <= testCount; ++test) {
		
		memset(ans, 0, sizeof(ans));
		memset(freq, 0, sizeof(freq));
		
		cin >> S;
		for (auto c : S)
			++freq[(int)c];
			
		get('Z', 0);
		get('U', 4);
		get('X', 6);
		get('W', 2);
		get('G', 8);
			
		get('O', 1);
		get('F', 5);

		get('T', 3);
		get('I', 9);
		get('S', 7);
		
		cout << "Case #" << test << ": ";
		for (int d = 0; d < 10; ++d)
			for (int i = 0; i < ans[d]; ++i)
				cout << d;
				
		cout << endl;
	}
	
	return 0;
}
