#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 1-omino
 *
 * #
 *
 * 2-omino
 *
 * ##
 *
 * 3-omino
 *
 * ### ##
 *     #
 *
 * 4-omino
 *
 * #### ### ### ## ##
 *      #    #  ##  ##
 *
 * 5-omino
 *
 * ##### #### #### ### ### ###
 *       #     #   ##  # #   ##
 *
 * ##  ##  ##   #  ### #
 *  ##  ##  #  ###  #  ###
 *  #    #  ##  #   #   #
 *
 * 6-omino
 *
 *  35 of them...
 *
 */
class matrix {
	public:
		matrix(int r, int c) :
			data(r, vector<int>(c)) {}
		int& operator()(int y, int x, int s) {
			if(s & 0x1) y = r-y-1;
			if(s & 0x2) x = c-x-1;
			if(s & 0x3) swap(y, x);
			return data[y][x];
		}

	private:
		int r;
		int c;
		vector<vector<int>> data;
};

int smallest_biggest_length(int X) {
	switch(X) {
		case 1: return 1;
		case 2: return 1;
		case 3: return 2;
		case 4: return 2;
		case 5: return 3;
		case 6: return 3;
		default: return -1;
	}
}

int biggest_recthull_surface(int X) {
	switch(X) {
		case 1: return 1*1;
		case 2: return 1*2;
		case 3: return 2*2;
		case 4: return 2*3;
		case 5: return 3*3;
		case 6: return 3*4;
		default: return -1;
	}
}

// 1x3 ###
//
// 2x3 ### ##.
// YES ... #..
//
// 3x3 ### ##.
// YES ... #..
//     ... ...
//
// 3x4 ###. ##..
// YES #... #...
//     #... ....

// 1x4 ####
//
// 2x2 ##
// NO  ##
//
// 2x4 #### ##.. ##..
// NO  .... ##.. .##.
//
// 3x4 #### ##.. ##.. ###. ###.
// YES .... ##.. .##. .#.. #...
//     .... .... .... .... ....
//
// 4x4 #### ##.. ##.. ###. ###.
// YES .... ##.. .##. .#.. #...
//     .... .... .... .... ....
//     .... .... .... .... ....

bool solve(int X, int R, int C) {
	if(X >= 7)
		return false;
	if(R < X && C < X)
		return false;
	if(R < smallest_biggest_length(X) || C < smallest_biggest_length(X))
		return false;
	if(R*C < biggest_recthull_surface(X))
		return false;
	if((R*C) % X)
		return false;
	if(X <= 3)
		return true;
	if(X == 4) {
		if(R == 4 and C == 2)
			return false;
		if(R == 2 and C == 4)
			return false;
	}
	if(X >= 5)
		return false;
	return true;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int X, R, C;
		cin >> X >> R >> C;
		if(solve(X, R, C))
			cout << "Case #" << t+1 << ": GABRIEL" << endl;
		else
			cout << "Case #" << t+1 <<": RICHARD" << endl;
	}
	return 0;
}
