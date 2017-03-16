#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <gmpxx.h>
#include <algorithm>
#include <assert.h>


void print_one_only(int r, int c) {
	for(int i =0; i < r;++i) {
		for(int j =0; j < c;++j) {
			if(i ==0 && j==0 ) {
				std::cout << 'c';
			}
			else {
				std::cout << '*';
			}
		}
		std::cout << "\n";
	}
}

void print_1_row(int c, int m, bool transpose)
{
	char buf[50];
	memset(buf, '*', sizeof(buf));
	for(int i =0; i < c-m;++i) {
		buf[i] = '.';
	}
	buf[0] = 'c';
	if(transpose) {
		for(int i = 0; i < c;++i) {
			std::cout << buf[i];
			std::cout << "\n";
		}
	}
	else {
		for(int i = 0; i < c;++i) {
			std::cout << buf[i];
		}
		std::cout << "\n";
	}
	
}

void print_2_row(int c, int x, bool t) {
	char buf[2][50];
	memset(buf, '*', sizeof(buf));
	for(int i =0; i < x;++i) {
		buf[0][i] ='.';
		buf[1][i] ='.';
	}
	buf[0][0]='c';
	if(t) {
		for(int i =0; i < c;++i) {
			std::cout << buf[0][i] << buf[1][i] << "\n";;
		}
	}
	else {
		for(int i =0; i < c;++i) {
			std::cout << buf[0][i];
		}
		std::cout << "\n";
		for(int i =0; i < c;++i) {
			std::cout << buf[1][i];
		}
		std::cout << "\n";
	}
}
void print_even(int r, int c, int m) {
	char buf[50][50];
	memset(buf, '*', sizeof(buf));
	int x = (r * c -m)/2;
	for(int i =0; i < x;++i) {
		buf[0][i] = '.';
		buf[1][i] = '.';
	}
	buf[0][0] = 'c';
	
	for(int i =0; i < r;++i) {
		for(int j =0; j < c;++j) {
			std::cout << buf[i][j];
		}
		std::cout << "\n";
	}
}

void print_odd(int r, int c, int m) {
	char buf[50][50];
	memset(buf, '*', sizeof(buf));
	int x = (r * c -m -3)/2;
	for(int i =0; i < x;++i) {
		buf[0][i] = '.';
		buf[1][i] = '.';
	}
	buf[0][0] = 'c';
	buf[2][0] = buf[2][1]= buf[2][2] = '.';

	for(int i =0; i < r;++i) {
		for(int j =0; j < c;++j) {
			std::cout << buf[i][j];
		}
		std::cout << "\n";
	}
}

void print_2r_2(int r, int c, int m, bool t) {
	char buf[50][50];
	memset(buf, '*', sizeof(buf));
	int x = r * c -m;

	for(int i =0; i < r && x >0; ++i) {
		for(int j =0; j < c && x >0 ;++j) {
			buf[i][j] ='.';
			--x;
		}
	}
	buf[0][0] ='c';

	if(t) {
		for(int i =0; i < c;++i) {
			for(int j =0; j < r;++j) {
				std::cout << buf[j][i];
			}
			std::cout << "\n";
		}
	}
	else {
		for(int i =0; i < r;++i) {
			for(int j =0; j < c;++j) {
				std::cout << buf[i][j];
			}
			std::cout << "\n";
		}
	}
}

void print_2r_1(int r, int c, int m, bool t) {
	char buf[50][50];
	memset(buf, '*', sizeof(buf));
	int x = r * c -m;

	for(int i =0; i < r && x >0; ++i) {
		for(int j =0; j < c && x >0 ;++j) {
			buf[i][j] ='.';
			--x;
		}
	}
	buf[0][0] ='c';
	
	int y = (r * c -m) / c;

	buf[y-1][c-1] = '*';
	buf[y][1] = '.';
	if(t) {
		for(int i =0; i < c;++i) {
			for(int j =0; j < r;++j) {
				std::cout << buf[j][i];
			}
			std::cout << "\n";
		}
	}
	else {
		for(int i =0; i < r;++i) {
			for(int j =0; j < c;++j) {
				std::cout << buf[i][j];
			}
			std::cout << "\n";
		}
	}
}

void solve(std::ifstream& input)
{
	int r, c, m;
	input >> r >> c >> m;
	std::cout << "\n";

	if(m == r* c -1) {
		print_one_only(r, c);
		return;
	}
	
	if(r ==1) {
		print_1_row(c, m, false);
		return;
	}
	if(c ==1) {
		print_1_row(r, m, true);
		return;
	}

	int empty = c* r -m;


	if(r ==2) {
		if(empty >=4 && empty %2 ==0 ) {
			print_2_row(c, empty/2, false);
			return;
		}
		else {
			std::cout << "Impossible\n";
			return;
		}
	}
	if(c==2) {
		if(empty >=4 && empty%2 ==0) {
			print_2_row(r, empty/2, true);
			return;
		}
		else {
			std::cout << "Impossible\n";
			return;
		}
	}
	if(empty >= (2 *r + 2) ) {
		if(empty%r !=1)
			print_2r_2(c, r, m, true);
		else
			print_2r_1(c, r, m, true);
		return;
	}
	
	if(empty >= (2*c +2) ) {
		if(empty %c !=1)
			print_2r_2(r, c, m, false);
		else
			print_2r_1(r, c, m, false);
		return;
	}
	
	if(empty >=4 && empty %2==0) {
		print_even(r, c, m);
		return;
	}

	if(empty >=9 && empty %2==1) {
		print_odd(r, c, m);
		return;
	}

	std::cout << "Impossible\n";
}
int main(int argc, char* argv[]) 
{
	if(argc < 2) {
		std::cerr << "missing input file\n" ;
		return 1;
	}

	std::ifstream in(argv[1]);
	int c ;
	in  >> c;
	for(int i =1; i <=c;++i) {
		printf("Case #%d: ", i);
		solve(in);
	}
	return 0;
}
