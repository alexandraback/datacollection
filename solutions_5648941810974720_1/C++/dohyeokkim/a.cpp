#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t, tmp;
	string s; 
	vector<char> ans;
	vector<int> data;

	scanf("%d", &t);

	for (int i = 0; i < t; i++){
		cin >> s;
		int len = s.length();
		data.resize(26);
		for (int j = 0; j < len; j++){
			data[s[j] - 'A']++;
		}
		
		//0
		tmp = data['Z' - 'A'];
		data['E' - 'A'] -= tmp;
		data['R' - 'A'] -= tmp;
		data['O' - 'A'] -= tmp;
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('0');

		//2
		tmp = data['W' - 'A'];
		data['T' - 'A'] -= tmp;
		data['O' - 'A'] -= tmp;
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('2');
		
		//4
		tmp = data['U' - 'A'];
		data['O' - 'A'] -= tmp;
		data['F' - 'A'] -= tmp;
		data['R' - 'A'] -= tmp;
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('4');
		
		//6
		tmp = data['X' - 'A'];
		data['S' - 'A'] -= tmp;
		data['I' - 'A'] -= tmp;		
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('6');
		
		//8
		tmp = data['G' - 'A'];
		data['E' - 'A'] -= tmp;
		data['I' - 'A'] -= tmp;		
		data['H' - 'A'] -= tmp;		
		data['T' - 'A'] -= tmp;		
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('8');
		
		//5
		tmp = data['F' - 'A'];
		data['I' - 'A'] -= tmp;
		data['V' - 'A'] -= tmp;		
		data['E' - 'A'] -= tmp;		
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('5');

		//7
		tmp = data['S' - 'A'];
		data['E' - 'A'] -= tmp;
		data['V' - 'A'] -= tmp;		
		data['E' - 'A'] -= tmp;		
		data['N' - 'A'] -= tmp;		
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('7');

		//1
		tmp = data['O' - 'A'];
		data['N' - 'A'] -= tmp;
		data['E' - 'A'] -= tmp;		
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('1');

		//3
		tmp = data['T' - 'A'];
		data['H' - 'A'] -= tmp;
		data['R' - 'A'] -= tmp;		
		data['E' - 'A'] -= tmp;		
		data['E' - 'A'] -= tmp;		
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('3');

		//9
		tmp = data['I' - 'A'];
		data['N' - 'A'] -= tmp;
		data['N' - 'A'] -= tmp;		
		data['E' - 'A'] -= tmp;		
		for (int j = 0 ; j < tmp; j++)
			ans.push_back('9');

		sort(ans.begin(), ans.end());
		string res = "";
		for (vector<char>::iterator i = ans.begin(); i != ans.end(); i++){
			res += *i;
		}
		printf("Case #%d: %s\n", i + 1, res.c_str());
		
		ans.clear();
		data.clear();
	}


	return 0;
}
