#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>


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

	int tx, ty, jump, x, y;
	string result;

	for (int n = 0; n < count; ++n)
	{
		infile >> tx >> ty;
		jump = 1;
		x = y = 0;
		result = "";

		if (abs(tx) < abs(ty))
		{
			while (x != tx)
			{
				if (x > tx)
				{
					if (jump > x - tx)
					{
						x += jump++;
						result += "E";
						x -= jump++;
						result += "W";
					}
					else
					{
						x -= jump++;
						result += "W";
					}
				}
				else
				{
					if (jump > tx - x)
					{
						x -= jump++;
						result += "W";
						x += jump++;
						result += "E";
					}
					else
					{
						x += jump++;
						result += "E";
					}
				}
			}
			while (y != ty)
			{
				if (y > ty)
				{
					if (jump > y - ty)
					{
						y += jump++;
						result += "N";
						y -= jump++;
						result += "S";
					}
					else
					{
						y -= jump++;
						result += "S";
					}
				}
				else
				{
					if (jump > ty - y)
					{
						y -= jump++;
						result += "S";
						y += jump++;
						result += "N";
					}
					else
					{
						y += jump++;
						result += "N";
					}
				}
			}
		}
		else
		{
			while (y != ty)
			{
				if (y > ty)
				{
					if (jump > y - ty)
					{
						y += jump++;
						result += "N";
						y -= jump++;
						result += "S";
					}
					else
					{
						y -= jump++;
						result += "S";
					}
				}
				else
				{
					if (jump > ty - y)
					{
						y -= jump++;
						result += "S";
						y += jump++;
						result += "N";
					}
					else
					{
						y += jump++;
						result += "N";
					}
				}
			}
			while (x != tx)
			{
				if (x > tx)
				{
					if (jump > x - tx)
					{
						x += jump++;
						result += "E";
						x -= jump++;
						result += "W";
					}
					else
					{
						x -= jump++;
						result += "W";
					}
				}
				else
				{
					if (jump > tx - x)
					{
						x -= jump++;
						result += "W";
						x += jump++;
						result += "E";
					}
					else
					{
						x += jump++;
						result += "E";
					}
				}
			}
		}

		outfile << "Case #" << n + 1 << ": " << result << endl;
	}

	outfile.close();
	infile.close();

	delete [] filename;

	return EXIT_SUCCESS;
}
