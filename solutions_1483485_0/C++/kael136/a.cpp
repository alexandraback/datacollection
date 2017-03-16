#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string in, out;
	int t;
	t = 1;
	//in = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	//out = in;
	fstream in_f, out_f;
	in_f.open("A-small-attempt3.in", fstream::in);
	out_f.open("proba.out", std::ios_base::binary | std::ios_base::out );

	in_f >> t;
	cout << t << endl;
	for(int i = 0; i <= t; i++)
	{
		getline (in_f,in);
		if (i != 0)
		{
			cout << in;
			out = in;
			for(int j = 0; j < in.size(); j++)
			{
				switch (out[j])
				{
				case 'a':
					out[j] = 'y';
					break;
				case 'b':
					out[j] = 'h';
					break;
				case 'c':
					out[j] = 'e';
					break;
				case 'd':
					out[j] = 's';
					break;
				case 'e':
					out[j] = 'o';
					break;
				case 'f':
					out[j] = 'c';
					break;
				case 'g':
					out[j] = 'v';
					break;
				case 'h':
					out[j] = 'x';
					break;
				case 'i':
					out[j] = 'd';
					break;
				case 'j':
					out[j] = 'u';
					break;
				case 'k':
					out[j] = 'i';
					break;
				case 'l':
					out[j] = 'g';
					break;
				case 'm':
					out[j] = 'l';
					break;
				case 'n':
					out[j] = 'b';
					break;
				case 'o':
					out[j] = 'k';
					break;
				case 'p':
					out[j] = 'r';
					break;
				case 'q':
					out[j] = 'z';
					break;
				case 'r':
					out[j] = 't';
					break;
				case 's':
					out[j] = 'n';
					break;
				case 't':
					out[j] = 'w';
					break;
				case 'u':
					out[j] = 'j';
					break;
				case 'v':
					out[j] = 'p';
					break;
				case 'w':
					out[j] = 'f';
					break;
				case 'x':
					out[j] = 'm';
					break;
				case 'y':
					out[j] = 'a';
					break;
				case 'z':
					out[j] = 'q';
					break;
				default:
					out[j] = in[j];
					break;
				}
			}
			out_f << "Case #" << i << ": " << out << endl;
		}
	}

	cout << out << endl;
	return 0;
}