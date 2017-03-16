#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
                
#define MOD 1000000007

typedef long long Int;
bool middle[32];

string press(string tstr){
	string res;
	for(Int i = 0;i < tstr.size();i++){
		if(res.size() == 0 || res[res.size() - 1] != tstr[i])res += tstr[i];
	}
	return res;
}

Int solve(){
	string tstr;
	int n;
 	cin >> n;
	Int id[26];
	Int in[26], out[26];
	bool used[26], middle[26];
	for(Int i = 0;i < 26;i++){
		middle[i] = false;
		used[i] = false;
		in[i] = out[i] = id[i] = 0;
	}
	for(Int i = 0;i < n;i++){
		cin >> tstr;
		tstr = press(tstr);
		set<char> s;
		for(Int j = 0;j < tstr.size();j++)s.insert(tstr[j]);
		if(s.size() != tstr.size())return 0;
		for(Int j = 1;j < tstr.size() - 1;j++){
			Int c = tstr[j] - 'a';
			if(middle[c])return 0;
			middle[c] = true;
		}
		if(tstr.size() == 1){
			id[tstr[0] - 'a']++;
		}
		else{
			in[tstr[0]-'a']++;
			out[tstr[tstr.size() - 1] - 'a']++;
		}
	}
	Int segment = 0;
	bool seg = false;
	for(Int i = 0;i < 26;i++){
		if(in[i] > 0 || out[i] > 0){
			if(middle[i])return 0;
			seg = true;
		}
		if(in[i] > 1)return 0;
		if(out[i] > 1)return 0;
		if(in[i] > out[i])segment++;
	}
	if(seg && segment == 0)return 0;
  for(int i = 0;i < 26;i++){
		if(in[i] == 0 && out[i] == 0 && id[i])segment++;
	}
	Int res = 1;
	for(Int i = 1;i <= segment;i++){
		res *= i;
		res %= MOD;
	}
	for(Int i = 0;i < 26;i++){
		for(Int j = 1;j <= id[i];j++){
			res *= j;
			res %= MOD;
		}
	}
	return res;
}
int main(){
	Int T;
	cin >> T;
	for(Int i = 1;i <= T;i++){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
