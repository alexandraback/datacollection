#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

void GoogleTransate(char * a_line, int a_len)
{
	for (int l_index = 0; l_index < a_len; ++ l_index)
	{
		char & c = a_line[l_index];
		switch (c)
		{
			case 'a': c = 'y'; break;
			case 'b': c = 'h'; break;
			case 'c': c = 'e'; break;
			case 'd': c = 's'; break;
			case 'e': c = 'o'; break;
			case 'f': c = 'c'; break;
			case 'g': c = 'v'; break;
			case 'h': c = 'x'; break;
			case 'i': c = 'd'; break;
			case 'j': c = 'u'; break;
			case 'k': c = 'i'; break;
			case 'l': c = 'g'; break;
			case 'm': c = 'l'; break;
			case 'n': c = 'b'; break;
			case 'o': c = 'k'; break;
			case 'p': c = 'r'; break;
			case 'q': c = 'z'; break;
			case 'r': c = 't'; break;
			case 's': c = 'n'; break;
			case 't': c = 'w'; break;
			case 'u': c = 'j'; break;
			case 'v': c = 'p'; break;
			case 'w': c = 'f'; break;
			case 'x': c = 'm'; break;
			case 'y': c = 'a'; break;
			case 'z': c = 'q'; break;
		}
	}

}

void main()
{
	int l_nCases = 0;
	cin>>l_nCases;
	char l_line[101];
	cin.getline(l_line, 101);

	for (int l_index = 0; l_index < l_nCases; ++l_index)
	{
		::memset(l_line, '\0', 101);
		cin.getline(l_line, 101);
		GoogleTransate(l_line, ::strlen(l_line));
		cout<<"Case #"<<(l_index+1)<<": "<<l_line<<endl;
	}
}