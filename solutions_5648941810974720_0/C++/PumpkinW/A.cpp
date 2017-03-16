#include <stdio.h>
#include <iostream>
using namespace std;

string numbers[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int counter[26];
int answer[10];
int main(){	
    
    freopen("in.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
	int T;
	cin >> T;
	
	string tmp;
	for(int t = 1; t <= T; ++t){
		cin >> tmp;
		for(int i = 0; i <= 25; ++i){
			counter[i] = 0;
		}
		
		for(int i =0; i <= 9; ++i){
			answer[i] = 0;
		}
		
		for(int j = 0; j < tmp.length(); ++j){
			counter[tmp[j]-'A']++;
		}
		
		while(counter['Z'-'A'] > 0){
			answer[0]++;
			counter['Z' - 'A']--;
			counter['E' - 'A']--;
			counter['R' - 'A']--;
			counter['O' - 'A']--;
		}
		
		while(counter['U'-'A'] > 0){
			answer[4]++;
			counter['F' - 'A']--;
			counter['O' - 'A']--;
			counter['U' - 'A']--;
			counter['R' - 'A']--;
		}
		
		while(counter['X'-'A'] > 0){
			answer[6]++;
			counter['S' - 'A']--;
			counter['I' - 'A']--;
			counter['X' - 'A']--;
		}
		
		while(counter['W'-'A'] > 0){
			answer[2]++;
			counter['T' - 'A']--;
			counter['W' - 'A']--;
			counter['O' - 'A']--;
		}
		
		while(counter['G'-'A'] > 0){
			answer[8]++;
			counter['E' - 'A']--;
			counter['G' - 'A']--;
			counter['H' - 'A']--;
			counter['I' - 'A']--;
			counter['T' - 'A']--;
		}
		
		while(counter['S'-'A'] > 0){
			answer[7]++;
			counter['S' - 'A']--;
			counter['E' - 'A']--;
			counter['V' - 'A']--;
			counter['E' - 'A']--;
			counter['N' - 'A']--;
		}
		
		while(counter['O'-'A'] > 0){
			answer[1]++;
			counter['O' - 'A']--;
			counter['N' - 'A']--;
			counter['E' - 'A']--;
		}
		
		while(counter['N'-'A'] > 0){
			answer[9]++;
			counter['N' - 'A']--;
			counter['I' - 'A']--;
			counter['N' - 'A']--;
			counter['E' - 'A']--;
		}
		
		while(counter['F'-'A'] > 0){
			answer[5]++;
			counter['F' - 'A']--;
			counter['I' - 'A']--;
			counter['V' - 'A']--;
			counter['E' - 'A']--;
		}
		
		while(counter['T'-'A'] > 0){
			answer[3]++;
			counter['T' - 'A']--;
			counter['H' - 'A']--;
			counter['E' - 'A'] -= 2;
			counter['R' - 'A']--;
		}
		
		cout << "Case #" << t << ": ";
		
		for(int i = 0; i <= 9; ++i){
			for(int j = 0; j < answer[i]; ++j){
				cout << i;
			}
		}
		cout << endl;
	}
	
	return 0;
}
