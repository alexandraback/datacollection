#include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int ans[10] = { 0 };
		cout << "Case #" << i << ": ";
		string str;
		cin >> str;
		int alp[200] = { 0 };
		for (char c : str){
			alp[c]++;
		}
		if (alp['Z'] > 0){
			int m = alp['Z'];
			alp['Z'] -= m;
			alp['E'] -= m;
			alp['R'] -= m;
			alp['O'] -= m;
			ans[0] += m;
		}
		if (alp['W'] > 0){
			int m = alp['W'];
			alp['T'] -= m;
			alp['W'] -= m;
			alp['O'] -= m;
			ans[2] += m;
		}
		if (alp['U'] > 0){
			int m = alp['U'];
			alp['F'] -= m;
			alp['O'] -= m;
			alp['U'] -= m;
			alp['R'] -= m;
			ans[4] += m;
		}
		if (alp['X'] > 0){
			int m = alp['X'];
			alp['S'] -= m;
			alp['I'] -= m;
			alp['X'] -= m;
			ans[6] += m;
		}
		if (alp['G'] > 0){
			int m = alp['G'];
			alp['E'] -= m;
			alp['I'] -= m;
			alp['G'] -= m;
			alp['H'] -= m;
			alp['T'] -= m;
			ans[8] += m;
		}
		if (alp['O'] > 0){
			int m = alp['O'];
			alp['O'] -= m;
			alp['N'] -= m;
			alp['E'] -= m;
			ans[1] += m;
		}
		if (alp['F'] > 0){
			int m = alp['F'];
			alp['F'] -= m;
			alp['I'] -= m;
			alp['V'] -= m;
			alp['E'] -= m;
			ans[5] += m;
		}
		if (alp['S'] > 0){
			int m = alp['S'];
			alp['S'] -= m;
			alp['E'] -= m;
			alp['V'] -= m;
			alp['E'] -= m;
			alp['N'] -= m;
			ans[7] += m;
		}
		if (alp['H'] > 0){
			int m = alp['H'];
			alp['T'] -= m;
			alp['H'] -= m;
			alp['R'] -= m;
			alp['E'] -= m;
			alp['E'] -= m;
			ans[3] += m;
		}
		if (alp['I'] > 0){
			int m = alp['I'];
			alp['N'] -= m;
			alp['I'] -= m;
			alp['N'] -= m;
			alp['E'] -= m;
			ans[9] += m;
		}
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < ans[i]; j++){
				cout << i;
			}
		}
		cout << endl;
	}
}