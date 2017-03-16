								/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

#define cin fin
#define cout fout

string in;
int mp[26] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};

int main(){
	int T, test = 0;
	cin >> T;
	getline(cin, in);
	while(T--){
		getline(cin, in);
		string res = "";
		for(int i = 0; i < in.length(); i++)
			res += (in[i] == ' ' ? ' ' : (char)(mp[in[i] - 'a'] + 'a'));
		cout << "Case #" << ++test << ": " << res << endl;
	}
	return 0;
}