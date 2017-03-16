#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, m;

const string ss[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

const int list[] = {0, 2, 6, 8, 3, 4, 7, 5, 1, 9};
const int c[] = {'Z', 'W', 'X', 'G', 'H', 'U', 'S', 'F', 'O', 'I'};

int a[10][30];

int main(){
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 10; i ++){
		for (int j = 0; j < ss[i].size(); j++){
			a[i][ss[i][j]-'A'] ++;
		}
	}
	/*
	for (int i = 0; i < 10; i++){
		if (i == 0 || i == 8 || i == 6 || i == 2) continue;
		if (i == 3 || i == 7 || i == 4) continue;
		cout << i << "---------";
		for (int j = 0; j < 26; j++) 
			cout << char(j+'A') << '-' << a[i][j] << ' ';
		cout << endl;
	}
	*/
	int tt; cin >> tt;
	for (int cas = 1; cas <= tt; cas++){
		cout << "Case #" << cas << ":" << ' ';
		string s; cin >> s;
		int b[30] = {0};
		for (int i = 0; i < s.size(); i++) b[s[i]-'A'] ++;
		int num[10] = {0};
		
		for (int i = 0; i < 10; i ++){
			int now = list[i];
			int ccc = c[i] - 'A';
			int sum = b[ccc];
			num[now] = sum;
			for (int j = 0; j < 30; j ++) b[j] -= sum * a[now][j];
		}
		
		string ans;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < num[i]; j++) ans += i + '0';
		}
		cout << ans << endl;
	}
	return 0;
}