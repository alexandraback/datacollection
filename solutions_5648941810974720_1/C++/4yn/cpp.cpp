#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> pi;

int tc;
int countchar[26];
vi digits;

void solve(char c,string del,int val){
	while(countchar[c-'A']){
		for(auto i:del){
			countchar[i-'A']--;
		}
		digits.push_back(val);
	}
}

int main(){
	cin >> tc;
	for(int t=1;t<=tc;t++){
		cout << "Case #" << t << ": ";
		string s; cin >> s;
		memset(countchar,0,sizeof(countchar));
		for(auto i:s){
			countchar[i-'A']++;
		}

		digits.clear();

		solve('G',"EIGHT",8);
		solve('H',"THREE",3);
		solve('T',"TWO",2);
		solve('U',"FOUR",4);
		solve('X',"SIX",6);
		solve('Z',"ZERO",0);
		solve('F',"FIVE",5);
		solve('S',"SEVEN",7);
		solve('O',"ONE",1);
		solve('N',"NINE",9);

		sort(digits.begin(),digits.end());
		for(int i=0;i<digits.size();i++){
			cout << digits[i];
		}

		cout << endl;
	}
}