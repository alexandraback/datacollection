#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
void Test(int);
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T; cin >> T;
	for(int i=1; i<=T; i++) Test(i);
	return 0;
}

string niz;

void idi(int tx, int ty, int x, int y, int num=1) {
	if(num>500) {
		cout << "-" << endl;
		return;
	} 
	
	if(tx<x) {
		if(tx+num<=x) {
			//cout << 'E';
			niz += 'E';
			idi(tx+num, ty, x, y, num+1);
		} else {
			//cout << 'W';
			niz += 'W';
			idi(tx-num, ty, x, y, num+1);
		}
		return;
	}
	
	if(tx>x) {
		if(tx-num>=x) {
			//cout << 'W';
			niz += 'W';
			idi(tx-num, ty, x, y, num+1);
		} else {
			//cout << 'E';
			niz += 'E';
			idi(tx+num, ty, x, y, num+1);
		}
		return;
	}
	
	if(ty<y) {
		if(ty+num<=y) {
			//cout << 'N';
			niz += 'N';
			idi(tx, ty+num, x, y, num+1);
		} else {
			//cout << 'S';
			niz += 'S';
			idi(tx, ty-num, x, y, num+1);
		}
		return;
	}
	
	if(ty>y) {
		if(ty-num>=y) {
			//cout << 'S';
			niz += 'S';
			idi(tx, ty-num, x, y, num+1);
		} else {
			//cout << 'N';
			niz += 'N';
			idi(tx, ty+num, x, y, num+1);
		}
		return;
	}
}

void Test(int T) {
	int x, y, tx=0, ty=0;
	
	cin >> x >> y;
	
	niz = "";
	cout << "Case #" << T << ": ";
	idi(tx, ty, x, y);
	cout << niz << endl;
}

