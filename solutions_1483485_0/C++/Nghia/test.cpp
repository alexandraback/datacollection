#include "stdio.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
char mapping[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main()
{
 	ifstream file1("a.txt");
	ofstream file2("a.res");
	int T;
	file1 >> T;	
	string line;
	getline(file1, line);
	for(int i=0; i < T; ++i)
	{
		file2 << "Case #" << i + 1 << ": ";

		getline(file1,line);
		for(int j = 0; j < line.length(); ++j) {
                   if ('a' <= line[j] && line[j] <='z')
    		      file2 << mapping[ line[j] - 'a' ];
                   else file2 << line[j];
		}					
		file2 << endl;
	}	
	return 0;
}

