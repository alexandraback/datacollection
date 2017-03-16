#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define PLL pair<long long, long long>

// i is 2, j is 3, k is 4

static int MUL[4][4] = {	{1, 2, 3, 4}, 
							{2, -1, 4, -3},
							{3, -4, -1, 2},
							{4, 3, -2, -1} };
int main() {
	ifstream in("C-small-attempt2.in");
	ofstream out; 
	out.open("c.output");
	int t;
	in >> t;
	for(int z = 0; z < t; z++) {
		long long l, x;
		string s;
		in >> l >> x;
		in >> s;
		int cur;
		if(x >= 16)
			x = x % 4 + 12;
		cout << "x=" << x << endl;
		if(x % 4 == 0) {
			out << "Case #" << z+1 << ": NO" << endl;
			continue;
		}
		string temp = "";
		for(int i = 0; i < x; i++) {
			temp += s;
		}
		s = temp;
		l *= x;
		int L = 1;
		int LisPos =1;
		cout << s << endl;
		for(long long i = 0; i < l; i++) {
			if(s[i] == 'i') cur = 2;
			else if (s[i] == 'j') cur = 3;
			else cur = 4;
			L = MUL[L-1][cur-1]; 
			if(L < 0){
				L = (-1)*L;
				LisPos ^= 1;
			}
		}
		if(L!= 1 || LisPos == 1) {
			out << "Case #" << z+1 << ": NO" << endl;
			cout << "sum is not equal to -1" << endl;
			continue;
		}
		bool flag1 = false;
		bool flag2 = false;
		int num = 1;
		int isPos = 1;
		int itr = 0;
		while (itr < l) {
			if(s[itr] == 'i') cur = 2;
			else if (s[itr] == 'j') cur = 3;
			else cur = 4;
			num = MUL[num-1][cur-1];
			if(num < 0){
				num = (-1)*num;
				isPos ^= 1;
			}
			itr++;
			if(num == 2 && isPos) {
				flag1 = true;
				break;
			}
		}
		num = 1;

		while (itr < l) {
			if(s[itr] == 'i') cur = 2;
			else if (s[itr] == 'j') cur = 3;
			else cur = 4;
			num = MUL[num-1][cur-1];
			if(num < 0){
				num = (-1)*num;
				isPos ^= 1;
			}
			itr++;
			if(num == 3 && isPos) {
				flag2 = true;
				break;
			}
		}
		if(flag1 && flag2) {
			out << "Case #" << z+1 << ": YES" << endl;
		}
		else 
			out << "Case #" << z+1 << ": NO" << endl;
	}
	return 0;
}

/**

		for(long long i = 0; i < l; i++) {
			if(s[i] == 'i') cur = 2;
			else if (s[i] == 'j') cur = 3;
			else cur = 4;
			L = MUL[L-1][cur-1]; 
			if(L < 0){
				L = (-1)*L;
				LisPos ^= 1;
			}
		}
		for(long long i = 0; i < l-1; i++) {
			for(long long j = 1; j < ; )
		}
*/

