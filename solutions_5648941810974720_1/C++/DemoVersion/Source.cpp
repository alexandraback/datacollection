#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
#include<fstream>

#define Author "DemoVersion"
#define DBG(x) cout<<#x<<" = "<<x<<";\n"


using namespace std;
int dx[] = { 0,0,-1,1,1,-1,1,-1 };
int dy[] = { 1,-1,0,0,1,1,-1,-1 };
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

string num_strings[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int get_cnt(int num, int chid) {
	int k,cnt=0;
	for (k = 0;k < num_strings[num].size();k++) {
		if (num_strings[num][k] == chid)cnt++;
	}
	return cnt;
}
string solve(string inpt) {
	int mp[255] = { 0 };
	int i,k;
	for (i = 0;i < inpt.length();i++) {
		mp[inpt[i]]++;
	}
	string ret = "";
	string mosh = "ZXGHTSUFIO";
	int bta[] = { 0,6,8,3,2,7,4,5,9,1 };
	int cntof[10] = { 0 };
	for (k = 0;k < 10;k++) {
		cntof[bta[k]] = mp[mosh[k]];
		for (i = 'A';i <= 'Z';i++) {
			mp[i] -= cntof[bta[k]]*get_cnt(bta[k], i);
		}
	}
	for (k = 0;k < 10;k++) {
		for (i = 0;i < cntof[k];i++) {
			ret += k + '0';
		}
	}
	return ret;
}
int main() {
	int T,test;
	
	string S;
	cin >> T;
	for (test = 1;test <= T;test++) {
		cin >> S;
		cout << "Case #" << test << ": " << solve(S) << endl;
	}
	return 0;
}
