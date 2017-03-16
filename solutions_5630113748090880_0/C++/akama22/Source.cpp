
#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;


int main() {
	int T = 0;
	long int N = 0;
	map<int, int>  heightcount;
	ifstream infile;
	ofstream outfile;
	string line;
	int n = 0;

	infile.open("D:/GoogleCodeJam/B-small.in");
	outfile.open("D:/GoogleCodeJam/B-smallOut.txt");


	if (infile.is_open())
	{
		bool first = true, second = true;
		while (getline(infile, line))
		{
			
			if (first == true) {
				int intVal = atoi(line.c_str());
				T = intVal;
				first = false;
			} else {

				istringstream iss(line);
				vector<string> tokens;
				copy(istream_iterator<string>(iss),
					istream_iterator<string>(),
					back_inserter(tokens));

				if (tokens.size() == 1) {

					int intVal = atoi(line.c_str());
					N = intVal;

					if (!heightcount.empty()){
						map<int, int>::iterator it = heightcount.begin();

						vector<int> num;
						for (; it != heightcount.end(); it++) {
							if (it->second % 2 != 0) {
								num.push_back(it->first);
							}
						}

						std::sort(num.begin(), num.end());
						outfile << " Case #"<< n<<":";
						for (int i = 0; i < num.size(); i++) {
							outfile << " " << num[i];
						}
						outfile << endl;
						heightcount.clear();
					}
					n++;

				
				}
				else {

					for (int i = 0; i < tokens.size(); i++) {
						int intVal = atoi(tokens[i].c_str());

						map<int, int> ::iterator iter = heightcount.find(intVal);

						if (iter != heightcount.end()){
							iter->second += 1;
						}
						else {
							heightcount.insert(std::pair<int, int>(intVal, 1));

						}

					}

				}			
			}

		}
		infile.close();
	}
	else cout << "Unable to open file";
	if (!heightcount.empty()){
		map<int, int>::iterator it = heightcount.begin();

		vector<int> num;
		for (; it != heightcount.end(); it++) {
			if (it->second % 2 != 0) {
				num.push_back(it->first);
			}
		}

		std::sort(num.begin(), num.end());
		outfile << " Case #" << n << ":";
		for (int i = 0; i < num.size(); i++) {
			outfile << " " << num[i];
		}

		outfile << endl;
		heightcount.clear();
	}															 
	
	infile.close();
	outfile.close();
	_getch();
}