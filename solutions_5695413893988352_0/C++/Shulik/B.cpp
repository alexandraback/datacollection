#include <bits/stdc++.h>
#include <iomanip>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int pw(int e){
	int ret = 1;
	REP(i, e)ret*=10;
	return ret;
}

bool valid(int a, string s){
	int mn = ((int)s.length()) -1;
	//cerr << mn << " " << a << " " << s << endl;
	for(int i = mn; i >= 0; i--){
		if(s[mn-i] != '?' && ((s[mn-i]-'0') != ((a/pw(i)) % 10)))return false;
	}
	return true;
}

int ab(int x){
	return x > 0 ? x : -x;
}

void testcase(int T){
	string s1, s2;
	cin >> s1 >> s2;
	int bsta = -1;
	int bstb = -1;
	int bstdiff = 99999;
	for(int i = 0; i < pw(s1.size()); i++)
		for(int j = 0; j < pw(s1.size()); j++){
			if(valid(i, s1) && valid(j, s2)){
				if(ab(i-j) < bstdiff || (ab(i-j) == bstdiff && i < bsta) || (ab(i-j) == bstdiff && i == bsta && j < bstb)){
					bstdiff = ab(i-j);
					bsta = i;
					bstb = j;
				}
			}
		}
	cout << "Case #" << T <<": " << setfill('0') << setw(s1.size()) << bsta << " " << setfill('0') << setw(s1.size()) <<  bstb << endl;
}

int main(){
	int T;
	cin >> T;
	REP(i, T)testcase(i+1);


	return 0;
}
