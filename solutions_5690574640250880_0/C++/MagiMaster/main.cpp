#include <fstream>
using namespace std;

#include "Mines.cpp"

int main() {
	ifstream infile("C-small-attempt0.in");
	ofstream outfile("results.out");
	Mines m;
	m.go(infile, outfile);
}