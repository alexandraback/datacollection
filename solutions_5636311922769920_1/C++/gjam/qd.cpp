#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string run_test(string line)
{	
	int k, c, s;
	istringstream iss(line);
	iss>>k>>c>>s;

	string retval;
	ostringstream oss(retval);

	int moves = k/c;
	if(k%c) moves++;
	if (moves > s) {
		oss << "IMPOSSIBLE";
		return oss.str();
	}

	int j=0;
	for (int i=0; i<moves; i++)
	{
		long long section_size = pow(k,c-1);
		long long position = 0;
		for (int d = 0; d<c && j<k; d++) {
			position += j*section_size;
			section_size /= k;
			j++;
		}
		oss <<position+1<<" ";
	}

	return oss.str();
}

int main()
{
	string line;
	getline(cin,line);

	auto n_tests = stoi(line);	

	for(int i = 0; i < n_tests; i++) {		
		getline(cin,line);

		cout<<"Case #"<<i+1<<": ";

		auto result = run_test(line);

		cout<<result<<"\n";	
	}
}
