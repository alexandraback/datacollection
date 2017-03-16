#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int main()
{
    ifstream input;		
	input.open("C:\\codejam\\probA\\input.txt", ifstream::in);
	ofstream output;
	output.open("C:\\codejam\\probA\\output.txt");
	string currentLine;
	string translation;
	map<char, char> translator;
	translator[' '] = ' ';
	translator['y'] = 'a';
	translator['n'] = 'b';
	translator['f'] = 'c';
	translator['i'] = 'd';
	translator['c'] = 'e';
	translator['w'] = 'f';
	translator['l'] = 'g';
	translator['b'] = 'h';
	translator['k'] = 'i';
	translator['u'] = 'j';
	translator['o'] = 'k';
	translator['m'] = 'l';
	translator['x'] = 'm';
	translator['s'] = 'n';
	translator['e'] = 'o';
	translator['v'] = 'p';
	translator['z'] = 'q';
	translator['p'] = 'r';
	translator['d'] = 's';
	translator['r'] = 't';
	translator['j'] = 'u';
	translator['g'] = 'v';
	translator['t'] = 'w';
	translator['h'] = 'x';
	translator['a'] = 'y';
	translator['q'] = 'z';
	int lineNumber = 0;
	string numb;
	getline(input, numb);
	lineNumber = atoi(numb.c_str());
	for(int i = 1; i < lineNumber+1; ++i)
	{
		getline(input, currentLine);
		ostringstream oss;
		oss << i;
		string result = oss.str();
		translation = "Case #" + result + ": ";
		for(int j = 0; j != currentLine.size(); ++j)
		{
			translation += translator[currentLine[j]];
		}
		output<<translation<<endl;
	}
	input.close();
	output.close();
    return 0;
}
