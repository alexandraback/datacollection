#include <iostream>
#include <vector>
#include <map>

using namespace std;

int testcase = 0;

void solve(){
	testcase++;
	string ans = "";
	string s;
	cin>>s;
	int freq[26] = {};
	int freqn[10] = {};
	int len = s.size();
	for(int i = 0; i<len; i++) freq[s[i]-'A']++;
	if(freq['Z'-'A']){
		freqn[0] = freq['Z'-'A'];
		freq['E'-'A'] -= freq['Z'-'A'];
		freq['R'-'A'] -= freq['Z'-'A'];
		freq['O'-'A'] -= freq['Z'-'A'];
		freq['Z'-'A'] -= freq['Z'-'A'];
	}
	if(freq['W'-'A']){
		freqn[2] = freq['W'-'A'];
		freq['T'-'A'] -= freq['W'-'A'];
		freq['O'-'A'] -= freq['W'-'A'];
		freq['W'-'A'] -= freq['W'-'A'];
	}
	if(freq['U'-'A']){
		freqn[4] = freq['U'-'A'];
		freq['F'-'A'] -= freq['U'-'A'];
		freq['R'-'A'] -= freq['U'-'A'];
		freq['O'-'A'] -= freq['U'-'A'];
		freq['U'-'A'] -= freq['U'-'A'];
	}
	if(freq['X'-'A']){
		freqn[6] = freq['X'-'A'];
		freq['S'-'A'] -= freq['X'-'A'];
		freq['I'-'A'] -= freq['X'-'A'];
		freq['X'-'A'] -= freq['X'-'A'];
	}
	if(freq['G'-'A']){
		freqn[8] = freq['G'-'A'];
		freq['E'-'A'] -= freq['G'-'A'];
		freq['I'-'A'] -= freq['G'-'A'];
		freq['H'-'A'] -= freq['G'-'A'];
		freq['T'-'A'] -= freq['G'-'A'];
		freq['G'-'A'] -= freq['G'-'A'];
	}
	if(freq['R'-'A']){
		freqn[3] = freq['R'-'A'];
		freq['T'-'A'] -= freq['R'-'A'];
		freq['H'-'A'] -= freq['R'-'A'];
		freq['E'-'A'] -= freq['R'-'A'];
		freq['E'-'A'] -= freq['R'-'A'];
		freq['R'-'A'] -= freq['R'-'A'];
	}
	if(freq['O'-'A']){
		freqn[1] = freq['O'-'A'];
		freq['N'-'A'] -= freq['O'-'A'];
		freq['E'-'A'] -= freq['O'-'A'];
		freq['O'-'A'] -= freq['O'-'A'];
	}
	if(freq['F'-'A']){
		freqn[5] = freq['F'-'A'];
		freq['I'-'A'] -= freq['F'-'A'];
		freq['V'-'A'] -= freq['F'-'A'];
		freq['E'-'A'] -= freq['F'-'A'];
		freq['F'-'A'] -= freq['F'-'A'];
	}
	if(freq['S'-'A']){
		freqn[7] = freq['S'-'A'];
		freq['E'-'A'] -= freq['S'-'A'];
		freq['V'-'A'] -= freq['S'-'A'];
		freq['E'-'A'] -= freq['S'-'A'];
		freq['N'-'A'] -= freq['S'-'A'];
		freq['S'-'A'] -= freq['S'-'A'];
	}
	if(freq['I'-'A']){
		freqn[9] = freq['I'-'A'];
		freq['N'-'A'] -= freq['I'-'A'];
		freq['N'-'A'] -= freq['I'-'A'];
		freq['E'-'A'] -= freq['I'-'A'];
		freq['I'-'A'] -= freq['I'-'A'];
	}
	for(int i = 0; i<10; i++){
		for(int j = 0; j<freqn[i]; j++)
			ans += '0' + i;
	}
	cout<<"Case #"<<testcase<<": "<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}