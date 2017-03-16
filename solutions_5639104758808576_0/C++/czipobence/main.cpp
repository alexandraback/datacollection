#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	int n;
	std::ifstream myfile;
	std::ofstream output;
	myfile.open("A-small-attempt0.in");
	output.open("out.txt");

	myfile >> n;
	for (int i = 1;i<=n;i++) {
		int m;
		myfile >> m;
		char c;
		int st = 0;
		int plus = 0;
		for (int j=0;j<=m;j++) {
			if (j > st) {plus++;st++;};
			myfile >> c;
			st += c - '0';
		}
		output << "Case #" << i << ": " << plus << std::endl;
	}
    myfile.close();
	
	return 0;
}
