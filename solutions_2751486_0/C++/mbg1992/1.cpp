#include <fstream>
#include <string>
using namespace std;

void Replace (string & word, int & length)
{
	for (int i = 0; i < length; i++)
	{
		char ch = word.at(i);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			word[i] = 'W';
		else
			word[i] = 'C';
	}
}

int main()
{
	ifstream input("f.txt");
	ofstream output("out.txt");
	int total_case;
	input >> total_case;
	for (int test = 1; test <= total_case; test++)
	{
		string word;
		int n, length;
		input >> word >> n;
		length = word.length();
		Replace(word,length);
		unsigned long long point = 0;
		unsigned long long cursor = 0;
		string word_to_find = "";
		for (int a = 1; a <= n; a++)
			word_to_find += "C";
		
			bool founded = false;
			bas:
			unsigned long long pointer = word.find(word_to_find,cursor);
			if (pointer != string::npos)
			{
				point += (pointer + 1 - (int)founded) * ((length + 1) - (pointer + n));
				cursor = pointer + 1;
				founded = true;
				goto bas;
			}
			output << "Case #" << test << ": " << point << endl; 
	}
	output.close();
	system("PAUSE");
	return 0;
}