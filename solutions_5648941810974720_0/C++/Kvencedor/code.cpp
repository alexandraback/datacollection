#include  <bits/stdc++.h>
using namespace std;

int main(){
	int casos;
	int letras[40];
	vector<int> num;
	cin >> casos;

	for(int caso = 1; caso <= casos; caso++){
		string s;
		cin >> s;
		memset(letras, 0, sizeof letras);
		for(int i = 0; i < s.length(); i++)
			letras[s[i] - 'A']++;

		int n = s.length();
		num.clear();

		if(letras['Z' - 'A']){
			int t = letras['Z' - 'A'];
			letras['Z' - 'A'] -= t;
			letras['E' - 'A'] -= t;
			letras['R' - 'A'] -= t;
			letras['O' - 'A'] -= t;
			while(t--)
				num.push_back(0);
		}
		
		if(letras['W' - 'A']){
			int t = letras['W' - 'A'];
			letras['T' - 'A'] -= t;
			letras['W' - 'A'] -= t;
			letras['O' - 'A'] -= t;
			while(t--)
				num.push_back(2);
		}

		if(letras['U' - 'A']){
			int t = letras['U' - 'A'];
			letras['F' - 'A'] -= t;
			letras['O' - 'A'] -= t;
			letras['U' - 'A'] -= t;
			letras['R' - 'A'] -= t;
			while(t--)
				num.push_back(4);
		}

		if(letras['F' - 'A']){
			int t = letras['F' - 'A'];
			letras['F' - 'A'] -= t;
			letras['I' - 'A'] -= t;
			letras['V' - 'A'] -= t;
			letras['E' - 'A'] -= t;
			while(t--)
				num.push_back(5);
		}

		if(letras['V' - 'A']){
			int t = letras['V' - 'A'];
			letras['S' - 'A'] -= t;
			letras['E' - 'A'] -= t;
			letras['V' - 'A'] -= t;
			letras['E' - 'A'] -= t;
			letras['N' - 'A'] -= t;
			while(t--)
				num.push_back(7);
		}

		if(letras['S' - 'A']){
			int t = letras['S' - 'A'];
			letras['S' - 'A'] -= t;
			letras['I' - 'A'] -= t;
			letras['X' - 'A'] -= t;
			while(t--)
				num.push_back(6);
		}

		if(letras['O' - 'A']){
			int t = letras['O' - 'A'];
			letras['O' - 'A'] -= t;
			letras['N' - 'A'] -= t;
			letras['E' - 'A'] -= t;
			while(t--)
				num.push_back(1);
		}

		if(letras['R' - 'A']){
			int t = letras['R' - 'A'];
			letras['T' - 'A'] -= t;
			letras['H' - 'A'] -= t;
			letras['R' - 'A'] -= t;
			letras['E' - 'A'] -= t;
			letras['E' - 'A'] -= t;
			while(t--)
				num.push_back(3);
		}

		if(letras['H' - 'A']){
			int t = letras['H' - 'A'];
			letras['E' - 'A'] -= t;
			letras['I' - 'A'] -= t;
			letras['G' - 'A'] -= t;
			letras['H' - 'A'] -= t;
			letras['T' - 'A'] -= t;
			while(t--)
				num.push_back(8);
		}

		if(letras['I' - 'A']){
			int t = letras['I' - 'A'];
			letras['N' - 'A'] -= t;
			letras['I' - 'A'] -= t;
			letras['N' - 'A'] -= t;
			letras['E' - 'A'] -= t;
			while(t--)
				num.push_back(9);
		}

		sort(num.begin(), num.end());

		printf("Case #%d: ", caso);
		for(auto it = num.begin(); it != num.end(); it++)
			printf("%d", *it);
		printf("\n");
	}
}