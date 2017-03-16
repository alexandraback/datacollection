#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iterator>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MM(a,x) memset(a, x, sizeof(a))
#define P(x) cout<<#x<<" = "<<x<<endl;
#define P2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define PV(a,n) for(int i=0;i<n;i++) cout<<#a<<"[" << i <<"] = "<<a[i]<<endl;
#define TM(a,b) cout<<#a<<"->"<<#b<<": "<<1.*(b-a)/CLOCKS_PER_SEC<<"s\n";

string s[4];
int T;

int f() {
	vector<string> vs;
	string s1, s2;
	s1 = s1 + s[0][0] + s[1][1] + s[2][2] + s[3][3];
	s2 = s2 + s[0][3] + s[1][2] + s[2][1] + s[3][0];
	vs.push_back(s1), vs.push_back(s2);
	for(int i = 0; i < 4; i++) {
		vs.push_back(s[i]);
		s1.clear();
		for(int j = 0; j < 4; j++) {
			s1 = s1 + s[j][i];
		}
		vs.push_back(s1);
	}
	for(int i = 0; i < vs.size(); i++) {
		int A = 0, B = 0, T = 0;
		for(int j = 0; j < 4; j++) {
			if(vs[i][j] == 'X') A++;
			else if(vs[i][j] == 'O') B++;
			else if(vs[i][j] == 'T') T++;
		}
		if(A + T == 4) return 0;
		if(B + T == 4) return 1;
	}
	int over = 1;
	for(int i = 0; i < 4; i++)for(int j = 0; j < 4; j++) if(s[i][j] == '.') over = 0;
	if(over) return 2;
	
	return 3;
}

int main() {
	cin >> T;
	for(int k = 1; k <= T; k++) {
		for(int i = 0; i < 4; i++) cin >> s[i];
		int t = f();
		cout << "Case #" << k << ": ";
		if(t == 0) cout << "X won";
		if(t == 1) cout << "O won";
		if(t == 2) cout << "Draw";
		if(t == 3) cout << "Game has not completed";
		cout << endl;
	}
	return 0;
}
