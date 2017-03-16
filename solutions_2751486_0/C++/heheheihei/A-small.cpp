#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector> 

using namespace std;
 
int cal(int l, int n) {
	if (l < n)
		return 0;
	else
		return (l * (l + 1) / 2 - (2 * l - n + 2) * (n - 1) / 2);
}

int main()
{
	ifstream infile;
	infile.open("A-small.in");
	ofstream outfile;
	outfile.open("A-small.out");

	string line;
	int t;
	getline(infile, line);
	istringstream stream1;
	stream1.str(line);
	stream1 >> t;

	for (int i = 0; i < t; i++) {
		string name;
		int n;
		getline(infile, line);
		istringstream stream;
		stream.str(line);
		stream >> name;
		stream >> n;

		//pre handling
		int l = name.size();
		vector<int> start, end;
		int p_s = -1, p_e = -1, status = 0;
		for (int j = 0; j < l; j++) {
			if (name[j] == 'a' || name[j] == 'e' || name[j] == 'i' || name[j] == 'o' || name[j] == 'u') {
				if (status) {
					p_e = j - 1;
					if (p_e >= (p_s + n - 1)) {
						start.push_back(p_s);
						end.push_back(p_e);
						cout << (i + 1) << ":" << p_s << " " << p_e << " | ";
					}
					status = 0;
				}
			}
			else {
				if (status == 0) {
					p_s = j;
					status = 1;
				}

				if (j == (l - 1)) {
					if (j >= (p_s + n - 1)) {
						start.push_back(p_s);
						end.push_back(j);
						cout << (i + 1) << ":" << p_s << " " << j << " | ";
					}
				}
			}
		}
		cout << endl;

		int sum = cal(l, n), cal_s, cal_e;
		vector<int>::iterator it_s = start.begin(), it_e = end.begin();
		if (start.size() == 1) {
			if (*it_s == 0)
				sum = sum - cal(l - 1 - (*it_e - n + 2) + 1, n);
			else if (*it_e == (l - 1))
				sum = sum - cal(*it_s + n - 2 + 1, n);
			else
				sum = sum - cal(*it_s + n - 2 + 1, n) - cal(l - 1 - (*it_e - n + 2) + 1, n);
		}
		else if (it_s != start.end()) {
			if (*it_s != 0) {
				sum = sum - cal(*it_s + n - 2 + 1, n);
				cal_s = *it_e - n + 2;
			}
			else
				cal_s = *it_e - n + 2;
			while(1) {
				it_s++;
				if (it_s == start.end()) {
					sum = sum - cal(l - 1 - cal_s + 1, n);
					break;
				}
				cal_e = *it_s + n - 2;
				sum = sum - cal(cal_e - cal_s + 1, n);
				it_e++;
				cal_s = *it_e - n + 2;
				
			}
		}
		else
			sum = 0;

		ostringstream ss;
		ss << "Case #" << (i + 1) << ": " << sum << '\n';
		outfile << ss.str(); 
	}
	
	infile.close();
	outfile.close();
  return 0;
}
