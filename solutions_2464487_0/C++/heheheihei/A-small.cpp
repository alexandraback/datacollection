#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector> 

using namespace std;
 
int main()
{
	ifstream infile;
	infile.open("A-small.in");
	ofstream outfile;
	outfile.open("A-small.out");

	string line;
	int n;
	getline(infile, line);
	istringstream stream1;
	stream1.str(line);
	stream1 >> n;

	int r, t;
	
	for (int i = 0; i < n; i++) {
		istringstream stream;
		getline(infile, line);
		stream.str(line);
		stream >> r >> t;
		cout << r << t << endl;
		
		int k = 0;
		while(1) {
			t = t - ((r+1)*(r+1) - r*r);
			if (t < 0)
				break;
			k++;
			r += 2;
		}
		ostringstream ss;
		ss << "Case #" << (i + 1) << ": " << k << '\n';
		outfile << ss.str(); 
		cout << "hehe" << endl;
	}
	
	infile.close();
	outfile.close();
  return 0;
}
