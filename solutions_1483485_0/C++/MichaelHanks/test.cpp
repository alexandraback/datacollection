#include <stdio.h> 

#include <iostream> 

#include <stdio.h> 

#include <string> 

#include <fstream> 

using namespace std; 

int main() 
{
	char tranChar[27] = {'y','n','f','i','c','w','l',
							'b','k','u','o','m','x','s',
							'e','v','z','p','d','r',
							'j','g','t','h','a','q'};

	char orignalChar[27] = {'a','b','c','d','e','f','g',
							'h','i','j','k','l','m','n',
							'o','p','q','r','s','t',
							'u','v','w','x','y','z'};
	char mapping[200];

	for ( int i = 0 ; i < 27 ; i++)
	{
		mapping[tranChar[i]] = orignalChar[i];
	}
/*	for ( int i = 'a'; i <= 'z' ; i++)
		fout << (char)i << " " <<mapping[i]<<endl;
*/
	ifstream fin ("C:/Code/A-small-attempt0.in",ios::in);
	ofstream fout("C:/Code/test.txt"); 
	string line;
	int N;
	fin >> N;
	getline(fin,line);
	for (int i = 1 ; i <= N;i++)
	{
		
		getline(fin,line);
		fout <<"Case #"<<i<<": ";
		for ( int j = 0 ; j < line.size(); j++)
		{
			char ch = line[j];
			if ( ch == ' ')
				fout << ch;
			else
				fout << mapping[ch];
		}
		fout << endl;
    } 

	return 0;
}