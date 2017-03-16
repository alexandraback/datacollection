#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{	
	char key[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u',
		'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w',
		'j', 'p', 'f', 'm', 'a', 'q'};

	char ch;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int i, j, k;//ÓÃÓÚµü´ú
	int count = 1;
	int N;
	string str;

	fin >> N;
	getline(fin,str);
	for(i = 1; i <= N; ++i)
	{
		fout << "Case #" << i << ": ";
		getline(fin,str);  
		for(k = 0; k != str.size(); ++k)
		{
			for(j = 0; j != 26; ++j)
			{
				if(str[k] == char(j+97))
				{
					fout << key[j];
					break;
				}
				if(str[k] == ' ')
				{
					fout << ' ';
					break;
				}
			}
		}
		fout << endl;   
	}

	return 0;
}

