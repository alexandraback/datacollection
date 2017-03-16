#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

map<char, map<char, char> > next;
map<char, map<char, bool> > negative;

void init(){
	next['1']['1'] = '1';
	next['1']['i'] = 'i';
	next['1']['j'] = 'j';
	next['1']['k'] = 'k';

	next['i']['1'] = 'i';
	next['i']['i'] = '1';
	next['i']['j'] = 'k';
	next['i']['k'] = 'j';

	next['j']['1'] = 'j';
	next['j']['i'] = 'k';
	next['j']['j'] = '1';
	next['j']['k'] = 'i';
	
	next['k']['1'] = 'k';
	next['k']['i'] = 'j';
	next['k']['j'] = 'i';
	next['k']['k'] = '1';

	negative['i']['i'] = true;
	negative['i']['k'] = true;
	negative['j']['i'] = true;
	negative['j']['j'] = true;
	negative['k']['j'] = true;
	negative['k']['k'] = true;
}

bool ex_or(bool a, bool b){
	return a != b;
}

string solve_small(string s, int X){
	string result;
	for(int i = 0; i < X; ++i){
		result = result.append(s);
	}
	char curr = '1';
	bool curr_negative = false;

	bool i_reached = false;
	bool j_reached = false;
	for(int i = 0; i < result.size(); ++i){
		char new_str= next[curr][result[i]];
		bool new_negative = ex_or(negative[curr][result[i]], curr_negative);

		//cout << "now: " << (curr_negative?"-":"") << curr  << endl;
		if(!i_reached && (new_str == 'i' && !new_negative)){
			i_reached = true;
		}else if(i_reached && !j_reached && (new_str == 'k' && !new_negative)){
			j_reached = true;
		}
	
		curr = new_str;
		curr_negative = new_negative;
	}
	if(i_reached && j_reached && curr == '1' && curr_negative){
		return "YES";
	}
	return "NO";
}

int main(){
	init();
	std::ios::sync_with_stdio(false);
	int nb_testcases; cin >> nb_testcases;
	for(int current_case = 1; current_case <= nb_testcases; ++current_case){
		int L, X;
		cin >> L >> X;
		string s;
		cin >> s;
		//cout << s << endl;
		cout << "Case #" << current_case << ": " << solve_small(s, X) << endl;
	}

    return 0;
}
