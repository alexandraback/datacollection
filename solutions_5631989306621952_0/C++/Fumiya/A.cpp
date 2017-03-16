#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	int T; cin >> T;
	for(int caseNum=1;caseNum<=T;++caseNum){
		string s; cin >> s;
		string res;
		res += s[0];
		for(int i=1;i<s.size();++i){
			if(res[0] <= s[i]) res = s[i] + res;
			else res = res + s[i];
		}
		printf("Case #%d: %s\n", caseNum, res.c_str());
	}
}
