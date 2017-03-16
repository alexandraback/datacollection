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
int can_be(int val, string mask) {

	if (mask.length() == 1 && val > 9)return 0;
	if (mask.length() == 2 && val > 99)return 0;

	string A = string(mask.size(),'0');
	int Z=A.length()-1;
	while (Z >= 0 && val > 0) {
		A[Z] = '0' + val % 10;
		val /= 10;
		Z--;
	}
	int i;

	for (i = 0;i < mask.length();i++) {
		if (mask[i] == '?' || mask[i] == A[i]) {

		}
		else {
			return 0;
		}
	}
	return 1;
}
string tomys(int val, string mask) {
	string A = string(mask.size(), '0');
	int Z = A.length() - 1;
	while (Z >= 0 && val > 0) {
		A[Z] = '0' + val % 10;
		val /= 10;
		Z--;
	}
	return A;
}
string solve(string S1,string S2) {
	int i,j;
	int c1[1001] = {0};
	int c2[1001] = {0};
	for (i = 0;i < 1000;i++) {
		c1[i] = can_be(i, S1);
	}
	for (i = 0;i < 1000;i++) {
		c2[i] = can_be(i, S2);
	}
	int minds = 1 << 28,mini,minj;
	for (i = 0;i < 1000;i++) {
		if (!c1[i])continue;
		for (j = 0;j < 1000;j++) {
			if (!c2[j])continue;
			if (abs(i - j) < minds) {
				minds = abs(i - j);
				mini = i;
				minj = j;
			}
		}
	}
	return tomys(mini, S1)+string(" ")+tomys(minj, S2);
}
int main() {
	int T,test;
	
	string S1,S2;
	cin >> T;
	for (test = 1;test <= T;test++) {
		cin >> S1>>S2;
		cout << "Case #" << test << ": " << solve(S1,S2) << endl;
	}
	return 0;
}
