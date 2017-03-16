#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

char mapping(char c);
string mapping(string s);
int main()
{
	std::ifstream f("A-small-attempt0.in");
	std::ofstream o("result1-1.txt");

	int size;
	f >> size;
	char str[255];
	f.getline(str,255);
	for(int i = 0; i < size; i++)
	{
		char str[255];
		f.getline(str,255);
		string result(str);
		result = mapping(result);
		std::cout << "Case #" << i+1 << ": " << result << std::endl;
		o << "Case #" << i+1 << ": " << result << std::endl;
	}
	return 0;
}


string mapping(string s)
{
	string r(s);
	for(int i = 0; i < (int)s.size(); i++)
	{
		r[i] = mapping(s[i]);
	}
	return r;
}

char mapping(char c)
{
	switch(c)
	{
		case 'a' : 
			return 'y'; break;
		case 'b' :
			return 'h'; break;
		case 'c' : 
			return 'e'; break;
		case 'd' : 
			return 's'; break;
		case 'e' : 
			return 'o'; break;
		case 'f' : 
			return 'c'; break;		
		case 'i' : 
			return 'd'; break;
		case 'j' : 
			return 'u'; break;
		case 'k' : 
			return 'i'; break;
		case 'l' : 
			return 'g'; break;
		case 'm' : 
			return 'l'; break;
		case 'n' : 
			return 'b'; break;
		case 'o' : 
			return 'k'; break;
		case 'p' : 
			return 'r'; break;		
		case 'r' : 
			return 't'; break;
		case 's' : 
			return 'n'; break;
		case 't' : 
			return 'w'; break;
		case 'u' : 
			return 'j'; break;
		case 'v' : 
			return 'p'; break;
		case 'w' : 
			return 'f'; break;
		case 'x' : 
			return 'm'; break;
		case 'y' : 
			return 'a'; break;
		case 'z' : 
			return 'q'; break;


		case 'g' : 
			return 'v'; break;
		case 'h' : 
			return 'x'; break;
		case 'q' : 
			return 'z'; break;
		case ' ' :
			return ' '; break;
	}
}