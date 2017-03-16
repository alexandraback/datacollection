#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector> 

using namespace std;
 
int findmax(int* v, int start, int end) {
	int m = start;
	for(int i = start + 1; i <= end ; i++) {
		if (v[i] > v[m]) m = i;
	}
	
	return m;
}

int gain(int* v, int startp, int endp, int starte, int ende, int e, int r) {
	if (startp == endp)
		return v[startp] * (starte - ende + r);
	if (startp > endp)
		return 0;

	int m = findmax(v, startp, endp);
	int e1 = starte + (m - startp) * r;
	int e2 = ende - (endp - m) * r;

	if(e < e1 && e2 <= r)
		return gain(v, startp, m - 1, starte, e, e, r) + v[m] * e + gain(v, m + 1, endp, r, ende, e, r);
	else if(e >= e1 && e2 <= r)
		return v[m] * e1 + gain(v, m + 1, endp, r, ende, e, r);
	else if(e < e1 && e2 > r)
		return gain(v, startp, m - 1, starte, e, e, r) + v[m] * (e - e2 + r);
	else
		return v[m] * (e1 - e2 + r);
}

int main()
{
	ifstream infile;
	infile.open("B-small.in");
	ofstream outfile;
	outfile.open("B-small.out");

	string line;
	int n1;
	getline(infile, line);
	istringstream stream1;
	stream1.str(line);
	stream1 >> n1;

	int e, r, n;
	
	for (int i = 0; i < n1; i++) {
		istringstream stream;
		getline(infile, line);
		stream.str(line);
		stream >> e >> r >> n;
		
		istringstream stream2;
		getline(infile, line);
		stream2.str(line);
		int v[n];
		for (int j = 0; j < n; j++) {
			stream2 >> v[j];
		}

		int k = gain(v, 0, n - 1, e, r, e, r);
		ostringstream ss;
		ss << "Case #" << (i + 1) << ": " << k << '\n';
		outfile << ss.str(); 
	}
	
	infile.close();
	outfile.close();
  return 0;
}
