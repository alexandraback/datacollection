#include <fstream>
#include <string>
using namespace std;

char * translation = "yhesocvxduiglbkrztnwjpfmaq";
string text;

string FILENAME = "A-small-attempt0";

int main()
{
	ifstream in;
	ofstream out;

	int lines;
	string line;

	in.open(FILENAME + ".in");
	out.open(FILENAME + ".out");

	in >> lines;

	for (int i = 0; i < lines; i++)
	{
		do
		{
			getline(in, line);
		} while (line == "");

		out << "Case #" << i + 1 << ": ";

		for (int j = 0; j < line.length(); j++)
		{
			if (line[j] == ' ')
				out << ' ';
			else
				out << translation[line[j] - 'a'];
		}

		out << endl;
	}

	in.close();
	out.close();

	return 0;
}