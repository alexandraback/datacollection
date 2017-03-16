#include<bits/stdc++.h>

using namespace std;


typedef long long int ll;
typedef ll state_t;

int N;

void solve(){
	string s;
	cin >> s;
	N = s.size();

	vector<bool> pattern;
	for(int i=0;i<s.size();i++){
		if(i>0){
			if(s[i] == s[i-1]){
			}else{
				pattern.push_back(s[i] == '+');
			}
		}else{
			pattern.push_back(s[i] == '+');
		}
	}

	int answer = 0;

	//cerr << "ps " << pattern.size() << endl;

	if(pattern.size() % 2){
		if(pattern[0] == true){
			answer = pattern.size()-1;
		}else{
			answer = pattern.size();
		}
	}else{
		if(pattern[0] == true){
			answer = pattern.size();
		}else{
			answer = pattern.size()-1;
		}
	}
	
	cout << answer << endl;
}

int main(){
	int T;
	cin >> T;

	for(int i=1;i<=T;i++){
		printf("Case #%d: ", i);
		solve();
	}

	/*
	string s;
	cin >> s;
	N = s.size();

	state_t start = 0;
	for(int i=0;i<N;i++){
		start |= ((s[i] == '+') << i);
	}

	cerr << "N " << N;
	cerr << "s is " << s << endl;
	dbgState(start);
	cerr << "=====" << endl;
	for(state_t ns:next_states(start)){
	}
	*/
}
