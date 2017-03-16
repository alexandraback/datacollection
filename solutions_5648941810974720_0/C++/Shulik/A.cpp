#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int _cnt[50];
int nums[11];

int cnt(char x){
	return _cnt[x-'A'];
}

void testcase(int T){
	string s;
	cin >> s;
	//cerr << s << endl;
	REP(i, 50)_cnt[i] = 0;
	REP(i, s.length())_cnt[s[i]-'A']++;
	REP(i, 11)nums[i] = 0;
	nums[0] = cnt('Z');
	nums[2] = cnt('W');
	nums[4] = cnt('U');
	nums[6] = cnt('X');
	nums[8] = cnt('G');
	nums[3] = cnt('H') - nums[8];
	nums[5] = cnt('F') - nums[4];
	nums[7] = cnt('V') - nums[5];
	nums[1] = cnt('O') - nums[0]-nums[2]-nums[4];
	nums[9] = (cnt('N') - nums[1] - nums[7])/2;


	cout << "Case #" << T <<": ";
	REP(i, 11)REP(j, nums[i])cout << i;
	cout << endl;

}

int main(){
	int T;
	cin >> T;
	REP(i, T)testcase(i+1);


	return 0;
}
