#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<double> vd;
template<class T> void pr(T a, T b) { for(T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

string a[4];

bool is_win(char c){
	for(int i = 0; i < 4; ++i){
		int d = 0;
		for(int j = 0; j < 4; ++j){
			if((a[i][j] != c) && (a[i][j] != 'T')) break;
			d++;
		}
		if(d == 4) return true;
	}
	for(int i = 0; i < 4; ++i){
		int d = 0;
		for(int j = 0; j < 4; ++j){
			if((a[j][i] != c) && (a[j][i] != 'T')) break;
			d++;
		}
		if(d == 4) return true;
	}
	{
		int d = 0;
		for(int i = 0; i < 4; ++i){
			if((a[i][i] != c) && (a[i][i] != 'T')) break;
			d++;
		}
		if(d == 4) return true;
	}
	{
		int d = 0;
		for(int i = 0; i < 4; ++i){
			if((a[i][3-i] != c) && (a[i][3-i] != 'T')) break;
			d++;
		}
		if(d == 4) return true;
	}
	return false;
}

bool is_draw(){
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if(a[i][j] == '.') return false;
		}
	}
	return true;
}

void dupa(){
	for(int i = 0; i < 4; ++i){
		string s;
		cin >> s;
		a[i] = s;
	}
	if(is_win('X')) {
		cout << "X won" << endl;
	}else if(is_win('O')){
		cout << "O won" << endl;
	}else if(is_draw()){
		cout << "Draw" << endl;
	}else {
		cout << "Game has not completed" << endl;
	}
}

int main(){
	int z;
	cin >> z;
	for(int i = 0; i < z; ++i){
		cout << "Case #" << i+1 << ": ";
		dupa();
	}
}
