#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
	ifstream in("input");
	ofstream out("A.out");
	int T;
	in >> T;
	for (int z = 1 ; z <= T ; z++)
	{
		int R, C, W;
		in >> R >> C >> W;
		int score = 0;
		int t = (C+W-1)/W;
		score += R * t;
		int k = min(W,C-W*t);
		int i = 1;
		while (i < k){
			i = (W + i)/2 + 1;
			score++;
		}
		score += W - 1;
		out << "Case #" << z <<": "<<score <<endl;
	}
	in.close();
	out.close();
	return 0;
}
