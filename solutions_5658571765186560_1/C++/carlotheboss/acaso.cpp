#include <bits/stdc++.h>
using namespace std;

int T, R, C, X;

int main() {
	ios::sync_with_stdio(false);
	ifstream in("input.txt");
	ofstream out("output2.txt");
	in >> T;
	for(int i=1;i<=T;i++) {
	   in >> X >> R >> C;
	   if(R>C) swap(R,C);
	   out<<"Case #"<<i<<": ";
	   if((R*C) % X == 0 && R>= X-1 && C>=X) out<<"GABRIEL\n";
	   else out<<"RICHARD\n";
    }
	return 0;
}
