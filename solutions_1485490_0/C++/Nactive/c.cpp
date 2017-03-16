#include <iostream>
#include <fstream>

#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cassert>
#include <algorithm>
#include <iomanip>

using namespace std;


ofstream out;
ifstream in;

void init()
{
	in.open ("C-small-attempt2.in");
	assert(!in.fail());
	out.open("out.txt");
	assert(!out.fail());
}

void close()
{
	in.close();
	out.close();
}

string readLine()
{
	string s;
	getline(in, s);
	return s;
}

int readNumber()
{
	int i;
	in >> i;
	string s;
	getline(in, s);
	return i;
}

char readChar()
{
	char c;
	in >> c;
	string s;
	getline(in, s);
	return c;
}

int main()
{
	init();
	int cases = readNumber();
	
	for (int casenr = 1; casenr <= cases; casenr++)
	{
		std::vector<__int64> toys_aantal;
		std::vector<__int64> toys_type;
		std::vector<__int64> boxs_aantal;
		std::vector<__int64> boxs_type;
		std::vector<__int64> hulp;
		__int64 toystypes, boxstypes;
		in >> boxstypes;
		in >> toystypes;
		for (int i = 0; i < boxstypes; i++)
		{
			__int64 a, b;
			in >> a; in >> b;
			//std:: cout << b << " ";
			boxs_aantal.push_back(a);
			boxs_type.push_back(b);
		}
		hulp.resize(boxs_type.size(), 0);

		for (int i = 0; i < toystypes; i++)
		{
			__int64 a,b;
			in >> a; in >> b;
			toys_aantal.push_back(a);
			toys_type.push_back(b);
		}

		for (int i = 0; i < toys_type.size(); i++)
		{
			__int64 vorige = 0; 
			for (int j = 0; j < boxs_type.size(); j++)
			{
				__int64 links = (j > 0  ? hulp[j - 1] : 0);
				//__int64 boven = (j > 0  ? hulp[j] : 0);

				__int64 temp = hulp[j];
				if (boxs_type[j] == toys_type[i])
				{
					__int64 bij = (boxs_type[j] == toys_type[i] ? std::min(toys_aantal[i], boxs_aantal[j]) : 0);
					if (vorige + bij > std::max(hulp[j], links) )
					{
						hulp[j] = std::max(std::max(hulp[j], links), vorige + bij);
						toys_aantal[i] -= bij;
					} else
					{
						hulp[j] = std::max(std::max(hulp[j], links), vorige + bij);
					}
					
				} else
				{
					hulp[j] = std::max(hulp[j], links);
				}
				
				vorige = temp;
				//std:: cout << hulp[j] << " ";
			}

			//std::cout << std::endl;

		}
		out << "Case #" << casenr << ": " << hulp[boxs_type.size() - 1] << std::endl;
	}

	close();
	std::cout << "Finished (C)" << endl;
	cin.get();
	return 0;
}