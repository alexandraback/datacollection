										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int dig[10] = {0, 2, 6, 7, 8, 5, 4, 1, 3, 9};
char sg[10] = {'Z', 'W', 'X', 'S', 'G', 'V', 'F', 'O', 'H', 'I'};
string name[10] = {"ZERO", "TWO", "SIX", "SEVEN", "EIGHT", "FIVE", "FOUR", "ONE", "THREE", "NINE"};
int cnt[30];

int main(){
	freopen("A. Getting the Digits.in", "r", stdin);
	freopen("A. Getting the Digits.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		string str, res;
		cin >> str;
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < str.length(); i++)
			cnt[str[i] - 'A']++;
		for(int i = 0; i < 10; i++){
			int sz = cnt[sg[i] - 'A'];
			for(int j = 0; j < sz; j++){
				res += (char)(dig[i] + '0');
				for(int k = 0; k < name[i].length(); k++)
					cnt[name[i][k] - 'A']--;
			}
		}
		sort(res.begin(), res.end());
		cout << "Case #" << ++test << ": " << res << endl;
	}
	return 0;
}
