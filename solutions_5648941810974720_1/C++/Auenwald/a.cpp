#include <bits/stdc++.h>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define INTMIN -0x80000000
#define LONGMAX 0x7FFFFFFFFFFFFFFF
#define LONGMIN -0x8000000000000000

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int case_nr=1; case_nr<=T; case_nr++){
		string s;
		cin>>s;
		map<char,int> letters;
		for(int i=0; i<s.length(); i++)
			letters[s[i]]++;
			
		int digits[10];
		
		digits[0] = letters['Z'];
		letters['E'] -= letters['Z'];
		letters['R'] -= letters['Z'];
		letters['O'] -= letters['Z'];
		
		digits[6] = letters['X'];
		letters['S'] -= letters['X'];
		letters['I'] -= letters['X'];
		
		digits[7] = letters['S'];
		letters['E'] -= 2*letters['S'];
		letters['V'] -= letters['S'];
		letters['N'] -= letters['S'];
		
		digits[5] = letters['V'];
		letters['F'] -= letters['V'];
		letters['I'] -= letters['V'];
		letters['E'] -= letters['V'];
		
		digits[2] = letters['W'];
		letters['T'] -= letters['W'];
		letters['O'] -= letters['W'];
		
		digits[4] = letters['F'];
		letters['O'] -= letters['F'];
		letters['U'] -= letters['F'];
		letters['R'] -= letters['F'];
		
		digits[3] = letters['R'];
		letters['T'] -= letters['R'];
		letters['H'] -= letters['R'];
		letters['E'] -= 2*letters['R'];
		
		digits[8] = letters['G'];
		letters['E'] -= letters['G'];
		letters['I'] -= letters['G'];
		letters['H'] -= letters['G'];
		letters['T'] -= letters['G'];
		
		digits[1] = letters['O'];
		letters['N'] -= letters['O'];
		letters['E'] -= letters['O'];
		
		digits[9] = letters['I'];
		
		cout<<"Case #"<<case_nr<<": ";
		for(int i=0; i<10; i++){
			for(int j=0; j<digits[i]; j++)
				cout<<i;
		}
		cout<<"\n";
	}
}