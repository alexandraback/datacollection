#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int t;
	in >> t;
	for (int c=1; c<=t; c++) {
		out << "Case #" << c << ": ";
		int x, y;
		int curr_jump = 1;
		int curr_pos = 0;
		in >> x >> y;
		while (curr_pos + curr_jump <= abs(x)) {
			curr_pos += curr_jump;
			curr_jump++;
			out << ((x > 0) ? 'E' : 'W');
		}
		for (int i(0); i < abs(x)-curr_pos; i++) {
			out << ((x > 0) ? "WE" : "EW");
			curr_jump+=2;
		}
		curr_pos = 0;
		while (curr_pos + curr_jump <= abs(y)) {
			curr_pos += curr_jump;
			curr_jump++;
			out << ((y > 0) ? 'N' : 'S');
		}
		for (int i(0); i < abs(y)-curr_pos; i++) {
			out << ((y > 0) ? "SN" : "NS");
			curr_jump+=2;
		}
		out << endl;
		

	}

}//main