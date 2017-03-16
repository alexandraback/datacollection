#include <iostream>
#include <fstream>
#include <vector>
#include <map>

void solve(int case_num, std::ifstream& input)
{
	std::cout << "Case #" << case_num << ": ";
	char buf[10];
	int b[4][4];
	bool completed = true;
	for(int i =0; i < 4;++i) {
		input >> buf;
		for(int j =0; j < 4;++j) {
			switch (buf[j])  {
				case 'X' : b[i][j] = 0x1; break;	
				case 'O' : b[i][j] = 0x2; break;	
				case 'T' : b[i][j] = 0x3; break;	
				default : b[i][j] = 0; completed = false;  break;
			}
		}
	}

	for(int i =0; i < 4;++i) {
		int result = b[i][0] & b[i][1] & b[i][2] & b[i][3];
		if(result >0) {
			std::cout << (result ==0x1 ? "X won\n" : "O won\n");
			return;
		}
	}
	for(int i =0; i < 4;++i) {
		int result = b[0][i] & b[1][i] & b[2][i] & b[3][i];
		if(result >0) {
			std::cout << (result ==0x1 ? "X won\n" : "O won\n");
			return;
		}
	}
	int result = b[0][0] & b[1][1] & b[2][2] & b[3][3];
	if(result >0) {
		std::cout << (result ==0x1 ? "X won\n" : "O won\n");
		return;
	}
	result = b[0][3] & b[1][2] & b[2][1] & b[3][0];
	if(result >0) {
		std::cout << (result ==0x1 ? "X won\n" : "O won\n");
		return;
	}
	if(completed) {
		std::cout << "Draw\n";
	}
	else {
		std::cout << "Game has not completed\n";
	}

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
		solve(i, in);
	}
	return 0;
}
