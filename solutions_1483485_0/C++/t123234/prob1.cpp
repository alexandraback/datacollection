#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char table[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main(){
	ifstream infile;
	infile.open("./A-small-attempt1.in.txt");
	ofstream outfile;
	outfile.open("outfile.txt");
	
	int numCase;
	infile >> numCase;
	char line[101];
	infile.getline(line, 101);
	int i, j;
	for (i=0; i<numCase; i++) {
		infile.getline(line, 101);
		j = 0;
		while (line[j]) {
			if (line[j]!=' ') {
				line[j] = table[line[j]-'a'];
			}
			j++;
		}
		outfile <<"Case #"<<(i+1)<<": "<<line<<endl;
	}
	return 0;
}