// In the Name of Allah
// AD13
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;		//	typedef unsigned long long  ull;
typedef pair <int, int> pii;//	typedef pair <double, double> pdd;
typedef vector <int> VI;
#define MP make_pair
const int INF = 2147483647, MOD = 1000*1000*1000 + 7;
const double eps = 1e-8; // (eps < 1e-15) is the fact (1e-14)
#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
//#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }
void Error(string err) { cout << err; cerr << "_" << err << "_"; exit(0); }
int gcd(int a, int b) { return (b==0)? a: gcd(b, a%b); }
/*-------------------------------------------------------------------------------------*/


/*_____________________________________________________________________________________*/
int main() {
	srand (103);
	int tc1= 0, tc2 = 10000;
	cin >> tc1 >> tc2;
	//*
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	//*/
	int T;
	cin >> T;
	cout.setf(ios::fixed);
	cout.precision(8);
	For1 (tc, T) {
		if (tc < tc1 || tc > tc2) continue;
		cerr << tc << " / " << T << endl;
		int keyboardLen, wordLen, s;
		cin >> keyboardLen >> wordLen >> s;
		string keyboardStr, wordStr;
		cin >> keyboardStr >> wordStr;
		
		double ans = 0;
		if (wordStr.length() <= s) {
			int keyboardCnt[300] = {0}, wordCnt[300] = {0};
			int keyTypeCnt = 0;
			For (i, keyboardStr.length()) {
				if (keyboardCnt[keyboardStr[i]] == 0) keyTypeCnt++;
				keyboardCnt[keyboardStr[i]]++;
			}
			For (i, wordStr.length()) wordCnt[wordStr[i]]++;
			bool canType = true;
			for (int i = 'A'; i <= 'Z'; i++) {
				if (wordCnt[i] != 0 && keyboardCnt[i] == 0) canType = false;
			}
			if (canType && keyTypeCnt > 1) {
				const int REP = 77000111;
				
				if (s == wordLen) {
					double prob = 1;
					For (i, s) {
						prob *= keyboardCnt[wordStr[i]] / (double)(keyboardLen);
					}
					ans = 1 - prob;
				}
				else {
					string str = wordStr, next = wordStr;
					int mx = 1;
				
					For1 (i, wordLen-1) {
						if (wordStr.substr(i, wordLen - i) == wordStr.substr(0, wordLen - i)) {
							next = wordStr.substr(0, i);
							break;
						}
					}
					while (str.length() + next.length() <= s) 
					{
						str += next;
						mx++;
					}
				
					double sum = 0;
					For (rep, REP) {
						string str = "";
						For (i, s) str += keyboardStr[rand () % keyboardLen];
						int cnt = 0;
						For (i, s - wordLen + 1) {
							bool is = true;
							For (j, wordLen)
								if (str[i + j] != wordStr[j]) {
									is = false;
									break;
								}
							if (is) cnt++;
							if (cnt == mx) break;
						}
						sum += cnt;
					}
					ans = mx - sum / REP;
				}
			}
		}

		cout << "Case #" << tc << ": ";
		cout << ans << endl;
	}
	
	return 0;
}
/*
5
7 6 6
BANANAS
MONKEY
2 3 4
AA
AAA
2 1 2
AB
B
6 2 2
GOOGLE
GO
26 11 100
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ROSENCRANTZ

*/