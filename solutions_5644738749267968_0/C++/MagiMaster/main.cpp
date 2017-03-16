#include <fstream>
using namespace std;

#include "War.cpp"

int main() {
	ifstream infile("D-small-attempt1.in");
	ofstream outfile("results.out");
	War w;
	w.go(infile, outfile);
}