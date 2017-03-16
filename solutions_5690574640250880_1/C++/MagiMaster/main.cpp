#include <fstream>
using namespace std;

#include "Mines.cpp"

int main() {
	ifstream infile("C-large.in");
	ofstream outfile("results.out");
	Mines m;
	m.go(infile, outfile);
}