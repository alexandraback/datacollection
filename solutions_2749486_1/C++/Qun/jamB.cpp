#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

typedef long long int int64;


inline bool is_boin(char c)
{
	return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}

inline bool is_siin(char c){
	return !is_boin(c);
}

//jamB
int main(void)
{
	int nTestCase, repeat;
	int X, Y;
	int x, y;
	string s;
	int step;

	cin >> nTestCase;
	for(repeat = 1; repeat <= nTestCase; repeat++){
		cin >> X >> Y;

		cerr << "GOAL: (" << X << "," << Y << ")" << endl;

		x = 0;
		y = 0;
		s = "";
		step = 0;

		while(step <= 500){
			step++;
			if(abs(x - X) == 0 && abs(y - Y) == 0){ // “ž’…
				break;
			}else if(abs(x - X) > abs(y - Y)){ // X•ûŒü‚ÉˆÚ“®
				if(x < X){
					if(x + step <= X){
						s += 'E';
						x += step;
					}else{
						s += 'W';
						x -= step;
					}
				}else{
					if(x - step >= X){
						s += 'W';
						x -= step;
					}else{
						s += 'E';
						x += step;
					}
				}
			}else{ // Y•ûŒü‚ÉˆÚ“®
				if(y < Y){
					if(y + step <= Y){
						s += 'N';
						y += step;
					}else{
						s += 'S';
						y -= step;
					}
				}else{
					if(y - step >= Y){
						s += 'S';
						y -= step;
					}else{
						s += 'N';
						y += step;
					}
				}
			}
//			cerr << "  " << s[s.length() - 1] << ": " << step << " (" << x << ", " << y << ")" << endl;
		}

//		if(step > 500){
//			cerr << "ERROR! MORE THAN 500 STEP!" << endl;
//		}

		// Œ‹‰Êo—Í
		cout << "Case #" << repeat << ": " << s << endl;
		cerr << "Case #" << repeat << ": " << s << endl;
	}

	return 0;
}

int main2(void)
{
	int nTestCase, repeat;
	int X, Y;
	int x, y;
	string s;
	int step;

	cin >> nTestCase;
	for(repeat = 1; repeat <= nTestCase; repeat++){
		cin >> X >> Y;

		cerr << "GOAL: (" << X << "," << Y << ")" << endl;

		x = 0;
		y = 0;
		s = "";
		step = 0;

		while(step <= 500){
			step++;
			if(abs(x - X) == 0 && abs(y - Y) == 0){ // “ž’…
				break;
			}else if(abs(x - X) > abs(y - Y)){ // X•ûŒü‚ÉˆÚ“®
				if(x < X){
					if(x + step <= X){
						s += 'E';
						x += step;
					}else{
						s += 'W';
						x -= step;
					}
				}else{
					if(x - step >= X){
						s += 'W';
						x -= step;
					}else{
						s += 'E';
						x += step;
					}
				}
			}else{ // Y•ûŒü‚ÉˆÚ“®
				if(y < Y){
					if(y + step <= Y){
						s += 'N';
						y += step;
					}else{
						s += 'S';
						y -= step;
					}
				}else{
					if(y - step >= Y){
						s += 'S';
						y -= step;
					}else{
						s += 'N';
						y += step;
					}
				}
			}
			cerr << "  " << s[s.length() - 1] << ": " << step << " (" << x << ", " << y << ")" << endl;
		}

		if(step > 500){
			cerr << "ERROR! MORE THAN 500 STEP!" << endl;
		}

		// Œ‹‰Êo—Í
		cout << "Case #" << repeat << ": " << s << endl;
		cerr << "Case #" << repeat << ": " << s << endl;
	}

	return 0;
}
