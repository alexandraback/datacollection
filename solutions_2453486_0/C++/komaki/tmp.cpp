#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
//#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second

string XO = "XO";

bool check(char c0, char c1)
{
	if(c0 == 'T') return true;
	if(c0 == c1) return true;
	return false;
}

bool win(vector<string> mp, char c)
{
	rep(row, 4){ li cnt = 0; rep(col, 4)if(check(mp[row][col], c)) cnt++; if(cnt == 4) return true; }
	rep(col, 4){ li cnt = 0; rep(row, 4)if(check(mp[row][col], c)) cnt++; if(cnt == 4) return true; }
	{ li cnt = 0; rep(row, 4)if(check(mp[row][row], c)) cnt++; if(cnt == 4) return true; }
	{ li cnt = 0; rep(row, 4)if(check(mp[row][3 - row], c)) cnt++; if(cnt == 4) return true; }
	return false;
}

int main()
{
	li T;
	cin >> T;
	rep(step, T){
		vector<string> mp(4);
		rep(row, 4) cin >> mp[row];
		cout << "Case #" << step + 1 << ": ";

		li empty_cell_cnt = 0;
		rep(row, 4) empty_cell_cnt += count(all(mp[row]), '.');
		
		if(win(mp, 'X')){
			cout << "X won" << endl;
		}else if(win(mp, 'O')){
			cout << "O won" << endl;
		}else if(empty_cell_cnt == 0){
			cout << "Draw" << endl;
		}else{
			cout << "Game has not completed" << endl;
		}
	}
	
}
