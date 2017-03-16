#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;



int bomb(int len, int r, int w, int* score) {
	int i, j, k;
	if (len > 2 * w) {
		(*score) ++;
		len -= w;
		bomb(len, r, w, score);
//		cout<<"BOMB: "<<len<<" "<<(*score)<<endl;
	}
	else {
		if (len == w) {
			(*score) += w;
		}
		else {(*score) += w + 1;}
	}


	return *score;
}


int main() {
	int ii, jj, kk;
	int temp1, temp2, temp3;
	int r, c, w, t;
	int rnd, cnt, score;

	cin>> t;
	getchar();
	for (ii = 0; ii < t; ii++) {
		cin>> r>> c>> w;
		getchar();
		score = (r - 1) * (c / w);
		bomb(c, c, w, &score);
		cout<<"Case #" <<ii + 1 <<": "<<score<<endl;


	}

	return 0;
}


