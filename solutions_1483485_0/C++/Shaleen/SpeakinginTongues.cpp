#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi; 
typedef vector<string> vs;

#define PB push_back
const long double PI = 3.1415926535897932384626433832795;

char letters[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main(int argc, char *argv[])
{
	int num_tc;
	ifstream myfile;
	myfile.open(argv[1]);
	myfile >> num_tc;
	
	char str[150];
	myfile.getline(str, 150); // to read 1 "\n" left in previous line
	for (int i=0; i<num_tc; ++i) {
		myfile.getline(str, 150);
		int sz = strlen(str);
		string res;
		for (int j = 0; j < sz; ++j) {
			if (str[j] == ' ') res += ' ';
			else res += letters[str[j] - 'a'];
		}
		cout << "Case #" << i + 1 << ": " << res << "\n";
	}
	myfile.close();
	return 0;
}
