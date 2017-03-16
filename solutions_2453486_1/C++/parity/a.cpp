#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int T;

char b[4][4];

string ans[4] = {"X won", "O won", "Draw", "Game has not completed"};

string line;

map<char, int> hist;

int get_ans(){

	if(hist['.'])	return 2;

	if(hist['X'] >= 3 && hist['T'] <= 1 && hist['O'] == 0)
		return 0;
	if(hist['O'] >= 3 && hist['T'] <= 1 && hist['X'] == 0)
		return 1;

	return 2;

}

void init(){
	hist.clear();
	hist['.'] = 0;
	hist['X'] = 0;
	hist['T'] = 0;
	hist['O'] = 0;
}
bool notdone;
int main()
{

	getline(cin, line);
	T = atoi(line.c_str());

	for(int caseidx = 1; caseidx <= T; caseidx++){

		int state;

		notdone = false;

		for(int i = 0; i < 4; i++){
			getline(cin, line);
			for(int j = 0; j < 4; j++){
				b[i][j] = line[j];

				if(b[i][j] == '.')
					notdone = true;
			}
		}
		getline(cin, line);

		/*
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				printf("%c", b[i][j]);
			}
			printf("\n");
		}
		goto done;
		*/

		int r, c;
		for(r = 0; r < 4; r++){
			init();
			for(c = 0; c < 4; c++){
				hist[b[r][c]]++;
			}

			if((state = get_ans()) != 2)
				goto done;
		}

		for(c = 0; c < 4; c++){
			init();
			for(r = 0; r < 4; r++){
				hist[b[r][c]]++;
			}

			if((state = get_ans()) != 2)
				goto done;
	
		}

		init();
		for(c = 0; c < 4; c++){
			hist[b[c][c]]++;

			if((state = get_ans()) != 2)
				goto done;
		}

		init();
		for(c = 0; c < 4; c++){
			hist[b[c][3 - c]]++;

			if((state = get_ans()) != 2)
				goto done;
		}

		state = notdone ? 3: 2;

done:

		printf("Case #%d: %s\n", caseidx, ans[state].c_str());
	}

	return 0;
}

// vi: ts=2 sw=2
