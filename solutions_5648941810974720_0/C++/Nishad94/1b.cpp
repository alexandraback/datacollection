#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
//#include <pair>
#include <map>
#define ll long long

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		string s;
		cin >> s;
		map<char,int> char_count;
		for(int i = 0; i < s.size(); ++i)
			char_count[s[i]]++;
		vector<int> num_count(10,0);
		if(char_count['G']){
			num_count[8] += char_count['G'];
			char_count['E'] -= char_count['G'];
			char_count['I'] -= char_count['G'];
			char_count['H'] -= char_count['G'];
			char_count['T'] -= char_count['G'];
			char_count['G'] = 0; 
		}
		if(char_count['U']){
			num_count[4] += char_count['U'];
			char_count['F'] -= char_count['U'];
			char_count['O'] -= char_count['U'];
			char_count['R'] -= char_count['U'];
			char_count['U'] = 0;
		}
		if(char_count['W']){
			num_count[2] += char_count['W'];
			char_count['T'] -= char_count['W'];
			char_count['O'] -= char_count['W'];
			char_count['W'] = 0;
		}
		if(char_count['X']){
			num_count[6] += char_count['X'];
			char_count['S'] -= char_count['X'];
			char_count['I'] -= char_count['X'];
			char_count['X'] = 0;
		}
		if(char_count['Z']){
			num_count[0] += char_count['Z'];
			char_count['E'] -= char_count['Z'];
			char_count['R'] -= char_count['Z'];
			char_count['O'] -= char_count['Z'];
			char_count['Z'] = 0;
		}
		if(char_count['F']){
			num_count[5] += char_count['F'];
			char_count['I'] -= char_count['F'];
			char_count['V'] -= char_count['F'];
			char_count['E'] -= char_count['F'];
			char_count['F'] = 0;
		}
		if(char_count['H']){
			num_count[3] += char_count['H'];
			char_count['T'] -= char_count['H'];
			char_count['R'] -= char_count['H'];
			char_count['E'] -= 2*char_count['H'];
			char_count['H'] = 0;
		}
		if(char_count['S']){
			num_count[7] += char_count['S'];
			char_count['E'] -= 2*char_count['S'];
			char_count['V'] -= char_count['S'];
			char_count['N'] -= char_count['S'];
			char_count['S'] = 0;
		}
		if(char_count['I']){
			num_count[9] += char_count['I'];
			char_count['N'] -= 2*char_count['I'];
			char_count['E'] -= char_count['I'];
			char_count['I'] = 0;
		}
		if(char_count['N']){
			num_count[1] += char_count['N'];
			char_count['O'] -= char_count['N'];
			char_count['E'] -= char_count['N'];
			char_count['N'] = 0;
		}
		cout << "Case #" << t << ": ";
		for(int i = 0; i < 10; ++i)
			for(int j = 0; j < num_count[i]; ++j)
				cout << i;
		cout << endl;
	}
	return 0;
}