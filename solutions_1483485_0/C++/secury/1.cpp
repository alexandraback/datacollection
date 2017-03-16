#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char translate(char c)
{
	switch (c){
	case 'a': return 'y'; break;
	case 'b': return 'h'; break;
	case 'c': return 'e'; break;
	case 'd': return 's'; break;
	case 'e': return 'o'; break;
	case 'f': return 'c'; break;
	case 'g': return 'v'; break;
	case 'h': return 'x'; break;
	case 'i': return 'd'; break;
	case 'j': return 'u'; break;
	case 'k': return 'i'; break;
	case 'l': return 'g'; break;
	case 'm': return 'l'; break;
	case 'n': return 'b'; break;
	case 'o': return 'k'; break;
	case 'p': return 'r'; break;
	case 'q': return 'z'; break;
	case 'r': return 't'; break;
	case 's': return 'n'; break;
	case 't': return 'w'; break;
	case 'u': return 'j'; break;
	case 'v': return 'p'; break;
	case 'w': return 'f'; break;
	case 'x': return 'm'; break;
	case 'y': return 'a'; break;
	case 'z': return 'q'; break;
	case ' ': return ' '; break;
	}
	return '#';
}

int main(int argc, char *argv[])
{
	if (argc != 2){
		cout << "Error" << endl;
		return 1;
	}
	ifstream fin(argv[1]);
	if (fin.fail()){
		cout << "Error2" << endl;
		return 1;
	}
	int T;
	fin >> T;
	string tmp;
	getline(fin, tmp);
	int i;
	for (i=1;i<=T;i++){
		string sentence;
		getline(fin, sentence);
		
		cout << "Case #" << i << ": ";
		int j;
		for (j=0;j<sentence.length();j++){
			cout << translate(sentence[j]);
		}
		cout << endl;
	}

	return 0;
}