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
// YES .... #...
//     .... ....

// Yx2 ..##..
// NO  ...##.
//
// 3x4 #### ##.. ##.. ###. ###.
// YES .... ##.. .##. .#.. #...
//     .... .... .... .... ....
//
// 4x4 #### ##.. ##.. ###. ###.
// YES .... ##.. .##. .#.. #...
//     .... .... .... .... ....
//     .... .... .... .... ....
//
// 5x4 #.... ##334 ##444 ###44 ###12
// YES #.... ##334 1##43 1#443 #1112
//     #.... 12224 11333 11333 ....2
//     #.... 11124 12222 12222 ....2
//
// 6x4 ####.. ##.... ##4433
// YES ...... ##.... 1##443
//     ...... ...... 122253
//     ...... ...... 112555
//
// 6x6 ####.. ##.... ##2222 ###223 ###111
// YES ...... ##.... 1##333 1#2233 #22221
//     ...... ...... 111443 188663 ......
//     ...... ...... 888445 188766 ......
//     ...... ...... 877665 177755 ......
//     ...... ...... 776655 444455 ......
//
// 6 = 3+3
// 7 = 3+4
// 8 = 4+4
// 9 = 6+3
// 10 = 6+4
// 11 = 3+4+4
// 12 = 4+4+4
// 13 = 6+3+4
// 14 = 6+4+4
// 15 = 3+4+4+4
// 16 = 4+4+4+4
// 17 = 6+3+4+4
// 18 = 6+4+4+4
// 19 = 3+4+4+4+4
// 20 = 4+4+4+4+4
//
// YAY! That actually works for any value such that RxC % 4 = 0 and R > 2 and C > 2.

// 3x5 .W...
// NO  .WW..
//     ..WW.
//
// 4x5 WWPPP
// YES PWWPP
//     PPWPP
//     PPPPP
//
// YAY! That actually works for any RxC % 5 = 0 and R > 3 and C > 3

// 4x3 ##..
// NO  .##.
//     ..##
//
// 3xY .#....
// NO  .##...
//     ..###.
//
// YAY! That actually works for any RxC % 6 = 0 and R > 3 and C > 3

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
		if(R == 2 or C == 2)
			return false;
		return true;
	}
	if(X == 5) {
		if(R <= 3 || C <= 3)
			return false;
		return true;
	}
	if(X == 6) {
		if(R <= 3 || C <= 3)
			return false;
		return true;
	}
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
