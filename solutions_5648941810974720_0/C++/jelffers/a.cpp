#include<bits/stdc++.h>
using namespace std;
int freq[256];
string numbers[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int>result;
void read(int digit){
	for(char c:numbers[digit])freq[c]--;
	result.push_back(digit);
}
int main(){
	int T; cin >> T;
	for (int tc=1;tc<=T;tc++){
		string s; cin >> s;
		memset(freq,0,sizeof freq);
		result.clear();
		for(char c:s)freq[c]++;
		while(freq['Z'] > 0) read(0);
		while(freq['W'] > 0) read(2);
		while(freq['G'] > 0) read(8);
		while(freq['H'] > 0) read(3);
		while(freq['U'] > 0) read(4);
		while(freq['X'] > 0) read(6);
		while(freq['F'] > 0) read(5);
		while(freq['O'] > 0) read(1);
		while(freq['S'] > 0) read(7);
		while(freq['N'] > 0) read(9);
		sort(result.begin(),result.end());
		cout<<"Case #"<<tc<<": ";for(int digit:result)cout<<digit;cout<<endl;
	}
}
