#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		int occ[10] = {0};
		int memo[1000] = {0};
		string str;
		cin >> str;
		for(char x : str)
			memo[x]++;
		//0
		occ[0] = memo['Z'];
		memo['Z'] -= occ[0];
		memo['E'] -= occ[0];
		memo['R'] -= occ[0];
		memo['O'] -= occ[0];
		//2
		occ[2] = memo['W'];
		memo['T'] -= occ[2];
		memo['W'] -= occ[2];
		memo['O'] -= occ[2];
		//8
		occ[8] = memo['G'];
		memo['E'] -= occ[8];
		memo['I'] -= occ[8];
		memo['G'] -= occ[8];
		memo['H'] -= occ[8];
		memo['T'] -= occ[8];
		//3
		occ[3] = memo['H'];
		memo['T'] -= occ[3];
		memo['H'] -= occ[3];
		memo['R'] -= occ[3];
		memo['E'] -= 2*occ[3];
		//4
		occ[4] = memo['R'];
		memo['F'] -= occ[4];
		memo['O'] -= occ[4];
		memo['U'] -= occ[4];
		memo['R'] -= occ[4];
		//5
		occ[5] = memo['F'];
		memo['F'] -= occ[5];
		memo['I'] -= occ[5];
		memo['V'] -= occ[5];
		memo['E'] -= occ[5];
		//6
		occ[6] = memo['X'];
		memo['S'] -= occ[6];
		memo['I'] -= occ[6];
		memo['X'] -= occ[6];
		//7
		occ[7] = memo['S'];
		memo['S'] -= occ[7];
		memo['E'] -= occ[7];
		memo['V'] -= occ[7];
		memo['E'] -= occ[7];
		memo['N'] -= occ[7];
		//1					
		occ[1] = memo['O'];
		memo['O'] -= occ[1];
		memo['N'] -= occ[1];
		memo['E'] -= occ[1];
		//9
		occ[9] = memo['E'];
		memo['N'] -= occ[9];
		memo['I'] -= occ[9];
		memo['N'] -= occ[9];
		memo['E'] -= occ[9];
		string ans = "";
		for(int i = 0 ; i < 10 ; i++)
			for(int j = 0 ; j < occ[i] ; j++)
				ans += (char)(i + '0');
		printf("Case #%d: %s\n",tc,ans.c_str());						
	}
	return 0;
}