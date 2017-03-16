#include<bits/stdc++.h>
using namespace std;

string digit[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		string s; cin>>s;
		string ret;
		int n=s.size();
		map<char,int> mp;

		vector<int> x(10,0);

		for (int i=0; i<n; i++) mp[s[i]]++;
		x[0]=mp['Z'];
		x[6]=mp['X'];
		x[2]=mp['W'];
		x[4]=mp['U'];
		x[3]=mp['R']-x[0]-x[4];
		x[8]=mp['H']-x[3];
		x[1]=mp['O']-x[0]-x[2]-x[4];
		x[5]=mp['F']-x[4];
		x[7]=mp['S']-x[6];
		x[9]=mp['I']-x[5]-x[6]-x[8];

		for (int i=0; i<10; i++) {
			char ch='0'+i;
			for (int j=0; j<x[i]; j++)
				ret+=ch;
		}
		cout << "Case #" << c << ": " << ret << endl;
	}
	return 0;
}
