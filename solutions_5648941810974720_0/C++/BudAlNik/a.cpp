#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e4 + 5;

int t;
char s[MAXN];

string numbers[10] = {
"ZERO",
"ONE",
"TWO",
"THREE",
"FOUR",
"FIVE",
"SIX",
"SEVEN",
"EIGHT",
"NINE"};

int arr[26];
int ans[10];
		
int setted(int d) {
 	for (char c: numbers[d]) {
 	 	arr[c - 'A'] -= ans[d];
 	}
 	return 0;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &t);

	for (int tn = 0; tn < t; ++tn) {
	 	scanf("%s", s);
	 	int n = strlen(s);
		memset(arr, 0, sizeof arr);

		for (int i = 0; i < n; ++i) {
		 	arr[s[i] - 'A']++;
		}

		memset(ans, 0, sizeof ans);

		ans[0] = arr['Z' - 'A'];
		setted(0);
		//ans[1] = ;
		ans[2] = arr['W' - 'A'];
		setted(2);
		//ans[3] = ;
		ans[4] = arr['U' - 'A'];
		setted(4);
		//ans[5] = ;
		ans[6] = arr['X' - 'A'];
		setted(6);
		//ans[7] = ;
		ans[8] = arr['G' - 'A'];
		setted(8);
		//ans[9] = ;
		ans[3] = arr['R' - 'A'];
		setted(3);
		ans[1] = arr['O' - 'A'];
		setted(1);
		ans[7] = arr['S' - 'A'];
		setted(7);
		ans[9] = arr['N' - 'A'] / 2;
		setted(9);
		ans[5] = arr['F' - 'A'];
		setted(5);
		
        
        cout << "Case #" << tn + 1 << ": ";
        for (int i = 0; i < 10; ++i) {
         	for (int j = 0; j < ans[i]; ++j) {
         	 	cout << i;
         	}
        }
        cout << "\n";
	}

	return 0;
}