#include <fstream>
using namespace std;

#include "Cookies.cpp"

int main() {
	ifstream infile("B-large.in");
	ofstream outfile("results.out");
	Cookies c;
	c.go(infile, outfile);
}