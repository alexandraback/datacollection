#include <iostream>
#include <fstream>
#include <vector>
#include <map>

void solve(int case_num, std::ifstream& input)
{
	int r, c ;
	int d[100][100];
	int r_max[100];
	int c_max[100];


	std::cout << "Case #" << case_num << ": ";
	input >> r >> c;
	for(int i =0; i < r;++i) {
		r_max[i] =0; 
		for(int j =0; j < c;++j) {
			input  >>d[i][j];
			if(r_max[i] < d[i][j] )
				r_max[i] = d[i][j];
		}
	}
	for(int i =0; i < c;++i)
	{
		c_max[i] =0;
		for(int j =0; j < r;++j) {
			if(c_max[i] < d[j][i]) 
				c_max[i] = d[j][i];
		}
	}

	for(int i =0; i < r;++i)  {
		for(int j =0; j < c;++j) {
			if(d[i][j] != r_max[i] && d[i][j] != c_max[j] )
			{
				std::cout << "NO\n";
				return;
			}
		}
	}
	std::cout << "YES\n";

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
