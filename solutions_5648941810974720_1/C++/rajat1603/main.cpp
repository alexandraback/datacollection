#include "bits/stdc++.h"
using namespace std;
int t;
int tc = 0;
string str;
int main(){
	cin >> t;
	while(t--){
		++tc;
		cout << "Case #" << tc << ": "; 
		str = "";
		cin >> str;
		map < char , int > freq;
		freq.clear();
		for(char c : str){
			++freq[c];
		}
		map < int , int > ans;
		ans.clear();
		int x = freq['Z'];
		ans[0] += x;
		freq['Z'] -= x;
		freq['E'] -= x;
		freq['R'] -= x;
		freq['O'] -= x;
		x = freq['G'];
		ans[8] += x;
		freq['E'] -= x;
		freq['I'] -= x;
		freq['G'] -= x;
		freq['H'] -= x;
		freq['T'] -= x;
		x = freq['X'];
		ans[6] += x;
		freq['S'] -= x;
		freq['I'] -= x;
		freq['X'] -= x;
		x = freq['U'];
		ans[4] += x;
		freq['F'] -= x;
		freq['O'] -= x;
		freq['U'] -= x;
		freq['R'] -= x;
		x = freq['F'];
		ans[5] += x;
		freq['F'] -= x;
		freq['I'] -= x;
		freq['V'] -= x;
		freq['E'] -= x;
		x = freq['V'];
		ans[7] += x;
		freq['S'] -= x;
		freq['E'] -= x;
		freq['V'] -= x;
		freq['E'] -= x;
		freq['N'] -= x;
		x = freq['I'];
		ans[9] += x;
		freq['N'] -= x;
		freq['I'] -= x;
		freq['N'] -= x;
		freq['E'] -= x;
		x = freq['W'];
		ans[2] += x;
		freq['T'] -= x;
		freq['W'] -= x;
		freq['O'] -= x;
		x = freq['O'];
		ans[1] += x;
		freq['O'] -= x;
		freq['N'] -= x;
		freq['E'] -= x;
		x = freq['T'];
		ans[3] += x;
		freq['T'] -= x;
		freq['H'] -= x;
		freq['R'] -= x;
		freq['E'] -= x;
		freq['E'] -= x;
		for(auto it : ans){
			int x = it.second;
			while(x--){
				printf("%d" , it.first);
			}
		}
		printf("\n");
	}
}
/*
ZERO (find Z)
EIGHT(find G)
SIX  (find X)
FOUR (find U)
FIVE (find F)
SEVEN(find V)
NINE (find I)
TWO  (find W)
ONE  (find O)
THREE (find T)
*/