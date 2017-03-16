#include <iostream>
#include <string>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int t;
	cin >> t;
	REP(test, t){
		int smax;
		cin >> smax;
		string s;
		cin >> s;
		int ret = 0;
		int cur = 0;
		REP(i, smax+1){
			if(cur < i){
				ret+=i-cur;
				cur = i;
			}
			cur+=s[i]-'0';
		}
		cout << "Case #" << test+1 << ": " << ret << endl;
	}


	return 0;
}
