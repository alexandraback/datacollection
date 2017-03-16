#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>


int main(int argc, char * argv[])
{
	using namespace std;

	if (argc < 2)
	{
		cerr << "Usage: " << argv[0] << " inputFile\n";
		exit(EXIT_FAILURE);
	}

	ifstream infile;
	infile.open(argv[1]);
	if (!infile.is_open())
	{
		cerr << "Could not open the file " << argv[1]
			<< "\nProgram terminating.\n";
		exit(EXIT_FAILURE);
	}

	int count;
	infile >> count;
	infile.get();

	ofstream outfile;
	char * filename = new char[strlen(argv[1]) + 2];
	strcpy(filename, argv[1]);
	strcpy(filename + strlen(argv[1]) - 2, "out");
	outfile.open(filename);

	string word, subword;
	unsigned int pos, len, i;
	int nword, result, cons;

	for (int n = 0; n < count; ++n)
	{
		result = 0;
		infile >> word >> nword;

		for (len = nword; len <= word.size(); ++len)
			for (pos = 0; pos <= word.size() - len; ++pos)
			{
				subword =  word.substr(pos, len);
				cons = 0;
				for (i = 0; i < subword.size(); ++i)
				{
					if (toupper(subword[i]) != 'A' &&
						toupper(subword[i]) != 'E' &&
						toupper(subword[i]) != 'I' &&
						toupper(subword[i]) != 'O' &&
						toupper(subword[i]) != 'U')
					{
						++cons;
						if (cons >= nword)
						{
							++result;
							break;
						}
					}
					else
						cons = 0;
				}
			}

		outfile << "Case #" << n + 1 << ": " << result << endl;
	}

	outfile.close();
	infile.close();

	delete [] filename;

	return EXIT_SUCCESS;
}
