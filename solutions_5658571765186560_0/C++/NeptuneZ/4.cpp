#include<iostream>
#define min(a, b) ((a < b)? a: b)
#define max(a, b) ((a > b)? a: b)
using namespace std;

int runtime, x, r, c;

bool check(int x, int r, int c){
	if (r * c % x != 0) return false;
	if ((x + 1) / 2 > min(r, c)) return false;
	if (x > max(r, c)) return false;
	return true;	
}

int main(){
//	freopen("4.in", "r", stdin);
//	freopen("4.out", "w", stdout);
	cin >> runtime;
	for (int run = 1; run <= runtime; run++){
		cin >> x >> r >> c;
		if (check(x, r, c)) cout << "Case #" << run << ": " << "GABRIEL" << endl;
		else cout << "Case #" << run << ": " << "RICHARD" << endl;
	}
}
