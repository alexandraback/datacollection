#include <bits/stdc++.h>
using namespace std;

/*
( "THREE", "NINE"
*/
string solve(string s){
	int num[10] = {};
	map<char,int> memo;
	for(auto c : s ) memo[c]++;
	
	num[6] = memo['X'];
	memo['S'] -= num[6];
	memo['I'] -= num[6];
	memo['X'] -= num[6];
	num[0] = memo['Z'];
	memo['Z'] -= num[0];
	memo['E'] -= num[0];
	memo['R'] -= num[0];
	memo['O'] -= num[0];
	num[2] = memo['W'];
	memo['T'] -= num[2];
	memo['W'] -= num[2];
	memo['O'] -= num[2];
	num[8] = memo['G'];
	memo['E'] -= num[8];
	memo['I'] -= num[8];
	memo['G'] -= num[8];
	memo['H'] -= num[8];
	memo['T'] -= num[8];	
	num[3] = memo['T'];
	memo['T'] -= num[3];
	memo['H'] -= num[3];
	memo['R'] -= num[3];
	memo['E'] -= num[3];
	memo['E'] -= num[3];
	num[4] = memo['U'];
	memo['F'] -= num[4];
	memo['O'] -= num[4];
	memo['U'] -= num[4];
	memo['R'] -= num[4];
	num[5] = memo['F'];
	memo['F'] -= num[5];
	memo['I'] -= num[5];
	memo['V'] -= num[5];
	memo['E'] -= num[5];
	num[1] = memo['O'];
	memo['O'] -= num[1];
	memo['N'] -= num[1];
	memo['E'] -= num[1];
	num[7] = memo['V'];
	memo['S'] -= num[7];
	memo['E'] -= num[7];
	memo['V'] -= num[7];
	memo['E'] -= num[7];
	memo['N'] -= num[7];
	num[9] = memo['I'];
	memo['N'] -= num[9];
	memo['I'] -= num[9];
	memo['N'] -= num[9];
	memo['E'] -= num[9];
	string res;
	for( auto m : memo )
		assert( m.second == 0 );
	for(int i = 0 ; i < 10 ; i++){
		res += string(num[i],'0'+i);
	}
	return res;
	
	
	
	
	
	
	
	
	
	
}
int main(){
	int T;
	cin >> T;
	int t = 1;
	while(T--){
		string s;
		cin >> s;
		printf("Case #%d: ",t++);
		cout << solve(s) << endl;
	}
}